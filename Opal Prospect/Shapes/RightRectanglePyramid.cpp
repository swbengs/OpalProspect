#include "RightRectanglePyramid.hpp"

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

RightRectanglePyramid::RightRectanglePyramid()
{
    whl.setXYZ(0.0f, 0.0f, 0.0f);
}

float RightRectanglePyramid::getWidth() const
{
    return whl.x;
}

float RightRectanglePyramid::getHeight() const
{
    return whl.y;
}

float RightRectanglePyramid::getLength() const
{
    return whl.z;
}

Point3D RightRectanglePyramid::getWidthHeightLength() const
{
    return whl;
}

Point3D RightRectanglePyramid::getApex() const
{
    return Point3D();
}

Point3D RightRectanglePyramid::getFrontLeft() const
{
    return Point3D();
}

Point3D RightRectanglePyramid::getFrontRight() const
{
    return Point3D();
}

Point3D RightRectanglePyramid::getBackLeft() const
{
    return Point3D();
}

Point3D RightRectanglePyramid::getBackRight() const
{
    return Point3D();
}

void RightRectanglePyramid::setWidth(float width)
{
    whl.x = width;
}

void RightRectanglePyramid::setHeight(float height)
{
    whl.y = height;
}

void RightRectanglePyramid::setLength(float length)
{
    whl.z = length;
}

void RightRectanglePyramid::setWidthHeightLength(float width, float height, float length)
{
    whl.setXYZ(width, height, length);
}
