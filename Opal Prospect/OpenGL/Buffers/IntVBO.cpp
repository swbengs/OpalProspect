#include "IntVBO.hpp"
#include "GL\glew.h"

void IntVBO::addData(size_t count, const void * data)
{
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, getCurrentSize(), count, data);
    setCurrentSize(getCurrentSize() + count);
}

void IntVBO::bindVBO() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getID());
}

void IntVBO::unbindVBO() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getID());
}

void IntVBO::createVBO() const
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, getMaximumSize(), nullptr, GL_STATIC_DRAW);
}

void IntVBO::vertexPointer()
{
    //this command doesn't work on element array buffers
    //glVertexAttribPointer(getIndex(), getDimensions(), GL_INT, GL_FALSE, 0, NULL);
}

void IntVBO::modifyData(size_t start, size_t count, const void* data) const
{
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, start, count, data);
}
