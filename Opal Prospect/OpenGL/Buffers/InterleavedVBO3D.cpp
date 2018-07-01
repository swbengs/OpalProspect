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

InterleavedVBO3D::InterleavedVBO3D()
{
    id = 0;
    maximum_size = 0;
    current_size = 0;
}

void InterleavedVBO3D::bindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, getID());
}

void InterleavedVBO3D::unbindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InterleavedVBO3D::addData(const std::vector<float>& data)
{
    addData(data.size(), data.data());
}

void InterleavedVBO3D::modifyData(size_t start, const std::vector<float>& data)
{
    modifyData(start, data.size(), data.data());
}

void InterleavedVBO3D::generateVBOID()
{
    glGenBuffers(1, &id);
}

void InterleavedVBO3D::createVBO() const
{
    glBufferData(GL_ARRAY_BUFFER, getMaximumSize(), nullptr, GL_STATIC_DRAW); //nullptr since we are not uploading when we create the buffer
}

void InterleavedVBO3D::destroyVBO()
{
    glDeleteBuffers(1, &id);
}

void InterleavedVBO3D::vertexPointerSetup() const
{
    const int stride = (vertex_dimensions + uv_dimensions + normal_dimensions) * sizeof(float);
    glVertexAttribPointer(vertex_bind, vertex_dimensions, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glVertexAttribPointer(uv_bind, uv_dimensions, GL_FLOAT, GL_FALSE, stride, (void*)(vertex_dimensions * sizeof(float)));
    //glVertexAttribPointer(normal_bind, normal_dimmensions, GL_FLOAT, GL_FALSE, stride, (void*)((vertex_dimensions + uv_dimensions) * sizeof(float)); leave disabled until shader uses normals
}

void InterleavedVBO3D::enableVertexIndex() const
{
    glEnableVertexAttribArray(vertex_bind);
    glEnableVertexAttribArray(uv_bind);
    //glEnableVertexAttribArray(normal_bind); leave disabled until shader uses normals
}

void InterleavedVBO3D::disableVertexIndex() const
{
    glDisableVertexAttribArray(vertex_bind);
    glDisableVertexAttribArray(uv_bind);
    //glDisableVertexAttribArray(normal_bind); leave disabled until shader uses normals
}

unsigned int InterleavedVBO3D::getID() const
{
    return id;
}

size_t InterleavedVBO3D::getCurrentSize() const
{
    return current_size;
}

size_t InterleavedVBO3D::getMaximumSize() const
{
    return maximum_size;
}

size_t InterleavedVBO3D::getRemainingSize() const
{
    return maximum_size - current_size;
}

void InterleavedVBO3D::setCurrentSize(size_t byte_size)
{
    current_size = byte_size;
}

void InterleavedVBO3D::setMaximumSize(size_t byte_size)
{
    maximum_size = byte_size;
}

//private
void InterleavedVBO3D::addData(size_t count, const void * data)
{
    const size_t size = count * sizeof(float);
    glBufferSubData(GL_ARRAY_BUFFER, getCurrentSize(), size, data);
    setCurrentSize(getCurrentSize() + size);
}

void InterleavedVBO3D::modifyData(size_t start, size_t count, const void * data)
{
    glBufferSubData(GL_ARRAY_BUFFER, start, count * sizeof(float), data);
}
