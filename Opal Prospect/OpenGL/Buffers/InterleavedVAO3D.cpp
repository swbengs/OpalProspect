//class header
#include "InterleavedVAO3D.hpp"

//std lib includes

//other includes

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

InterleavedVAO3D::InterleavedVAO3D()
{
    maximum_size = 0;
    index_offset = 0;
}

void InterleavedVAO3D::bindVAO() const
{
    vao.bindVAO();
}

void InterleavedVAO3D::unBindVAO() const
{
    vao.unbindVAO();
}

void InterleavedVAO3D::bindMainVBO() const
{
    main.bindVBO();
}

void InterleavedVAO3D::bindIndexVBO() const
{
    index.bindVBO();
}

void InterleavedVAO3D::bufferMainVBO(const std::vector<float>& vector)
{

}

void InterleavedVAO3D::create()
{

}

void InterleavedVAO3D::destroy()
{
    main.destroyVBO();
    index.destroyVBO();
    vao.destroyVAO();
}

unsigned int InterleavedVAO3D::getID() const
{
    return vao.getID();
}

size_t InterleavedVAO3D::getMaximumSize() const
{
    return maximum_size;
}

size_t InterleavedVAO3D::getRemainingSize() const
{
    return size_t();
}

unsigned int InterleavedVAO3D::getRemainingIndexSize() const
{
    return 0;
}

unsigned int InterleavedVAO3D::getIndexOffset() const
{
    return 0;
}

void InterleavedVAO3D::setMaximumSize(size_t size)
{
    maximum_size = size;
}

void InterleavedVAO3D::setIndexOffset(unsigned int offset)
{
    index_offset = offset;
}

