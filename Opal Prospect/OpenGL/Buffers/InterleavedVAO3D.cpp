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
    maximum_vertex_size = 0;
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
    main.addData(vector);
}

void InterleavedVAO3D::bufferIndex(const std::vector<unsigned int>& vector)
{
    index.addData(vector.size() * sizeof(unsigned int), vector.data());
}

void InterleavedVAO3D::create()
{
    //ensure nothing else is bound and being modified
    vao.unbindVAO();
    main.unbindVBO(); //only one call is needed since vertex, uv, and normals all share the same binding spot
    index.unbindVBO();

    vao.createVAO();
    vao.bindVAO();

    main.generateVBOID();
    main.bindVBO();
    main.setMaximumSize(getMaximumVertexSize());

    main.createVBO();
    main.enableVertexIndex();
    main.vertexPointerSetup();

    index.generateVBOID();
    index.bindVBO();
    index.setMaximumSize(getMaximumIndexSize());

    index.createVBO();
    //dont need to assign how to access the data. therefore no enable index or vertex pointer needed for index data

    vao.unbindVAO(); //ensure this wont be modified elsewhere
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

size_t InterleavedVAO3D::getMaximumVertexSize() const
{
    return maximum_vertex_size;
}

size_t InterleavedVAO3D::getRemainingVertexSize() const
{
    return main.getRemainingSize();
}

size_t InterleavedVAO3D::getMaximumIndexSize() const
{
    return maximum_index_size;
}

size_t InterleavedVAO3D::getRemainingIndexSize() const
{
    return index.getRemainingSize();
}

unsigned int InterleavedVAO3D::getIndexOffset() const
{
    return index_offset;
}

void InterleavedVAO3D::setMaximumVertexSize(size_t size)
{
    maximum_vertex_size = size;
}

void InterleavedVAO3D::setMaximumIndexSize(size_t size)
{
    maximum_index_size = size;
}

void InterleavedVAO3D::setIndexOffset(unsigned int offset)
{
    index_offset = offset;
}

