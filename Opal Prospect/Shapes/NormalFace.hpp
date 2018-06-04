#pragma once

#include "TextureFace.hpp"

#include <vector>

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
Class that stores the normals for a face
*/

class NormalFace : public TextureFace
{
public:
    NormalFace();

    //gets
    Point3D getBottomLeftNormal() const;
    Point3D getBottomRightNormal() const;
    Point3D getTopLeftNormal() const;
    Point3D getTopRightNormal() const;

    //sets
    void setBottomLeftNormal(Point3D normal);
    void setBottomRightNormal(Point3D normal);
    void setTopLeftNormal(Point3D normal);
    void setTopRightNormal(Point3D normal);
    void setNormal(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right);

private:
    Point3D bottom_left_normal;
    Point3D bottom_right_normal;
    Point3D top_left_normal;
    Point3D top_right_normal;
};