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

NormalTriangle::NormalTriangle()
{
    Point3D junk;
    junk.setXYZ(0.0f, 0.0f, 0.0f);
    setABCNormal(junk, junk, junk);
}

Point3D NormalTriangle::getANormal() const
{
    return normal_a;
}

Point3D NormalTriangle::getBNormal() const
{
    return normal_b;
}

Point3D NormalTriangle::getCNormal() const
{
    return normal_c;
}

void NormalTriangle::setANormal(Point3D point)
{
    normal_a = point;
}

void NormalTriangle::setBNormal(Point3D point)
{
    normal_b = point;
}

void NormalTriangle::setCNormal(Point3D point)
{
    normal_c = point;
}

void NormalTriangle::setABCNormal(Point3D a, Point3D b, Point3D c)
{
    normal_a = a;
    normal_b = b;
    normal_c = c;
}
