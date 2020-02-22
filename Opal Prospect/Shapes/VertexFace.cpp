#include "VertexFace.hpp"

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

VertexFace::VertexFace()
{
    Point3D junk(0.0f, 0.0f, 0.0f);
    setVertex(junk, junk, junk, junk);
}

VertexFace::VertexFace(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right)
{
    setVertex(bottom_left, bottom_right, top_left, top_right);
}

void VertexFace::scaleVertex(unsigned int x_scale, unsigned int y_scale, unsigned int z_scale)
{
    bottom_left_vertex.scale(x_scale, y_scale, z_scale);
    bottom_right_vertex.scale(x_scale, y_scale, z_scale);
    top_left_vertex.scale(x_scale, y_scale, z_scale);
    top_right_vertex.scale(x_scale, y_scale, z_scale);
}

//gets
Point3D VertexFace::getBottomLeftVertex() const
{
    return bottom_left_vertex;
}

Point3D VertexFace::getBottomRightVertex() const
{
    return bottom_right_vertex;
}

Point3D VertexFace::getTopLeftVertex() const
{
    return top_left_vertex;
}

Point3D VertexFace::getTopRightVertex() const
{
    return top_right_vertex;
}

unsigned int VertexFace::getBottomLeftIndex() const
{
    return 0;
}

unsigned int VertexFace::getBottomRightIndex() const
{
    return 1;
}

unsigned int VertexFace::getTopLeftIndex() const
{
    return 2;
}

unsigned int VertexFace::getTopRightIndex() const
{
    return 3;
}

//sets
void VertexFace::setBottomLeftVertex(Point3D point)
{
    bottom_left_vertex = point;
}

void VertexFace::setBottomRightVertex(Point3D point)
{
    bottom_right_vertex = point;
}

void VertexFace::setTopLeftVertex(Point3D point)
{
    top_left_vertex = point;
}

void VertexFace::setTopRightVertex(Point3D point)
{
    top_right_vertex = point;
}

void VertexFace::setVertex(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right)
{
    bottom_left_vertex = bottom_left;
    bottom_right_vertex = bottom_right;
    top_left_vertex = top_left;
    top_right_vertex = top_right;
}

