#pragma once

#include <vector>

#include "FloatVBO.hpp"
#include "IntVBO.hpp"
#include "VAO.hpp"

/*
This class pairs up float buffers, int buffers, and a VAO class for easy use.
*/

class VertexUVNormalIndexVAO3D
{
public:
    VertexUVNormalIndexVAO3D();

    void bind() const;
    void unBind() const;
    void bindVertex() const;
    void bindUV() const;
    void bindNormal() const;
    void bindIndex() const;

    void bufferVertex(const std::vector<float> &vector);
    void bufferUV(const std::vector<float> &vector);
    void bufferNormal(const std::vector<float> &vector);
    void bufferIndex(const std::vector<unsigned int> &vector);

    void create();
    void destroy();

    //gets
    unsigned int getID() const;
    size_t getMaximumSize() const;
    size_t getRemainingSize() const;
    size_t getRemainingIndexSize() const;
    unsigned int getIndexOffset() const;

    //sets
    void setMaximumSize(size_t size);
    void setIndexOffset(unsigned int offset);
    
private:
    VAO vao;
    FloatVBO vertex; //xyzw
    FloatVBO uv; //rgba
    FloatVBO normal; //xyzw
    IntVBO index; //indices

    size_t maximum_size; //size in bytes split up amoung all the buffers
    unsigned int index_offset; //must stay uint as that's what opengl uses
};
