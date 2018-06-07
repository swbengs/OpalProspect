#pragma once

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
Class to store a face with only a vertex and index for it. A face meaning 4 points creating a rectangle
*/

class VertexFace
{
public:
    VertexFace();
    VertexFace(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right);

    //gets
    Point3D getBottomLeftVertex() const;
    Point3D getBottomRightVertex() const;
    Point3D getTopLeftVertex() const;
    Point3D getTopRightVertex() const;

    unsigned int getBottomLeftIndex() const;
    unsigned int getBottomRightIndex() const;
    unsigned int getTopLeftIndex() const;
    unsigned int getTopRightIndex() const;

    //sets
    void setBottomLeftVertex(Point3D point);
    void setBottomRightVertex(Point3D point);
    void setTopLeftVertex(Point3D point);
    void setTopRightVertex(Point3D point);
    void setVertex(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right);

    void setBottomLeftIndex(unsigned int index);
    void setBottomRightIndex(unsigned int index);
    void setTopLeftIndex(unsigned int index);
    void setTopRightIndex(unsigned int index);
    void setIndex(unsigned int bottom_left, unsigned int bottom_right, unsigned int top_left, unsigned int top_right);

private:
    Point3D bottom_left_vertex;
    Point3D bottom_right_vertex;
    Point3D top_left_vertex;
    Point3D top_right_vertex;

    unsigned int bottom_left_index;
    unsigned int bottom_right_index;
    unsigned int top_left_index;
    unsigned int top_right_index;
};
