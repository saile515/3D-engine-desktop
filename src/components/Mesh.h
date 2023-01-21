#include <GL/glew.h>
#include <glm/mat4x4.hpp>

#include "../core/Component.h"

class Mesh : public Component
{
public:
    double *vertices;
    double *indices;
    GLuint vertexBuffer;

    Mesh();

    void render();
};