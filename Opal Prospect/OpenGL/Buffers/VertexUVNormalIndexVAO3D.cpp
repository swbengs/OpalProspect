#include "VertexUVNormalIndexVAO3D.hpp"

#include <iostream>

VertexUVNormalIndexVAO3D::VertexUVNormalIndexVAO3D()
{
    maximum_size = 0;
    index_offset = 0;
}

void VertexUVNormalIndexVAO3D::bind() const
{
    vao.bindVAO();
}

void VertexUVNormalIndexVAO3D::unBind() const
{
    vao.unbindVAO();
}

void VertexUVNormalIndexVAO3D::bindVertex() const
{
    vertex.bindVBO();
}

void VertexUVNormalIndexVAO3D::bindUV() const
{
    uv.bindVBO();
}

void VertexUVNormalIndexVAO3D::bindNormal() const
{
    normal.bindVBO();
}

void VertexUVNormalIndexVAO3D::bindIndex() const
{
    index.bindVBO();
}

void VertexUVNormalIndexVAO3D::bufferVertex(const std::vector<float> &vector)
{
    vertex.addData(vector.size() * sizeof(float), vector.data());
}

void VertexUVNormalIndexVAO3D::bufferUV(const std::vector<float> &vector)
{
    uv.addData(vector.size() * sizeof(float), vector.data());
}

void VertexUVNormalIndexVAO3D::bufferNormal(const std::vector<float> &vector)
{
    normal.addData(vector.size() * sizeof(float), vector.data());
}

void VertexUVNormalIndexVAO3D::bufferIndex(const std::vector<unsigned int> &vector)
{
    index.addData(vector.size() * sizeof(unsigned int), vector.data());
}

void VertexUVNormalIndexVAO3D::create()
{
    //ensure nothing else is bound and being modified
    vao.unbindVAO();
    vertex.unbindVBO(); //only one call is needed since vertex, uv, and normals all share the same binding spot
    index.unbindVBO();

    vao.createVAO();
    vao.bindVAO();

    const static int vertex_dimensions = 4;
    const static int uv_dimensions = 3;
    const static int normal_dimensions = 4;

    const unsigned int point_size = (vertex_dimensions + uv_dimensions + normal_dimensions) * sizeof(float);
    const unsigned int point_index_size = sizeof(unsigned int);
    const unsigned int triangle_size = 3 * point_size + 3 * point_index_size;
    const unsigned int face_size = 4 * point_size + 6 * point_index_size;
    const float percent_faces = 1.0f;
    const float percent_triangles = 1.0f - percent_faces;
    const unsigned int triangle_count = static_cast<unsigned int>(getMaximumSize() * percent_triangles) / triangle_size;
    const unsigned int face_count = static_cast<unsigned int>(getMaximumSize() * percent_faces) / face_size;
    const unsigned int total_count = triangle_count + face_count;

    unsigned int vertex_size = triangle_count * 3 * vertex_dimensions * sizeof(float) + face_count * 4 * vertex_dimensions * sizeof(float);
    unsigned int uv_size = triangle_count * 3 * uv_dimensions * sizeof(float) + face_count * 4 * uv_dimensions * sizeof(float);
    unsigned int normal_size = triangle_count * 3 * normal_dimensions + face_count * 4 * normal_dimensions * sizeof(float);
    unsigned int index_size = triangle_count * 3 * point_index_size + face_count * 6 * point_index_size;
    unsigned int total = vertex_size + uv_size + normal_size  + index_size;

    vertex.generateVBOID();
    vertex.bindVBO();
    vertex.setMaximumSize(vertex_size);
    vertex.setDimensions(vertex_dimensions);
    vertex.setBindIndex(0);

    vertex.createVBO();
    vertex.enableVertexIndex();
    vertex.vertexPointer();

    uv.generateVBOID();
    uv.bindVBO();
    uv.setMaximumSize(uv_size);
    uv.setDimensions(uv_dimensions);
    uv.setBindIndex(1);

    uv.createVBO();
    uv.enableVertexIndex();
    uv.vertexPointer();

    normal.generateVBOID();
    normal.bindVBO();
    normal.setMaximumSize(normal_size);
    normal.setDimensions(normal_dimensions);
    normal.setBindIndex(2);

    normal.createVBO();
    //normal.enableVertexIndex();
    //normal.vertexPointer();

    index.generateVBOID();
    index.bindVBO();
    index.setMaximumSize(index_size);

    index.createVBO();
    //dont need to assign how to access the data. therefore no enable index or vertex pointer needed for index data

    vao.unbindVAO(); //ensure this wont be modified elsewhere
}

void VertexUVNormalIndexVAO3D::destroy()
{
    vertex.destroyVBO();
    uv.destroyVBO();
    index.destroyVBO();
    normal.destroyVBO();
    vao.destroyVAO();
}

//gets
unsigned int VertexUVNormalIndexVAO3D::getID() const
{
    return vao.getID();
}

size_t VertexUVNormalIndexVAO3D::getMaximumSize() const
{
    return maximum_size;
}

size_t VertexUVNormalIndexVAO3D::getRemainingSize() const
{
    return vertex.getRemainingSize() + uv.getRemainingSize() + normal.getRemainingSize() + index.getRemainingSize();
}

size_t VertexUVNormalIndexVAO3D::getRemainingIndexSize() const
{
    return index.getRemainingSize();
}

unsigned int VertexUVNormalIndexVAO3D::getIndexOffset() const
{
    return index_offset;
}

//sets
void VertexUVNormalIndexVAO3D::setMaximumSize(size_t size)
{
    maximum_size = size;
}

void VertexUVNormalIndexVAO3D::setIndexOffset(unsigned int offset)
{
    index_offset = offset;
}

