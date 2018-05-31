#include "FloatVBO.hpp"
#include "GL\glew.h"

void FloatVBO::addData(size_t count, const void * data)
{
    glBufferSubData(GL_ARRAY_BUFFER, getCurrentSize(), count, data);
    setCurrentSize(getCurrentSize() + count);
}

void FloatVBO::bindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, getID());
}

void FloatVBO::unbindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, getID());
}

void FloatVBO::createVBO() const
{
    glBufferData(GL_ARRAY_BUFFER, getMaximumSize(), nullptr, GL_STATIC_DRAW);
}

void FloatVBO::vertexPointer()
{
    glVertexAttribPointer(getBindIndex(), getDimensions(), GL_FLOAT, GL_FALSE, 0, nullptr);
}

void FloatVBO::modifyData(size_t start, size_t count, const void* data) const
{
    glBufferSubData(GL_ARRAY_BUFFER, start, count, data);
}
