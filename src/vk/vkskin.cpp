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

static Shader *skinShader, *skinShader_noAT;
static Shader *skinShader_fullLight, *skinShader_fullLight_noAT;
static int32 u_boneMatrices;

void
skinInstanceCB(Geometry *geo, InstanceDataHeader *header, bool32 reinstance)
{
}

void
skinUninstanceCB(Geometry *geo, InstanceDataHeader *header)
{
}

static float skinMatrices[64 * 16];

void
uploadSkinMatrices(Atomic *a)
{
}

void
skinRenderCB(Atomic *atomic, InstanceDataHeader *header)
{
}

static void *
skinOpen(void *o, int32, int32)
{

	return o;
}

static void *
skinClose(void *o, int32, int32)
{
	return o;
}

void
initSkin(void)
{
}

ObjPipeline *
makeSkinPipeline(void)
{
	return nullptr;
}

#else

void
initSkin(void)
{
}

#endif

} // namespace vk
} // namespace rw
