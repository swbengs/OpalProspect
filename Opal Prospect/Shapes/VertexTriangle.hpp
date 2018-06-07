#pragma once

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

class VertexTriangle : public Triangle3D
{
public:

    VertexTriangle();
    VertexTriangle(Point3D a, Point3D b, Point3D c);

    //gets
    unsigned int getIndexA() const;
    unsigned int getIndexB() const;
    unsigned int getIndexC() const;
    Point3D getVertexA() const;
    Point3D getVertexB() const;
    Point3D getVertexC() const;

    //sets
    void setIndexA(unsigned int a);
    void setIndexB(unsigned int b);
    void setIndexC(unsigned int c);
    void setIndexABC(unsigned int a, unsigned int b, unsigned int c);
    void setVertexA(Point3D a);
    void setVertexB(Point3D b);
    void setVertexC(Point3D c);
    void setVertexABC(Point3D a, Point3D b, Point3D c);

private:
    Point3D point_a;
    Point3D point_b;
    Point3D point_c;

    unsigned int index_a;
    unsigned int index_b;
    unsigned int index_c;
};
