#pragma once

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

//Rectangle with a center

class CenterRectangle : public Rectangle
{
public:
    CenterRectangle();
    CenterRectangle(float X, float Y);

    //gets
    float getX() const;
    float getY() const;
    const Point2D& getXY() const;

    //these gets are based on where the center is. So if the center is at 100, 0, you would add 100 to the x value and 0 to the y value
    Point2D getLiteralBottomLeft() const;
    Point2D getLiteralBottomRight() const;
    Point2D getLiteralTopLeft() const;
    Point2D getLiteralTopRight() const;

    //sets
    void setX(float X);
    void setY(float Y);
    void setXY(float X, float Y);
    void setXY(const Point2D& point);

private:
    Point2D center;
};
