#pragma once

#include <vector>

#include "FloatVBO.hpp"
#include "IntVBO.hpp"
#include "VAO.hpp"

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
