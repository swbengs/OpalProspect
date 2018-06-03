#include "Box.hpp"

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

Box::Box()
{
    setWidthHeightLength(0.0f, 0.0f, 0.0f);
}

//gets
float Box::getWidth() const
{
    return whl.x;
}

float Box::getHeight() const
{
    return whl.y;
}

float Box::getLength() const
{
    return whl.z;
}

Point3D Box::getWidthHeightLength() const
{
    return whl;
}

Point3D Box::getFrontBottomLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * -0.5f, getLength() * -0.5f);
}

Point3D Box::getFrontBottomRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * -0.5f, getLength() * -0.5f);
}

Point3D Box::getFrontTopLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * 0.5f, getLength() * -0.5f);
}

Point3D Box::getFrontTopRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * 0.5f, getLength() * -0.5f);
}

Point3D Box::getBackBottomLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * -0.5f, getLength() * 0.5f);
}

Point3D Box::getBackBottomRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * -0.5f, getLength() * 0.5f);
}

Point3D Box::getBackTopLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * 0.5f, getLength() * 0.5f);
}

Point3D Box::getBackTopRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * 0.5f, getLength() * 0.5f);
}

//sets
void Box::setWidth(float width)
{
    whl.x = width;
}

void Box::setHeight(float height)
{
    whl.y = height;
}

void Box::setLength(float length)
{
    whl.z = length;
}

void Box::setWidthHeightLength(float width, float height, float length)
{
    setWidth(width);
    setHeight(height);
    setLength(length);
}
