#include "VBO.hpp"
#include "GL\glew.h"

VBO::VBO()
{
    id = 0;
    maximum_size = 0;
    current_size = 0;
    dimensions = 0;
    bind_index = 0;
}

void VBO::generateVBOID()
{
    glGenBuffers(1, &id);
    
}

void VBO::destroyVBO()
{
    glDeleteBuffers(1, &id);
}

//gets
unsigned int VBO::getID() const
{
    return id;
}

size_t VBO::getCurrentSize() const
{
    return current_size;
}

size_t VBO::getMaximumSize() const
{
    return maximum_size;
}

size_t VBO::getRemainingSize() const
{
    return maximum_size - current_size;
}

int VBO::getDimensions() const
{
    return dimensions;
}

unsigned int VBO::getBindIndex() const
{
    return bind_index;
}

void VBO::enableVertexIndex() const
{
    glEnableVertexAttribArray(getBindIndex());
}

void VBO::disableVertexIndex() const
{
    glDisableVertexAttribArray(getBindIndex());
}

void VBO::setCurrentSize(size_t byte_size)
{
    current_size = byte_size;
}

//sets
void VBO::setMaximumSize(size_t byte_size)
{
    maximum_size = byte_size;
}

void VBO::setDimensions(int dimension)
{
    dimensions = dimension;
}

void VBO::setBindIndex(unsigned int binding_index)
{
    bind_index = binding_index;
}
