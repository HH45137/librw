#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../rwbase.h"
#include "../rwengine.h"
#include "../rwerror.h"
#include "../rwobjects.h"
#include "../rwpipeline.h"
#include "../rwplg.h"

#include "rwvk.h"
#include "rwvkshader.h"

namespace rw
{
namespace vk
{

// TODO: make some of these things platform-independent

#ifdef RW_VULKAN

void
freeInstanceData(Geometry *geometry)
{
}

void *
destroyNativeData(void *object, int32, int32)
{
	return nullptr;
}

static InstanceDataHeader *
instanceMesh(rw::ObjPipeline *rwpipe, Geometry *geo)
{
	return nullptr;
}
static void
instance(rw::ObjPipeline *rwpipe, Atomic *atomic)
{
}

static void
uninstance(rw::ObjPipeline *rwpipe, Atomic *atomic)
{
}

static void
render(rw::ObjPipeline *rwpipe, Atomic *atomic)
{
}

void
ObjPipeline::init(void)
{
}

ObjPipeline *
ObjPipeline::create(void)
{
	return nullptr;
}

void
defaultInstanceCB(Geometry *geo, InstanceDataHeader *header, bool32 reinstance)
{
}

void
defaultUninstanceCB(Geometry *geo, InstanceDataHeader *header)
{
}

ObjPipeline *
makeDefaultPipeline(void)
{
	return nullptr;
}

#else
void *
destroyNativeData(void *object, int32, int32)
{
	return object;
}
#endif

} // namespace vk
} // namespace rw
