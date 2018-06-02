#pragma once

#include <vector>
#include <array>

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
