#include "Triangle3D.hpp"

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

Triangle3D::Triangle3D()
{
    Point3D junk(0.0f, 0.0f, 0.0f);
    setABC(junk, junk, junk);
}

//gets
Point3D Triangle3D::getA() const
{
    return point_a;
}

Point3D Triangle3D::getB() const
{
    return point_b;
}

Point3D Triangle3D::getC() const
{
    return point_c;
}

//sets
void Triangle3D::setA(Point3D a)
{
    point_a = a;
}

void Triangle3D::setB(Point3D b)
{
    point_b = b;
}

void Triangle3D::setC(Point3D c)
{
    point_c = c;
}

void Triangle3D::setABC(Point3D a, Point3D b, Point3D c)
{
    point_a = a;
    point_b = b;
    point_c = c;
}
