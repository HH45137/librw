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
#include "rwvkshader.h"

#include "rwvkimpl.h"

namespace rw
{
namespace vk
{

void
drawInst_simple(InstanceDataHeader *header, InstanceData *inst)
{
}

// Emulate PS2 GS alpha test FB_ONLY case: failed alpha writes to frame- but not to depth buffer
void
drawInst_GSemu(InstanceDataHeader *header, InstanceData *inst)
{
}

void
drawInst(InstanceDataHeader *header, InstanceData *inst)
{
}

void
setAttribPointers(AttribDesc *attribDescs, int32 numAttribs)
{
}

void
disableAttribPointers(AttribDesc *attribDescs, int32 numAttribs)
{
}

void
setupVertexInput(InstanceDataHeader *header)
{
}

void
teardownVertexInput(InstanceDataHeader *header)
{
}

int32
lightingCB(Atomic *atomic)
{
	return 0;
}

void
defaultRenderCB(Atomic *atomic, InstanceDataHeader *header)
{
}

} // namespace vk
} // namespace rw

#endif
