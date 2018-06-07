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

//class code

RightRectanglePyramidNormal::RightRectanglePyramidNormal()
{
    Point3D junk(0.0f, 0.0f, 0.0f);
    setNormal(junk, junk, junk, junk, junk);
}

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
    return front_normal;
}

Point3D RightRectanglePyramidNormal::getBackNormal() const
{
    return back_normal;
}

Point3D RightRectanglePyramidNormal::getLeftNormal() const
{
    return left_normal;
}

Point3D RightRectanglePyramidNormal::getRightNormal() const
{
    return right_normal;
}

Point3D RightRectanglePyramidNormal::getBottomNormal() const
{
    return bottom_normal;
}

void RightRectanglePyramidNormal::setFrontNormal(Point3D front)
{
    front_normal = front;
}

void RightRectanglePyramidNormal::setBackNormal(Point3D back)
{
    back_normal = back;
}

void RightRectanglePyramidNormal::setLeftNormal(Point3D left)
{
    left_normal = left;
}

void RightRectanglePyramidNormal::setRightNormal(Point3D right)
{
    right_normal = right;
}

void RightRectanglePyramidNormal::setBottomNormal(Point3D bottom)
{
    bottom_normal = bottom;
}

void RightRectanglePyramidNormal::setNormal(const Point3D& front, const Point3D& back, const Point3D& left, const Point3D& right, const Point3D& bottom)
{
    front_normal = front;
    back_normal = back;
    left_normal = left;
    right_normal = right;
    bottom_normal = bottom;
}
