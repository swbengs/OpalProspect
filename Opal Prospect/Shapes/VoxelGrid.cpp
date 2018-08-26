//class header
#include "VoxelGrid.hpp"

//std lib includes
#include <assert.h>

//other includes

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

Point3D VoxelGrid::getPosition(unsigned int index)
{
    return Point3D();
}

unsigned int VoxelGrid::getGridCount() const
{
    return getGridWidth() * getGridHeight() * getGridLength();
}

unsigned int VoxelGrid::getGridWidth() const
{
    return grid_width;
}

unsigned int VoxelGrid::getGridHeight() const
{
    return grid_height;
}

unsigned int VoxelGrid::getGridLength() const
{
    return grid_length;
}

float VoxelGrid::getBoxWidth() const
{
    return box.getWidth();
}

float VoxelGrid::getBoxHeight() const
{
    return box.getHeight();
}

float VoxelGrid::getBoxLength() const
{
    return box.getLength();
}

float VoxelGrid::getYOffset() const
{
    return y_offset;
}

float VoxelGrid::getYStride() const
{
    return y_stride;
}

void VoxelGrid::setGridWidth(unsigned int width)
{
    grid_width = width;
}

void VoxelGrid::setGridHeight(unsigned int height)
{
    grid_height = height;
}

void VoxelGrid::setGridLength(unsigned int length)
{
    grid_length = length;
}

void VoxelGrid::setGridWidthLengthHeight(unsigned int width, unsigned int height, unsigned int length)
{
    setGridWidth(width);
    setGridHeight(height);
    setGridLength(length);
}

void VoxelGrid::setBoxWidth(float width)
{
    box.setWidth(width);
}

void VoxelGrid::setBoxHeight(float height)
{
    box.setHeight(height);
}

void VoxelGrid::setBoxLength(float length)
{
    box.setLength(length);
}

void VoxelGrid::setBoxWidthLengthHeight(float width, float height, float length)
{
    box.setWidthHeightLength(width, height, length);
}

void VoxelGrid::setYOffset(float offset)
{
    y_offset = offset;
}

void VoxelGrid::setYStride(float stride)
{
    y_stride = stride;
}


