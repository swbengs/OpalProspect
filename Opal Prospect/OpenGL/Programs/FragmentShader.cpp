#include "FragmentShader.hpp"
#include "GL\glew.h"

void FragmentShader::createShaderID()
{
    setID(glCreateShader(GL_FRAGMENT_SHADER));
}
