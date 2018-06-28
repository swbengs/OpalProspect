//class header
#include "Grid3DYOffset.hpp"
//std lib includes

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

//class code

Grid3DYOffset::Grid3DYOffset()
{
    grid_width = 0;
    grid_height = 0;
    grid_length = 0;
    y_offset = 0.0f;
}

void Grid3DYOffset::create()
{
    int total_count = getGridWidth() * getGridHeight() * getGridLength();
    int layer_size = getGridWidth() * getGridLength();

    grid.resize(total_count);

    for (unsigned int layer = 0; layer < getGridHeight(); layer++)
    {
        int layer_count_offset = layer_size * layer;
        float layer_offset = layer * getBoxHeight();

        for (unsigned int row = 0; row < getGridLength(); row++)
        {
            int row_count_offset = getGridWidth() * row;
            float row_offset = row * getBoxLength();

            for (unsigned int column = 0; column < getGridWidth(); column++)
            {
                grid.at(column + row_count_offset + layer_count_offset).setXYZ(column * getBoxWidth() + 0.5f * getBoxWidth(), layer_offset + 0.5f * getBoxHeight(), row_offset + 0.5f * getBoxLength());
            }
        }
    }
}

unsigned int Grid3DYOffset::getGridCount() const
{
    return getGridWidth() * getGridHeight() * getGridLength();
}

unsigned int Grid3DYOffset::getGridWidth() const
{
    return grid_width;
}

unsigned int Grid3DYOffset::getGridHeight() const
{
    return grid_height;
}

unsigned int Grid3DYOffset::getGridLength() const
{
    return grid_length;
}

float Grid3DYOffset::getBoxWidth() const
{
    return box.getWidth();
}

float Grid3DYOffset::getBoxHeight() const
{
    return box.getHeight();
}

float Grid3DYOffset::getBoxLength() const
{
    return box.getLength();
}

CenterBox Grid3DYOffset::getBox(unsigned int index) const
{
    CenterBox result(box);
    result.setXYZ(grid.at(index));

    return result;
}

float Grid3DYOffset::getYOffset() const
{
    return y_offset;
}

void Grid3DYOffset::setGridWidth(unsigned int width)
{
    grid_width = width;
}

void Grid3DYOffset::setGridHeight(unsigned int height)
{
    grid_height = height;
}

void Grid3DYOffset::setGridLength(unsigned int length)
{
    grid_length = length;
}

void Grid3DYOffset::setGridWidthLengthHeight(unsigned int width, unsigned int height, unsigned int length)
{
    setGridWidth(width);
    setGridHeight(height);
    setGridLength(length);
}

void Grid3DYOffset::setBoxWidth(float width)
{
    box.setWidth(width);
}

void Grid3DYOffset::setBoxHeight(float height)
{
    box.setHeight(height);
}

void Grid3DYOffset::setBoxLength(float length)
{
    box.setLength(length);
}

void Grid3DYOffset::setBoxWidthLengthHeight(float width, float height, float length)
{
    box.setWidthHeightLength(width, height, length);
}

void Grid3DYOffset::setYOffset(float offset)
{
    y_offset = offset;
}
