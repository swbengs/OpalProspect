#include "Grid3D.hpp"

#include <iostream>

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

Grid3D::Grid3D()
{
    grid_width = 0;
    grid_height = 0;
    grid_length = 0;
}

void Grid3D::create()
{
    int total_size = getGridWidth() * getGridHeight() * getGridLength();
    int layer_size = getGridWidth() * getGridLength();

    grid.resize(total_size);

    //stack of 2D grids X and Z define the width and height and Y defines each layer

    for (int layer = 0; layer < getGridHeight(); layer++)
    {
        int layer_offset = layer_size * layer;

        for (int column = 0; column < getGridLength(); column++)
        {
            int column_offset = getGridWidth() * column;

            for (int row = 0; row < getGridWidth(); row++)
            {
                grid.at(row + column_offset + layer_offset).setXYZ(row * getBoxWidth() + 0.5f * getBoxWidth(), layer * getBoxHeight() + 0.5f * getBoxHeight(), column * getBoxLength() + 0.5f * getBoxLength());
            }
        }
    }

    /*
    for (int n = 0; n < getGridHeight(); n++)
    {
    int row = n * getGridWidth();

    for (int m = 0; m < getGridWidth(); m++)
    {
    grid.at(m + row).setX(m * getBoxWidth() + 0.5f * getBoxWidth());
    grid.at(m + row).setY(n * getBoxHeight() + 0.5f * getBoxHeight());
    }
    }
    */
}

//gets
int Grid3D::getGridSize() const
{
    return getGridWidth() * getGridHeight() * getGridLength();
}

int Grid3D::getGridWidth() const
{
    return grid_width;
}

int Grid3D::getGridHeight() const
{
    return grid_height;
}

int Grid3D::getGridLength() const
{
    return grid_length;
}

float Grid3D::getBoxWidth() const
{
    return box.getWidth();
}

float Grid3D::getBoxHeight() const
{
    return box.getHeight();
}

float Grid3D::getBoxLength() const
{
    return box.getLength();
}

CenterBox Grid3D::getBox(int index) const
{
    CenterBox result(box);
    result.setXYZ(grid.at(index));

    return result;
}

//sets
void Grid3D::setGridWidth(int width)
{
    grid_width = width;
}

void Grid3D::setGridHeight(int height)
{
    grid_height = height;
}

void Grid3D::setGridLength(int length)
{
    grid_length = length;
}

void Grid3D::setBoxWidth(float width)
{
    box.setWidth(width);
}

void Grid3D::setBoxHeight(float height)
{
    box.setHeight(height);
}

void Grid3D::setBoxLength(float length)
{
    box.setLength(length);
}
