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
#include "../rwrender.h"
#ifdef RW_VULKAN

#include "rwvk.h"
#include "rwvkimpl.h"
#include "rwvkshader.h"

#define PLUGIN_ID 0

namespace rw
{
namespace vk
{

/*
 * GL state cache
 */

void
setGlRenderState(uint32 state, uint32 value)
{
}

void
flushGlRenderState(void)
{
}

void
setAlphaBlend(bool32 enable)
{
}

bool32
getAlphaBlend(void)
{
	return 0;
}

bool32
getAlphaTest(void)
{
	return 0;
}

static void
setDepthTest(bool32 enable)
{
}

static void
setDepthWrite(bool32 enable)
{
}

static void
setAlphaTest(bool32 enable)
{
}

static void
setAlphaTestFunction(uint32 function)
{
}

static void
setVertexAlpha(bool32 enable)
{
}

static void
setActiveTexture(int32 n)
{
}

uint32
bindTexture(uint32 texid)
{
	return 0;
}

void
bindFramebuffer(uint32 fbo)
{
}

static void
setFilterMode(uint32 stage, int32 filter, int32 maxAniso = 1)
{
}

static void
setAddressU(uint32 stage, int32 addressing)
{
}

static void
setAddressV(uint32 stage, int32 addressing)
{
}

static void
setRasterStageOnly(uint32 stage, Raster *raster)
{
}

static void
setRasterStage(uint32 stage, Raster *raster)
{
}

void
evictRaster(Raster *raster)
{
}

void
setTexture(int32 stage, Texture *tex)
{
}

static void
setRenderState(int32 state, void *pvalue)
{
}

static void *
getRenderState(int32 state)
{
	return nullptr;
}

static void
resetRenderState(void)
{
}

void
setWorldMatrix(Matrix *mat)
{
}

int32
setLights(WorldLights *lightData)
{
	return 0;
}

void
setProjectionMatrix(float32 *mat)
{
}

void
setViewMatrix(float32 *mat)
{
}

void
setMaterial(const RGBA &color, const SurfaceProperties &surfaceprops, float extraSurfProp)
{
}

void
flushCache(void)
{
}

static void
setFrameBuffer(Camera *cam)
{
}

static Rect
getFramebufferRect(Raster *frameBuffer)
{
	Rect r;
	return r;
}

static void
setViewport(Raster *frameBuffer)
{
}

static void
beginUpdate(Camera *cam)
{
}

static void
endUpdate(Camera *cam)
{
}

static void
clearCamera(Camera *cam, RGBA *col, uint32 mode)
{
}

static void
showRaster(Raster *raster, uint32 flags)
{
}

static bool32
rasterRenderFast(Raster *raster, int32 x, int32 y)
{
	return 0;
}

static void
addVideoMode(const GLFWvidmode *mode)
{
}

static void
makeVideoModeList(void)
{
}

#endif

} // namespace vk
} // namespace rw
