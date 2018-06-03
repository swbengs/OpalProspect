#include "VBO.hpp"

#include "GL\glew.h"

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
