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
#ifdef RW_VULKAN
#include "rwvk.h"
#include "rwvkshader.h"

namespace rw
{
namespace vk
{
static char *
shader_strdup(const char *name)
{
	return nullptr;
}

int32
registerUniform(const char *name, UniformType type, int32 num)
{
	return 0;
}

int32
findUniform(const char *name)
{
	return 0;
}

int32
registerBlock(const char *name)
{
	return 0;
}

int32
findBlock(const char *name)
{
	return 0;
}

void
setUniform(int32 id, void *data)
{
}

void
flushUniforms(void)
{
}

static void
printShaderSource(const char **src)
{
}

static int
compileshader(GLenum type, const char **src, GLuint *shader)
{
	return 0;
}

static int
linkprogram(GLint vs, GLint fs, GLuint *program)
{
	return 0;
}

Shader *
Shader::create(const char **vsrc, const char **fsrc)
{
	return nullptr;
}

void
Shader::use(void)
{
}

void
Shader::destroy(void)
{
}

} // namespace vk
} // namespace rw

#endif
