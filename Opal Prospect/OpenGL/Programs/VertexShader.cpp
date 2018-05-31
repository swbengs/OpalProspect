#include "VertexShader.hpp"
#include "GL\glew.h"

void VertexShader::createShaderID()
{
    setID(glCreateShader(GL_VERTEX_SHADER));
}
