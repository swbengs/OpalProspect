#include "VertexBox.hpp"

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

void VertexBox::fillVertexFace(VertexFace& front_face, VertexFace& back_face, VertexFace& left_face, VertexFace& right_face, VertexFace& top_face, VertexFace& bottom_face) const
{
    Point3D front_bottom_left = getFrontBottomLeft();
    Point3D front_bottom_right = getFrontBottomRight();
    Point3D front_top_left = getFrontTopLeft();
    Point3D front_top_right = getFrontTopRight();

    Point3D back_bottom_left = getBackBottomLeft();
    Point3D back_bottom_right = getBackBottomRight();
    Point3D back_top_left = getBackTopLeft();
    Point3D back_top_right = getBackTopRight();

    //front back left right top bottom
    front_face.setVertex(front_bottom_left, front_bottom_right, front_top_left, front_top_right);
    back_face.setVertex(back_bottom_right, back_bottom_left, back_top_right, back_top_left);
    left_face.setVertex(back_bottom_left, front_bottom_left, back_top_left, front_top_left);
    right_face.setVertex(front_bottom_right, back_bottom_right, front_top_right, back_top_right);
    top_face.setVertex(front_top_left, front_top_right, back_top_left, back_top_right);
    bottom_face.setVertex(back_bottom_left, back_bottom_right, front_bottom_left, front_bottom_right);
}

void VertexBox::fillIndexFace(VertexFace& front_face, VertexFace& back_face, VertexFace& left_face, VertexFace& right_face, VertexFace& top_face, VertexFace& bottom_face) const
{
    /*
    unsigned int offset = 0;

    front_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
    offset += 4;
    back_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
    offset += 4;
    left_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
    offset += 4;
    right_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
    offset += 4;
    top_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
    offset += 4;
    bottom_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
    */
}

void VertexBox::fillVertexIndexed(std::array<float, 96> &data) const
{
    size_t start = 0;
    Point3D front_bottom_left = getFrontBottomLeft();
    Point3D front_bottom_right = getFrontBottomRight();
    Point3D front_top_left = getFrontTopLeft();
    Point3D front_top_right = getFrontTopRight();

    Point3D back_bottom_left = getBackBottomLeft();
    Point3D back_bottom_right = getBackBottomRight();
    Point3D back_top_left = getBackTopLeft();
    Point3D back_top_right = getBackTopRight();

    //4 points * 4 floats = 16 floats per face

    //front
    fillFaceVertex(start, data.data(), front_bottom_left, front_bottom_right, front_top_left, front_top_right);
    start += 16;
    //back
    fillFaceVertex(start, data.data(), back_bottom_right, back_bottom_left, back_top_right, back_top_left);
    start += 16;
    //left
    fillFaceVertex(start, data.data(), back_bottom_left, front_bottom_left, back_top_left, front_top_left);
    start += 16;
    //right
    fillFaceVertex(start, data.data(), front_bottom_right, back_bottom_right, front_top_right, back_top_right);
    start += 16;
    //top
    fillFaceVertex(start, data.data(), front_top_left, front_top_right, back_top_left, back_top_right);
    start += 16;
    //bottom
    fillFaceVertex(start, data.data(), back_bottom_left, back_bottom_right, front_bottom_left, front_bottom_right);
}

void VertexBox::fillIndex(size_t start, std::array<unsigned int, 36> &data) const
{
    size_t data_offset = 0; //we have only exactly what we need so we start at the first element
    size_t index_offset = start * 24; //start at the next box which requires 24 ints for it's index

    for (int n = 0; n < 6; n++) 
    {
        fillFaceIndex(data_offset, index_offset, data.data(), 0, 1, 2, 3);
        data_offset += 6;
        index_offset += 4;
    }
}

//privates
void VertexBox::fillFaceVertex(size_t start, float* data, Point3D &bottom_left, Point3D &bottom_right, Point3D &top_left, Point3D &top_right) const
{
    size_t offset = 0;

    fillPoint(start, data, bottom_left);
    offset += 4;
    fillPoint(start + offset, data, bottom_right);
    offset += 4;
    fillPoint(start + offset, data, top_left);
    offset += 4;
    fillPoint(start + offset, data, top_right);
}

void VertexBox::fillPoint(size_t start, float* data, Point3D &point) const
{
    size_t offset = 0;

    data[start] = point.x;
    offset++;
    data[start + offset] = point.y;
    offset++;
    data[start + offset] = point.z;
    offset++;
    data[start + offset] = 1.0f;
}

/*

*/
void VertexBox::fillFaceIndex(size_t data_start, size_t index_offset, unsigned int *data, int bottom_left, int bottom_right, int top_left, int top_right) const
{
    size_t offset = 0;

    //triangle 1
    data[data_start] = bottom_left + index_offset;
    offset++;
    data[data_start + offset] = bottom_right + index_offset;
    offset++;
    data[data_start + offset] = top_left + index_offset;
    offset++;

    //triangle 2
    data[data_start + offset] = top_left + index_offset;
    offset++;
    data[data_start + offset] = bottom_right + index_offset;
    offset++;
    data[data_start + offset] = top_right + index_offset;
}
