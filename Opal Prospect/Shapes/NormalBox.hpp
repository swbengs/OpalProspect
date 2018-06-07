#pragma once

#include "TextureBox.hpp"

#include "NormalFace.hpp"
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

class NormalBox : public TextureBox
{
public:
    NormalBox();

    void fillNormalFace(NormalFace& front_face, NormalFace& back_face, NormalFace& left_face, NormalFace& right_face, NormalFace& top_face, NormalFace& bottom_face) const;

    //gets
    Point3D getFrontNormal() const;
    Point3D getBackNormal() const;
    Point3D getLeftNormal() const;
    Point3D getRightNormal() const;
    Point3D getTopNormal() const;
    Point3D getBottomNormal() const;

    //sets
    void setFrontNormal(const Point3D& normal);
    void setBackNormal(const Point3D& normal);
    void setLeftNormal(const Point3D& normal);
    void setRightNormal(const Point3D& normal);
    void setTopNormal(const Point3D& normal);
    void setBottomNormal(const Point3D& normal);
    void setNormal(const Point3D& front, const Point3D& back, const Point3D& left, const Point3D& right, const Point3D& top, const Point3D& bottom);

private:
    Point3D front_normal, back_normal, left_normal, right_normal, top_normal, bottom_normal;
};
