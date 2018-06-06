#include "TextureTriangle.hpp"

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

TextureTriangle::TextureTriangle()
{
    Point3D junk;
    junk.setXYZ(0.0f, 0.0f, 0.0f);
    setABCUV(junk, junk, junk);
}

Point3D TextureTriangle::getAUV() const
{
    return a_uv;
}

Point3D TextureTriangle::getBUV() const
{
    return b_uv;
}

Point3D TextureTriangle::getCUV() const
{
    return c_uv;
}

void TextureTriangle::setA(Point3D point)
{
    a_uv = point;
}

void TextureTriangle::setB(Point3D point)
{
    b_uv = point;
}

void TextureTriangle::setC(Point3D point)
{
    c_uv = point;
}

void TextureTriangle::setABCUV(Point3D a, Point3D b, Point3D c)
{
    a_uv = a;
    b_uv = b;
    c_uv = c;
}
