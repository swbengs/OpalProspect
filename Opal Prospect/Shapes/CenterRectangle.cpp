#include "CenterRectangle.hpp"

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

CenterRectangle::CenterRectangle()
{
    setXY(0.0f, 0.0f);
}

CenterRectangle::CenterRectangle(float X, float Y) : Rectangle(0.0f, 0.0f)
{
    setXY(X, Y);
}

//gets
float CenterRectangle::getX() const
{
    return center.x;
}

float CenterRectangle::getY() const
{
    return center.y;
}

const Point2D& CenterRectangle::getXY() const
{
    return center;
}

Point2D CenterRectangle::getLiteralBottomLeft() const
{
    Point2D point = getBottomLeft();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

Point2D CenterRectangle::getLiteralBottomRight() const
{
    Point2D point = getBottomRight();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

Point2D CenterRectangle::getLiteralTopLeft() const
{
    Point2D point = getTopLeft();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

Point2D CenterRectangle::getLiteralTopRight() const
{
    Point2D point = getTopRight();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

//sets
void CenterRectangle::setX(float X)
{
    center.x = X;
}

void CenterRectangle::setY(float Y)
{
    center.y = Y;
}

void CenterRectangle::setXY(float X, float Y)
{
    center.setXY(X, Y);
}

void CenterRectangle::setXY(const Point2D& point)
{
    center = point;
}
