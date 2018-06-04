#include "CenterBox.hpp"

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

CenterBox::CenterBox()
{
    setWidthHeightLength(0.0f, 0.0f, 0.0f);
    setXYZ(0.0f, 0.0f, 0.0f);
}

CenterBox::CenterBox(const Box& box) : Box(box)
{
    setXYZ(0.0f, 0.0f, 0.0f);
}

//gets
float CenterBox::getX() const
{
    return center.x;
}

float CenterBox::getY() const
{
    return center.y;
}

float CenterBox::getZ() const
{
    return center.z;
}

const Point3D& CenterBox::getXYZ() const
{
    return center;
}

Point3D CenterBox::getLiteralFrontBottomLeft() const
{
    Point3D point = getFrontBottomLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralFrontBottomRight() const
{
    Point3D point = getFrontBottomRight();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralFrontTopLeft() const
{
    Point3D point = getFrontTopLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralFrontTopRight() const
{
    Point3D point = getFrontTopRight();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackBottomLeft() const
{
    Point3D point = getBackBottomLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackBottomRight() const
{
    Point3D point = getBackBottomRight();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackTopLeft() const
{
    Point3D point = getBackTopLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackTopRight() const
{
    Point3D point = getBackTopRight();
    addCenter(point);

    return point;
}

//sets
void CenterBox::setX(float X)
{
    center.x = X;
}

void CenterBox::setY(float Y)
{
    center.y = Y;
}

void CenterBox::setZ(float Z)
{
    center.z = Z;
}

void CenterBox::setXYZ(float X, float Y, float Z)
{
    center.setXYZ(X, Y, Z);
}

void CenterBox::setXYZ(const Point3D& point)
{
    center = point;
}

//privates
void CenterBox::addCenter(Point3D& point) const
{
    point.setXYZ(point.x + getX(), point.y + getY(), point.z + getZ());
}
