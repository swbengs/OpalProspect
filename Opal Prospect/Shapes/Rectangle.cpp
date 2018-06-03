#include "Rectangle.hpp"

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

Rectangle::Rectangle()
{
    setWidthHeight(0.0f, 0.0f);
}

Rectangle::Rectangle(float width, float height)
{
    setWidthHeight(width, height);
}

//gets
float Rectangle::getWidth() const
{
    return hw.x;
}

float Rectangle::getHeight() const
{
    return hw.y;
}

const Point2D& Rectangle::getWidthHeight() const
{
    return hw;
}

Point2D Rectangle::getBottomLeft() const
{
    return Point2D(-0.5f * getWidth(), -0.5f * getHeight());
}

Point2D Rectangle::getBottomRight() const
{
    return Point2D(0.5f * getWidth(), -0.5f * getHeight());
}

Point2D Rectangle::getTopLeft() const
{
    return Point2D(-0.5f * getWidth(), 0.5f * getHeight());
}

Point2D Rectangle::getTopRight() const
{
    return Point2D(0.5f * getWidth(), 0.5f * getHeight());
}

//sets
void Rectangle::setWidth(float width)
{
    hw.x = width;
}

void Rectangle::setHeight(float height)
{
    hw.y = height;
}

void Rectangle::setWidthHeight(float width, float height)
{
    hw.setXY(width, height);
}

void Rectangle::setWidthHeight(const Point2D& point)
{
    hw = point;
}
