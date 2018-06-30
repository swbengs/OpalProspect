//class header
#include "InterleavedVBO3D.hpp"

//std lib includes

//other includes
#include "glew.h"

/*
MIT License

Copyright (c) 2018 Scott Bengs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

InterleavedVBO::InterleavedVBO()
{
    id = 0;
    maximum_size = 0;
    current_size = 0;
}

void InterleavedVBO::bindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, getID());
}

void InterleavedVBO::unbindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InterleavedVBO::addData(size_t count, const void *data)
{

}

void InterleavedVBO::modifyData(size_t start, size_t count, const void *data)
{

}

void InterleavedVBO::generateVBOID()
{
    glGenBuffers(1, &id);
}

void InterleavedVBO::createVBO() const
{

}

void InterleavedVBO::destroyVBO()
{
    glDeleteBuffers(1, &id);
}

void InterleavedVBO::vertexPointerSetup() const
{
    //glVertexAttribPointer(vertex_bind, vertex_dimmensions, GL_FLOAT, GL_FALSE, stride, offset);
    //glVertexAttribPointer(uv_bind, uv_dimmensions, GL_FLOAT, GL_FALSE, stride, offset);
    //glVertexAttribPointer(normal_bind, normal_dimmensions, GL_FLOAT, GL_FALSE, stride, offset);
}

void InterleavedVBO::enableVertexIndex() const
{
    glEnableVertexAttribArray(vertex_bind);
    glEnableVertexAttribArray(uv_bind);
    glEnableVertexAttribArray(normal_bind);
}

void InterleavedVBO::disableVertexIndex() const
{
    glDisableVertexAttribArray(vertex_bind);
    glDisableVertexAttribArray(uv_bind);
    glDisableVertexAttribArray(normal_bind);
}

unsigned int InterleavedVBO::getID() const
{
    return id;
}

size_t InterleavedVBO::getCurrentSize() const
{
    return current_size;
}

size_t InterleavedVBO::getMaximumSize() const
{
    return maximum_size;
}

size_t InterleavedVBO::getRemainingSize() const
{
    return maximum_size - current_size;
}

void InterleavedVBO::setCurrentSize(size_t byte_size)
{
    current_size = byte_size;
}

void InterleavedVBO::setMaximumSize(size_t byte_size)
{
    maximum_size = byte_size;
}
