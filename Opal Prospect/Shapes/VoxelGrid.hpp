#pragma once

//std lib includes
#include <vector>

//other includes
#include "Box.hpp"
#include "Point3D.hpp"
#include "Point3DUInt.hpp"

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

class VoxelGrid
{
public:

    //gets
    Point3D getPosition(unsigned int index);

    unsigned int getGridCount() const;
    unsigned int getGridWidth() const;
    unsigned int getGridHeight() const;
    unsigned int getGridLength() const;

    float getBoxWidth() const;
    float getBoxHeight() const;
    float getBoxLength() const;
    float getYOffset() const;
    float getYStride() const;

    void setGridWidth(unsigned int width);
    void setGridHeight(unsigned int height);
    void setGridLength(unsigned int length);
    void setGridWidthLengthHeight(unsigned int width, unsigned int height, unsigned int length);

    void setBoxWidth(float width);
    void setBoxHeight(float height);
    void setBoxLength(float length);
    void setBoxWidthLengthHeight(float width, float height, float length);

    void setYOffset(float offset);
    void setYStride(float stride);

private:
    Box box;

    float y_offset; //change from origin
    float y_stride; //distance between each layer
    unsigned int grid_width;
    unsigned int grid_height;
    unsigned int grid_length;
};

