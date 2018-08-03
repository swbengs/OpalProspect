#pragma once
//parent
#include "RightRectanglePyramidTexture.hpp"
//std lib includes

//other includes
#include "NormalFace.hpp"
#include "NormalTriangle.hpp"

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
Description: This structure is still not fully decided on. Give a basic description of what this class does at a minimum. More detail is always welcome.
*/

class RightRectanglePyramidNormal : public RightRectanglePyramidTexture
{
public:
    void fillNormalTriangleFace(NormalTriangle& front_triangle, NormalTriangle& back_triangle, NormalTriangle& left_triangle, NormalTriangle& right_triangle, NormalFace& bottom_face) const;

    //gets
    Point3D getFrontNormal() const;
    Point3D getBackNormal() const;
    Point3D getLeftNormal() const;
    Point3D getRightNormal() const;
    Point3D getBottomNormal() const;
};

