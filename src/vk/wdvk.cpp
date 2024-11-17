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
#include "rwwdvk.h"

#ifdef RW_VULKAN
// #include "glad/glad.h"
#endif

#define PLUGIN_ID 2

namespace rw
{
namespace wdvk
{

static void *
driverOpen(void *o, int32, int32)
{
	return o;
}

static void *
driverClose(void *o, int32, int32)
{
	return nullptr;
}

void
registerPlatformPlugins(void)
{
}

#ifdef RW_VULKAN
void
uploadGeo(Geometry *geo)
{
}

void
setAttribPointers(InstanceDataHeader *inst)
{
}

#endif

void
packattrib(uint8 *dst, float32 *src, AttribDesc *a, float32 scale = 1.0f)
{
}

void
unpackattrib(float *dst, uint8 *src, AttribDesc *a, float32 scale = 1.0f)
{
}

void *
destroyNativeData(void *object, int32, int32)
{
	return nullptr;
}

Stream *
readNativeData(Stream *stream, int32, void *object, int32, int32)
{
	return stream;
}

Stream *
writeNativeData(Stream *stream, int32, void *object, int32, int32)
{
	return stream;
}

int32
getSizeNativeData(void *object, int32, int32)
{
	return 0;
}

void
registerNativeDataPlugin(void)
{
}

void
printPipeinfo(Atomic *a)
{
}

static void
instance(rw::ObjPipeline *rwpipe, Atomic *atomic)
{
}

static void
uninstance(rw::ObjPipeline *rwpipe, Atomic *atomic)
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

ObjPipeline *
makeDefaultPipeline(void)
{
	ObjPipeline *pipe = ObjPipeline::create();
	return pipe;
}

// Skin

Stream *
readNativeSkin(Stream *stream, int32, void *object, int32 offset)
{
	return nullptr;
}

Stream *
writeNativeSkin(Stream *stream, int32 len, void *object, int32 offset)
{
	return nullptr;
}

int32
getSizeNativeSkin(void *object, int32 offset)
{
	return 0;
}

uint32
skinInstanceCB(Geometry *g, int32 i, uint32 offset)
{
	return 0;
}

void
skinUninstanceCB(Geometry *geo)
{
}

// Skin

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

// MatFX

static void *
matfxOpen(void *o, int32, int32)
{
	return o;
}

static void *
matfxClose(void *o, int32, int32)
{
	return o;
}

void
initMatFX(void)
{
}

ObjPipeline *
makeMatFXPipeline(void)
{
}

// Raster

int32 nativeRasterOffset;

#ifdef RW_VULKAN
struct GlRaster {
	void *id;
};

static void *
createNativeRaster(void *object, int32 offset, int32)
{
}

static void *
destroyNativeRaster(void *object, int32 offset, int32)
{
	// TODO:
	return object;
}

static void *
copyNativeRaster(void *dst, void *, int32 offset, int32)
{
}

void
registerNativeRaster(void)
{
}

void
Texture::upload(void)
{
}

void
Texture::bind(int n)
{
}

#endif

} // namespace wdvk
} // namespace rw
