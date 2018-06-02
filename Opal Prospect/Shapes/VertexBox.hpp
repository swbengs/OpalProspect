#pragma once

#include "Box.hpp"

#include <array>

#include "VertexFace.hpp"
#include "Point3D.hpp"

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

*/

class VertexBox : public Box
{
public:
    void fillVertexFace(VertexFace& front_face, VertexFace& back_face, VertexFace& left_face, VertexFace& right_face, VertexFace& top_face, VertexFace& bottom_face) const;
    void fillIndexFace(VertexFace& front_face, VertexFace& back_face, VertexFace& left_face, VertexFace& right_face, VertexFace& top_face, VertexFace& bottom_face)const;

    //6 faces * 4 points * 4 floats each = 96 floats
    void fillVertexIndexed(std::array<float, 96> &data) const; //fills in 4d coordinates
    //6 faces * 2 triangles * 3 index each
    void fillIndex(size_t start, std::array<unsigned int, 36> &data) const;
private:
    void fillFaceVertex(size_t start, float* data, Point3D &bottom_left, Point3D &bottom_right, Point3D &top_left, Point3D &top_right) const;
    void fillPoint(size_t start, float *data, Point3D &point) const;
    //data start is where in the int pointer you want to start writing at, and index start is what index number to start from. For example if it's the second box you would have 2 * size of box index
    void fillFaceIndex(size_t data_start, size_t index_offset, unsigned int *data, int bottom_left, int bottom_right, int top_left, int top_right) const;
};
