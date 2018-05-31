#include "GeometryShader.hpp"
#include "GL\glew.h"

void GeometryShader::createShaderID()
{
    setID(glCreateShader(GL_GEOMETRY_SHADER));
}
