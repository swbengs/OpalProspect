#include <iostream>

#include "VertexColorIndexVAO.hpp"

void VertexColorIndexVAO::bind() const
{
    vao.bindVAO();
}

void VertexColorIndexVAO::unBind() const
{
    vao.unbindVAO();
}

void VertexColorIndexVAO::bindVertex() const
{
    vertex.bindVBO();
}

void VertexColorIndexVAO::bindColor() const
{
    color.bindVBO();
}

void VertexColorIndexVAO::bindIndex() const
{
    index.bindVBO();
}

void VertexColorIndexVAO::bufferVertex(int start, const std::vector<float> &vector)
{
    bufferVertex(start, vector.size(), vector.data());
}

void VertexColorIndexVAO::bufferVertex(int start, int count, const float* data)
{
    vertex.modifyData(start*object_vertex_size, count, data);
}

void VertexColorIndexVAO::bufferColor(int start, const std::vector<float> &vector)
{
    bufferColor(start, vector.size(), vector.data());
}

void VertexColorIndexVAO::bufferColor(int start, int count, const float* data)
{
    color.modifyData(start*object_color_size, count, data);
}

void VertexColorIndexVAO::bufferIndex(int start, const std::vector<int> &vector)
{
    bufferIndex(start, vector.size(), vector.data());
}

void VertexColorIndexVAO::bufferIndex(int start, int count, const int* data)
{
    index.modifyData(start*object_index_size, count, data);
}

void VertexColorIndexVAO::create()
{
    //ensure nothing else is bound and being modified
    vao.unbindVAO();
    vertex.unbindVBO(); //only one call is needed since vertex, uv, and normals all share the same binding spot
    index.unbindVBO();

    vao.createVAO();
    vao.bindVAO();

    vertex.generateVBOID();
    vertex.bindVBO();
    vertex.setMaximumSize(object_count*object_vertex_size * sizeof(float));
    vertex.setDimensions(4);
    vertex.setBindIndex(0);

    vertex.createVBO();
    vertex.enableVertexIndex();
    vertex.vertexPointer();

    color.generateVBOID();
    color.bindVBO();
    color.setMaximumSize(object_count*object_color_size * sizeof(float));
    color.setDimensions(3);
    color.setBindIndex(1);

    color.createVBO();
    color.enableVertexIndex();
    color.vertexPointer();

    index.generateVBOID();
    index.bindVBO();
    index.setMaximumSize(object_count*object_index_size * sizeof(int));

    index.createVBO();
    //dont need to assign how to access the data. therefore no enable index or vertex pointer needed for index data

    vao.unbindVAO(); //ensure this wont be modified elsewhere
}

void VertexColorIndexVAO::destroy()
{
    vertex.destroyVBO();
    color.destroyVBO();
    index.destroyVBO();
    vao.destroyVAO();
}

//gets
int VertexColorIndexVAO::getObjectCount() const
{
    return object_count;
}

int VertexColorIndexVAO::getObjectVertexSize() const
{
    return object_vertex_size;
}

int VertexColorIndexVAO::getObjectColorSize() const
{
    return object_color_size;
}

int VertexColorIndexVAO::getObjectIndexSize() const
{
    return object_index_size;
}

//sets
void VertexColorIndexVAO::setObjectCount(int count)
{
    object_count = count;
}

void VertexColorIndexVAO::setObjectVertexSize(int size)
{
    object_vertex_size = size;
}

void VertexColorIndexVAO::setObjectColorSize(int size)
{
    object_color_size = size;
}

void VertexColorIndexVAO::setObjectIndexSize(int size)
{
    object_index_size = size;
}
