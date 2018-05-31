#pragma once

#include <vector>

#include "FloatVBO.hpp"
#include "IntVBO.hpp"
#include "VAO.hpp"

/*
This class pairs up float buffers, int buffers, and a VAO class for easy use.
*/

class VertexUVIndexVAO
{
public:
    void bind() const;
    void unBind() const;
    void bindVertex() const;
    void bindUV() const;
    void bindIndex() const;

    void bufferVertex(size_t start, const std::vector<float> &vector);
    void bufferUV(size_t start, const std::vector<float> &vector);
    void bufferIndex(size_t start, const std::vector<unsigned int> &vector);

    void create();
    void destroy();

    //gets
    unsigned int getID() const;
    int getObjectCount() const;
    int getObjectVertexSize() const;
    int getObjectUVSize() const;
    int getObjectIndexSize() const;
    //sets
    void setObjectCount(int count); //so 10 objects means enter 10
    void setObjectVertexSize(int size); //vertex are floats so say 96 floats for a box
    void setObjectUVSize(int size); //same as vertex but different number
    void setObjectIndexSize(int size);
private:
    VAO vao;
    FloatVBO vertex; //xy
    FloatVBO uv; //rgba
    IntVBO index; //indices

    int object_count; //how many to store
    int object_vertex_size; //size of a single object's vertex data
    int object_uv_size; //size of a single object's uv. also known as texture coordinates
    int object_index_size; //size of a single object's index
};
