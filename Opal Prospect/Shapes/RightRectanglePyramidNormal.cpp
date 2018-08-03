#include "RightRectanglePyramidNormal.hpp"

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

void RightRectanglePyramidNormal::fillNormalTriangleFace(NormalTriangle& front_triangle, NormalTriangle& back_triangle, NormalTriangle& left_triangle, NormalTriangle& right_triangle, NormalFace& bottom_face) const
{
    front_triangle.setABCNormal(getFrontNormal(), getFrontNormal(), getFrontNormal());
    back_triangle.setABCNormal(getBackNormal(), getBackNormal(), getBackNormal());
    left_triangle.setABCNormal(getLeftNormal(), getLeftNormal(), getLeftNormal());
    right_triangle.setABCNormal(getRightNormal(), getRightNormal(), getRightNormal());
    bottom_face.setNormal(getBottomNormal(), getBottomNormal(), getBottomNormal(), getBottomNormal());
}

Point3D RightRectanglePyramidNormal::getFrontNormal() const
{
    return Point3D(0.0f, 0.0f, -1.0f);
}

Point3D RightRectanglePyramidNormal::getBackNormal() const
{
    return Point3D(0.0f, 0.0f, 1.0f);
}

Point3D RightRectanglePyramidNormal::getLeftNormal() const
{
    return Point3D(-1.0f, 0.0f, 0.0f);
}

Point3D RightRectanglePyramidNormal::getRightNormal() const
{
    return Point3D(1.0f, 0.0f, 0.0f);
}

Point3D RightRectanglePyramidNormal::getBottomNormal() const
{
    return Point3D(0.0f, -1.0f, 0.0f);
}

