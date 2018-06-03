#include "VertexUVIndexVAO.hpp"

#include <iostream>

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

void VertexUVIndexVAO::bind() const
{
    vao.bindVAO();
}

void VertexUVIndexVAO::unBind() const
{
    vao.unbindVAO();
}

void VertexUVIndexVAO::bindVertex() const
{
    vertex.bindVBO();
}

void VertexUVIndexVAO::bindUV() const
{
    uv.bindVBO();
}

void VertexUVIndexVAO::bindIndex() const
{
    index.bindVBO();
}

void VertexUVIndexVAO::bufferVertex(size_t start, const std::vector<float> &vector)
{
    vertex.modifyData(start*object_vertex_size, vector.size(), vector.data());
}

void VertexUVIndexVAO::bufferUV(size_t start, const std::vector<float> &vector)
{
    uv.modifyData(start*object_uv_size, vector.size(), vector.data());
}

void VertexUVIndexVAO::bufferIndex(size_t start, const std::vector<unsigned int> &vector)
{
    index.modifyData(start*object_index_size, vector.size(), vector.data());
}

void VertexUVIndexVAO::create()
{
    //ensure nothing else is bound and being modified
    vao.unbindVAO();
    vertex.unbindVBO(); //only one call is needed since vertex, uv, and normals all share the same binding spot
    index.unbindVBO();

    vao.createVAO();
    vao.bindVAO();

    vertex.generateVBOID();
    vertex.bindVBO();
    vertex.setMaximumSize(object_count*object_vertex_size*sizeof(float));
    vertex.setDimensions(4);
    vertex.setBindIndex(0);

    vertex.createVBO();
    vertex.enableVertexIndex();
    vertex.vertexPointer();

    uv.generateVBOID();
    uv.bindVBO();
    uv.setMaximumSize(object_count*object_uv_size*sizeof(float));
    uv.setDimensions(3);
    uv.setBindIndex(1);

    uv.createVBO();
    uv.enableVertexIndex();
    uv.vertexPointer();

    index.generateVBOID();
    index.bindVBO();
    index.setMaximumSize(object_count*object_index_size*sizeof(int));

    index.createVBO();
    //dont need to assign how to access the data. therefore no enable index or vertex pointer needed for index data

    vao.unbindVAO(); //ensure this wont be modified elsewhere
}

void VertexUVIndexVAO::destroy()
{
    vertex.destroyVBO();
    uv.destroyVBO();
    index.destroyVBO();
    vao.destroyVAO();
}

//gets
unsigned int VertexUVIndexVAO::getID() const
{
    return vao.getID();
}

int VertexUVIndexVAO::getObjectCount() const
{
    return object_count;
}

int VertexUVIndexVAO::getObjectVertexSize() const
{
    return object_vertex_size;
}

int VertexUVIndexVAO::getObjectUVSize() const
{
    return object_uv_size;
}

int VertexUVIndexVAO::getObjectIndexSize() const
{
    return object_index_size;
}

//sets
void VertexUVIndexVAO::setObjectCount(int count)
{
    object_count = count;
}

void VertexUVIndexVAO::setObjectVertexSize(int size)
{
    object_vertex_size = size;
}

void VertexUVIndexVAO::setObjectUVSize(int size)
{
    object_uv_size = size;
}

void VertexUVIndexVAO::setObjectIndexSize(int size)
{
    object_index_size = size;
}
