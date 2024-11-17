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
#include "rwvkimpl.h"
#include "rwvkshader.h"

#define PLUGIN_ID ID_DRIVER

namespace rw
{
namespace vk
{

int32 nativeRasterOffset;

static uint32
getLevelSize(Raster *raster, int32 level)
{
	return 0;
}

#ifdef RW_VULKAN

static Raster *
rasterCreateTexture(Raster *raster)
{
	return nullptr;
}

static Raster *
rasterCreateCameraTexture(Raster *raster)
{
	return nullptr;
}

static Raster *
rasterCreateCamera(Raster *raster)
{
	return nullptr;
}

static Raster *
rasterCreateZbuffer(Raster *raster)
{
	return nullptr;
}

#endif

void
allocateDXT(Raster *raster, int32 dxt, int32 numLevels, bool32 hasAlpha)
{
}

Raster *
rasterCreate(Raster *raster)
{
	return nullptr;
}

uint8 *
rasterLock(Raster *raster, int32 level, int32 lockMode)
{
	return nullptr;
}

void
rasterUnlock(Raster *raster, int32 level)
{
}

int32
rasterNumLevels(Raster *raster)
{
	return 0;
}

// Almost the same as d3d9 and ps2 function
bool32
imageFindRasterFormat(Image *img, int32 type, int32 *pWidth, int32 *pHeight, int32 *pDepth, int32 *pFormat)
{
	return 0;
}

bool32
rasterFromImage(Raster *raster, Image *image)
{
	return 0;
}

Image *
rasterToImage(Raster *raster)
{
	return nullptr;
}

static void *
createNativeRaster(void *object, int32 offset, int32)
{
	return nullptr;
}

void
evictRaster(Raster *raster);

static void *
destroyNativeRaster(void *object, int32 offset, int32)
{
	return nullptr;
}

static void *
copyNativeRaster(void *dst, void *, int32 offset, int32)
{
	return nullptr;
}

Texture *
readNativeTexture(Stream *stream)
{
	return nullptr;
}

void
writeNativeTexture(Texture *tex, Stream *stream)
{
}

uint32
getSizeNativeTexture(Texture *tex)
{
	return 0;
}

void
registerNativeRaster(void)
{
}

} // namespace vk
} // namespace rw
