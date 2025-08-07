#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../rwbase.h"
#include "../rwerror.h"
#include "../rwplg.h"
#include "../rwrender.h"
#include "../rwengine.h"
#include "../rwpipeline.h"
#include "../rwobjects.h"
#include "../rwanim.h"
#include "../rwplugins.h"

#include "rwgl1.h"

#include "rwgl1plg.h"

#include "rwgl1impl.h"

namespace rw {
namespace gl1 {

#ifdef RW_OPENGL1

void
matfxDefaultRender(InstanceDataHeader *header, InstanceData *inst, int32 vsBits, uint32 flags)
{
	Material *m;
	m = inst->material;

	setMaterial(flags, m->color, m->surfaceProps);

	setTexture(0, m->texture);

	rw::SetRenderState(VERTEXALPHA, inst->vertexAlpha || m->color.alpha != 0xFF);

	if((vsBits & VSLIGHT_MASK) == 0){
		if(getAlphaTest()) {
		} else {
		}
	}else{
		if(getAlphaTest()) {
		} else {
		}
	}

	drawInst(header, inst);
}

static Frame *lastEnvFrame;

static RawMatrix normal2texcoord = {
	{ 0.5f,  0.0f, 0.0f }, 0.0f,
	{ 0.0f, -0.5f, 0.0f }, 0.0f,
	{ 0.0f,  0.0f, 1.0f }, 0.0f,
	{ 0.5f,  0.5f, 0.0f }, 1.0f
};

void
uploadEnvMatrix(Frame *frame)
{
	Matrix invMat;
	if(frame == nil)
		frame = engine->currentCamera->getFrame();

	// cache the matrix across multiple meshes
	static RawMatrix envMtx;
// can't do it, frame matrix may change
//	if(frame != lastEnvFrame){
//		lastEnvFrame = frame;
	{

		RawMatrix invMtx;
		Matrix::invert(&invMat, frame->getLTM());
		convMatrix(&invMtx, &invMat);
		invMtx.pos.set(0.0f, 0.0f, 0.0f);
		float uscale = fabs(normal2texcoord.right.x);
		normal2texcoord.right.x = MatFX::envMapFlipU ? -uscale : uscale;
		RawMatrix::mult(&envMtx, &invMtx, &normal2texcoord);
	}
	//setUniform(u_texMatrix, &envMtx);
}

void
matfxEnvRender(InstanceDataHeader *header, InstanceData *inst, int32 vsBits, uint32 flags, MatFX::Env *env)
{
	Material *m;
	m = inst->material;

	if(env->tex == nil || env->coefficient == 0.0f){
		matfxDefaultRender(header, inst, vsBits, flags);
		return;
	}

	setTexture(0, m->texture);
	setTexture(1, env->tex);
	uploadEnvMatrix(env->frame);

	setMaterial(flags, m->color, m->surfaceProps);

	rw::SetRenderState(VERTEXALPHA, 1);
	rw::SetRenderState(SRCBLEND, BLENDONE);

	drawInst(header, inst);

	rw::SetRenderState(SRCBLEND, BLENDSRCALPHA);
}

void
matfxRenderCB(Atomic *atomic, InstanceDataHeader *header)
{
	uint32 flags = atomic->geometry->flags;
	setWorldMatrix(atomic->getFrame()->getLTM());
	int32 vsBits = lightingCB(atomic);

	setupVertexInput(header);

	lastEnvFrame = nil;

	InstanceData *inst = header->inst;
	int32 n = header->numMeshes;

	while(n--){
		MatFX *matfx = MatFX::get(inst->material);

		if(matfx == nil)
			matfxDefaultRender(header, inst, vsBits, flags);
		else switch(matfx->type){
		case MatFX::ENVMAP:
			matfxEnvRender(header, inst, vsBits, flags, &matfx->fx[0].env);
			break;
		default:
			matfxDefaultRender(header, inst, vsBits, flags);
			break;
		}
		inst++;
	}
	teardownVertexInput(header);
}

ObjPipeline*
makeMatFXPipeline(void)
{
	ObjPipeline *pipe = ObjPipeline::create();
	pipe->instanceCB = defaultInstanceCB;
	pipe->uninstanceCB = defaultUninstanceCB;
	pipe->renderCB = matfxRenderCB;
	pipe->pluginID = ID_MATFX;
	pipe->pluginData = 0;
	return pipe;
}

static void*
matfxOpen(void *o, int32, int32)
{
	matFXGlobals.pipelines[PLATFORM_GL1] = makeMatFXPipeline();

	return o;
}

static void*
matfxClose(void *o, int32, int32)
{
	((ObjPipeline*)matFXGlobals.pipelines[PLATFORM_GL1])->destroy();
	matFXGlobals.pipelines[PLATFORM_GL1] = nil;

	return o;
}

void
initMatFX(void)
{
	Driver::registerPlugin(PLATFORM_GL1, 0, ID_MATFX,
	                       matfxOpen, matfxClose);
}

#else

void initMatFX(void) { }

#endif

}
}

