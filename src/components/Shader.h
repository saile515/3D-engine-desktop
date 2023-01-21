#include <type_traits>

#include <GL/glew.h>

#include "../core/Component.h"

struct ShaderAttributes
{
    GLuint vertexPosition;
};

struct ShaderUniforms
{
    GLuint MVPMatrix;
};

struct ProgramInfo
{
    GLuint program;
    ShaderAttributes attributes;
    ShaderUniforms uniforms;
};

class Shader : public Component
{
public:
    ProgramInfo programInfo;
    Shader(const char *vertexPath, const char *fragmentPath);
};