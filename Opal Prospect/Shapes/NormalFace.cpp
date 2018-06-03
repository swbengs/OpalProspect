#include "NormalFace.hpp"

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

NormalFace::NormalFace()
{

}

//gets
Point3D NormalFace::getBottomLeftNormal() const
{
    return bottom_left_normal;
}

Point3D NormalFace::getBottomRightNormal() const
{
    return bottom_right_normal;
}

Point3D NormalFace::getTopLeftNormal() const
{
    return top_left_normal;
}

Point3D NormalFace::getTopRightNormal() const
{
    return top_right_normal;
}

//sets
void NormalFace::setBottomLeftNormal(Point3D normal)
{
    bottom_left_normal = normal;
}

void NormalFace::setBottomRightNormal(Point3D normal)
{
    bottom_right_normal = normal;
}

void NormalFace::setTopLeftNormal(Point3D normal)
{
    top_left_normal = normal;
}

void NormalFace::setTopRightNormal(Point3D normal)
{
    top_right_normal = normal;
}

void NormalFace::setNormal(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right)
{
    bottom_left_normal = bottom_left;
    bottom_right_normal = bottom_right;
    top_left_normal = top_left;
    top_right_normal = top_right;
}
