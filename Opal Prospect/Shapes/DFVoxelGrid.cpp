//class header
#include "DFVoxelGrid.hpp"

//std lib includes
#include <assert.h>

//other includes

/*
MIT License

Copyright (c) 2020 Scott Bengs

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

Point3D DFVoxelGrid::getBlockPosition(unsigned int index) const
{
    //x, y, z in terms of the grid
    const unsigned int x = index % getGridWidth();
    const unsigned int y = (index / (getGridWidth() * getGridLength())) % getGridHeight();
    const unsigned int z = (index / getGridWidth()) % getGridLength();

    //add the 0.5 times w/h/l since we want the grid[0] bottom left vertex to be at origin. The entire grid is in quadrant 1.
    return Point3D(x * getBoxWidth() + 0.5f * getBoxWidth(),
        y * getBoxHeight() + 0.5f * getBoxHeight(),
        z * getBoxLength() + 0.5f * getBoxLength());
}

Point3D DFVoxelGrid::getFloorPosition(unsigned int index) const
{
    // Get block position and offset the y downwards(negative y)
    Point3D temp = getBlockPosition(index);
    temp.y -= getBoxHeight() * 0.5f - getFloorHeight() * 0.5f;
    return temp;
}

unsigned int DFVoxelGrid::getGridCount() const
{
    return getGridWidth() * getGridHeight() * getGridLength();
}

unsigned int DFVoxelGrid::getGridWidth() const
{
    return grid_width;
}

unsigned int DFVoxelGrid::getGridHeight() const
{
    return grid_height;
}

unsigned int DFVoxelGrid::getGridLength() const
{
    return grid_length;
}

float DFVoxelGrid::getBoxWidth() const
{
    return box.getWidth();
}

float DFVoxelGrid::getBoxHeight() const
{
    return box.getHeight();
}

float DFVoxelGrid::getBoxLength() const
{
    return box.getLength();
}

float DFVoxelGrid::getFloorHeight() const
{
    return floor_height;
}

void DFVoxelGrid::setGridWidth(unsigned int width)
{
    grid_width = width;
}

void DFVoxelGrid::setGridHeight(unsigned int height)
{
    grid_height = height;
}

void DFVoxelGrid::setGridLength(unsigned int length)
{
    grid_length = length;
}

void DFVoxelGrid::setGridWidthLengthHeight(unsigned int width, unsigned int height, unsigned int length)
{
    setGridWidth(width);
    setGridHeight(height);
    setGridLength(length);
}

void DFVoxelGrid::setBoxWidth(float width)
{
    box.setWidth(width);
}

void DFVoxelGrid::setBoxHeight(float height)
{
    box.setHeight(height);
}

void DFVoxelGrid::setBoxLength(float length)
{
    box.setLength(length);
}

void DFVoxelGrid::setBoxWidthLengthHeight(float width, float height, float length)
{
    box.setWidthHeightLength(width, height, length);
}

void DFVoxelGrid::setFloorHeight(float height)
{
    floor_height = height;
}

bool DFVoxelGrid::isBottomSide(unsigned int index) const
{
    if (grid_height == 1)
    {
        return true;
    }

    unsigned int layer_size = grid_width * grid_length;

    assert(index < grid_width * grid_height * grid_length);

    if (index < layer_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DFVoxelGrid::isTopSide(unsigned int index) const
{
    if (grid_height == 1)
    {
        return true;
    }

    unsigned int layer_size = grid_width * grid_length;

    assert(index < grid_width * grid_height * grid_length);

    if (index >= layer_size * (grid_height - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DFVoxelGrid::isLeftSide(unsigned int index) const
{
    if (grid_width == 1)
    {
        return true;
    }

    assert(index < grid_width * grid_height * grid_length);

    if (index % grid_width == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DFVoxelGrid::isRightSide(unsigned int index) const
{
    if (grid_width == 1)
    {
        return true;
    }

    assert(index < grid_width * grid_height * grid_length);

    if (index % grid_width == grid_width - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DFVoxelGrid::isFrontSide(unsigned int index) const
{
    //if on +z side
    if (grid_length == 1)
    {
        return true;
    }

    assert(index < grid_width * grid_height * grid_length);

    if ((index / grid_width) % grid_length == grid_length - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DFVoxelGrid::isBackSide(unsigned int index) const
{
    //if -z side is showing
    if (grid_length == 1)
    {
        return true;
    }

    assert(index < grid_width * grid_height * grid_length);

    if ((index / grid_width) % grid_length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int DFVoxelGrid::getIndexDown(unsigned int index) const
{
    assert(index < grid_width * grid_height * grid_length);

    if (isBottomSide(index))
    {
        return index;
    }
    else
    {
        return index - grid_width * grid_length;
    }
}

unsigned int DFVoxelGrid::getIndexUp(unsigned int index) const
{
    assert(index < grid_width * grid_height * grid_length);

    if (isTopSide(index))
    {
        return index;
    }
    else
    {
        return index + grid_width * grid_length;
    }
}

unsigned int DFVoxelGrid::getIndexLeft(unsigned int index) const
{
    assert(index < grid_width * grid_height * grid_length);

    if (isLeftSide(index))
    {
        return index;
    }
    else
    {
        return index - 1;
    }
}

unsigned int DFVoxelGrid::getIndexRight(unsigned int index) const
{
    assert(index < grid_width * grid_height * grid_length);

    if (isRightSide(index))
    {
        return index;
    }
    else
    {
        return index + 1;
    }
}

unsigned int DFVoxelGrid::getIndexFront(unsigned int index) const
{
    assert(index < grid_width * grid_height * grid_length);

    if (isFrontSide(index))
    {
        return index;
    }
    else
    {
        return index + grid_width;
    }
}

unsigned int DFVoxelGrid::getIndexBack(unsigned int index) const
{
    assert(index < grid_width * grid_height * grid_length);

    if (isBackSide(index))
    {
        return index;
    }
    else
    {
        return index - grid_width;
    }
}
