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

#include "rwvkimpl.h"

namespace rw
{
namespace vk
{

// TODO: make some of these things platform-independent

static void *
driverOpen(void *o, int32, int32)
{
	return o;
}

static void *
driverClose(void *o, int32, int32)
{
	return o;
}

void
registerPlatformPlugins(void)
{
}

} // namespace vk
} // namespace rw
