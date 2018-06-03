#include "NormalBox.hpp"

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

NormalBox::NormalBox()
{
    front_normal.setXYZ(0.0f, 0.0f, 0.0f);
    back_normal.setXYZ(0.0f, 0.0f, 0.0f);
    left_normal.setXYZ(0.0f, 0.0f, 0.0f);
    right_normal.setXYZ(0.0f, 0.0f, 0.0f);
    top_normal.setXYZ(0.0f, 0.0f, 0.0f);
    bottom_normal.setXYZ(0.0f, 0.0f, 0.0f);
}

void NormalBox::fillNormalFace(NormalFace& front_face, NormalFace& back_face, NormalFace& left_face, NormalFace& right_face, NormalFace& top_face, NormalFace& bottom_face) const
{
    //front back left right top bottom
    front_face.setNormal(getFrontNormal(), getFrontNormal(), getFrontNormal(), getFrontNormal());
    back_face.setNormal(getBackNormal(), getBackNormal(), getBackNormal(), getBackNormal());
    left_face.setNormal(getLeftNormal(), getLeftNormal(), getLeftNormal(), getLeftNormal());
    right_face.setNormal(getRightNormal(), getRightNormal(), getRightNormal(), getRightNormal());
    top_face.setNormal(getTopNormal(), getTopNormal(), getTopNormal(), getTopNormal());
    bottom_face.setNormal(getBottomNormal(), getBottomNormal(), getBottomNormal(), getBottomNormal());
}

//gets
const Point3D& NormalBox::getFrontNormal() const
{
    return front_normal;
}

const Point3D& NormalBox::getBackNormal() const
{
    return back_normal;
}

const Point3D& NormalBox::getLeftNormal() const
{
    return left_normal;
}

const Point3D& NormalBox::getRightNormal() const
{
    return right_normal;
}

const Point3D& NormalBox::getTopNormal() const
{
    return top_normal;
}

const Point3D& NormalBox::getBottomNormal() const
{
    return bottom_normal;
}

//sets
void NormalBox::setFrontNormal(const Point3D& normal)
{
    front_normal = normal;
}

void NormalBox::setBackNormal(const Point3D& normal)
{
    back_normal = normal;
}

void NormalBox::setLeftNormal(const Point3D& normal)
{
    left_normal = normal;
}

void NormalBox::setRightNormal(const Point3D& normal)
{
    right_normal = normal;
}

void NormalBox::setTopNormal(const Point3D& normal)
{
    top_normal = normal;
}

void NormalBox::setBottomNormal(const Point3D& normal)
{
    bottom_normal = normal;
}

void NormalBox::setNormal(const Point3D& front, const Point3D& back, const Point3D& left, const Point3D& right, const Point3D& top, const Point3D& bottom)
{
    front_normal = front;
    back_normal = back;
    left_normal = left;
    right_normal = right;
    top_normal = top;
    bottom_normal = bottom;
}
