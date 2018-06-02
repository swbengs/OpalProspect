#pragma once

#include "Point3D.hpp"

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

/*
Class for a Box.
*/

class Box
{
public:
    Box();

    //gets
    float getWidth() const;
    float getHeight() const;
    float getLength() const;
    Point3D getWidthHeightLength() const;

    Point3D getFrontBottomLeft() const;
    Point3D getFrontBottomRight() const;
    Point3D getFrontTopLeft() const;
    Point3D getFrontTopRight() const;

    Point3D getBackBottomLeft() const;
    Point3D getBackBottomRight() const;
    Point3D getBackTopLeft() const;
    Point3D getBackTopRight() const;

    //sets
    void setWidth(float width);
    void setHeight(float height);
    void setLength(float length);
    void setWidthHeightLength(float width,  float height,  float length);
private:
    Point3D whl; //width height length
};

