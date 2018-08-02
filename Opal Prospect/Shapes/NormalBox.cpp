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
Point3D NormalBox::getFrontNormal() const
{
    return Point3D(-1.0f, 0.0f, 0.0f);
}

Point3D NormalBox::getBackNormal() const
{
    return Point3D(1.0f, 0.0f, 0.0f);
}

Point3D NormalBox::getLeftNormal() const
{
    return Point3D(0.0f, 0.0f, -1.0f);
}

Point3D NormalBox::getRightNormal() const
{
    return Point3D(0.0f, 0.0f, 1.0f);
}

Point3D NormalBox::getTopNormal() const
{
    return Point3D(0.0f, 1.0f, 0.0f);
}

Point3D NormalBox::getBottomNormal() const
{
    return Point3D(0.0f, -1.0f, 0.0f);
}

