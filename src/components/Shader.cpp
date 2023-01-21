#include "Shader.h"

#include <GL/glew.h>

#include "../utils/loadShader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    programInfo.program = LoadShaders(vertexPath, fragmentPath);

    programInfo.attributes.vertexPosition = glGetAttribLocation(programInfo.program, "vertexPosition");

    programInfo.uniforms.MVPMatrix = glGetUniformLocation(programInfo.program, "MVPMatrix");
}