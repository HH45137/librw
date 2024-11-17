#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../rwanim.h"
#include "../rwbase.h"
#include "../rwengine.h"
#include "../rwerror.h"
#include "../rwobjects.h"
#include "../rwpipeline.h"
#include "../rwplg.h"
#include "../rwplugins.h"
#include "../rwrender.h"

#include "rwvk.h"
#include "rwvkplg.h"
#include "rwvkshader.h"

#include "rwvkimpl.h"

namespace rw
{
namespace vk
{

#ifdef RW_VULKAN

static Shader *envShader, *envShader_noAT;
static Shader *envShader_fullLight, *envShader_fullLight_noAT;
static int32 u_texMatrix;
static int32 u_fxparams;
static int32 u_colorClamp;
static int32 u_envColor;

void
matfxDefaultRender(InstanceDataHeader *header, InstanceData *inst, int32 vsBits, uint32 flags)
{
}

static Frame *lastEnvFrame;

static RawMatrix normal2texcoord = {{0.5f, 0.0f, 0.0f}, 0.0f, {0.0f, -0.5f, 0.0f}, 0.0f, {0.0f, 0.0f, 1.0f}, 0.0f, {0.5f, 0.5f, 0.0f}, 1.0f};

void
uploadEnvMatrix(Frame *frame)
{
}

void
matfxEnvRender(InstanceDataHeader *header, InstanceData *inst, int32 vsBits, uint32 flags, MatFX::Env *env)
{
}

void
matfxRenderCB(Atomic *atomic, InstanceDataHeader *header)
{
}

ObjPipeline *
makeMatFXPipeline(void)
{
	return nullptr;
}

static void *
matfxOpen(void *o, int32, int32)
{
	return nullptr;
}

static void *
matfxClose(void *o, int32, int32)
{
	return nullptr;
}

void
initMatFX(void)
{
}

#else

void
initMatFX(void)
{
}

#endif

} // namespace vk
} // namespace rw
