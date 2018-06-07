#include "RightRectanglePyramidVertex.hpp"

//std lib includes

//other includes

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

void RightRectanglePyramidVertex::fillVertexFace(VertexTriangle& front_triangle, VertexTriangle& back_triangle, VertexTriangle& left_triangle, VertexTriangle& right_triangle, VertexFace& bottom_face) const
{
    Point3D front_left = getFrontLeft();
    Point3D front_right = getFrontLeft();
    Point3D back_left = getBackLeft();
    Point3D back_right = getFrontLeft();
    Point3D apex = getApex();

    front_triangle.setVertexABC(front_left, front_right, apex);
    back_triangle.setVertexABC(back_right, back_left, apex);
    left_triangle.setVertexABC(back_left, front_left, apex);
    right_triangle.setVertexABC(front_left, front_right, apex);
    bottom_face.setVertex(back_left, back_right, front_left, front_right);
}

void RightRectanglePyramidVertex::fillIndexFace(VertexTriangle& front_triangle, VertexTriangle& back_triangle, VertexTriangle& left_triangle, VertexTriangle& right_triangle, VertexFace& bottom_face) const
{
    unsigned int offset = 0;

    front_triangle.setIndexABC(offset, offset + 1, offset + 2);
    offset += 3;
    back_triangle.setIndexABC(offset, offset + 1, offset + 2);
    offset += 3;
    left_triangle.setIndexABC(offset, offset + 1, offset + 2);
    offset += 3;
    right_triangle.setIndexABC(offset, offset + 1, offset + 2);
    offset += 3;
    bottom_face.setIndex(offset, offset + 1, offset + 2, offset + 3);
}
