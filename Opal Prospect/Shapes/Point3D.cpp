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

Point3D::Point3D(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

void Point3D::fillArray3D(std::vector<float>& vector) const
{
    vector.push_back(x);
    vector.push_back(y);
    vector.push_back(z);
}

void Point3D::fillArray3D(size_t start, std::vector<float>& vector) const
{
    vector[start] = x;
    vector[start + 1] = y;
    vector[start + 2] = z;
}

void Point3D::scale(unsigned int x_scale, unsigned int y_scale, unsigned int z_scale)
{
    setXYZ(x * x_scale, y * y_scale, z * z_scale);
}

//sets
void Point3D::setXYZ(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}
