#pragma once

#include <vector>
#include <array>

#include "FloatVBO.hpp"
#include "IntVBO.hpp"
#include "VAO.hpp"

/*
Pair up float and int buffers with a VAO for easy use.
*/

class VertexColorIndexVAO
{
public:
    void bind() const;
    void unBind() const;
    void bindVertex() const;
    void bindColor() const;
    void bindIndex() const;

    void bufferVertex(int start, const std::vector<float> &vector);
    void bufferVertex(int start, int count, const float* data);
    void bufferColor(int start, const std::vector<float> &vector);
    void bufferColor(int start, int count, const float* data);
    void bufferIndex(int start, const std::vector<int> &vector);
    void bufferIndex(int start, int count, const int* data);

    void create();
    void destroy();

    //gets
    int getObjectCount() const;
    int getObjectVertexSize() const;
    int getObjectColorSize() const;
    int getObjectIndexSize() const;
    //sets
    void setObjectCount(int count);
    void setObjectVertexSize(int size);
    void setObjectColorSize(int size);
    void setObjectIndexSize(int size);
private:
    VAO vao;
    FloatVBO vertex; //xy
    FloatVBO color; //rgba
    IntVBO index; //indices

    int object_count; //how many to store
    int object_vertex_size; //size of a single object's vertex data
    int object_color_size; //size of a single object's color
    int object_index_size; //size of a single object's index
};
