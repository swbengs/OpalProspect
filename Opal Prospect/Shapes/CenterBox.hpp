#pragma once

#include "Shapes\Box.hpp"

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

class CenterBox : public Box
{
public:
    CenterBox();
    CenterBox(const Box& box);

    //gets
    float getX() const;
    float getY() const;
    float getZ() const;
    const Point3D& getXYZ() const;

    //these gets are based on where the center is. So if the center is at 100, 0, you would add 100 to the x value and 0 to the y value
    Point3D getLiteralFrontBottomLeft() const;
    Point3D getLiteralFrontBottomRight() const;
    Point3D getLiteralFrontTopLeft() const;
    Point3D getLiteralFrontTopRight() const;

    Point3D getLiteralBackBottomLeft() const;
    Point3D getLiteralBackBottomRight() const;
    Point3D getLiteralBackTopLeft() const;
    Point3D getLiteralBackTopRight() const;

    //sets
    void setX(float X);
    void setY(float Y);
    void setZ(float Z);
    void setXYZ(float X, float Y, float Z);
    void setXYZ(const Point3D& point);

private:
    Point3D center;

    void addCenter(Point3D& point) const;
};
