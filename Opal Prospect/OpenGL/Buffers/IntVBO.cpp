#include "IntVBO.hpp"

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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
