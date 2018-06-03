#include "Grid2D.hpp"

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

Grid2D::Grid2D()
{
    grid_width = 0;
    grid_height = 0;
}

void Grid2D::create()
{
    int size = getGridWidth() * getGridHeight();

    grid.resize(size);

    fillWidthHeight(size);

    for (int n = 0; n < getGridHeight(); n++)
    {
        int row = n * getGridWidth();

        for (int m = 0; m < getGridWidth(); m++)
        {
            grid.at(m + row).setX(m * getRectangleWidth() + 0.5f * getRectangleWidth());
            grid.at(m + row).setY(n * getRectangleHeight() + 0.5f * getRectangleHeight());
        }
    }
}

//gets
int Grid2D::getGridWidth() const
{
    return grid_width;
}

int Grid2D::getGridHeight() const
{
    return grid_height;
}

float Grid2D::getRectangleWidth() const
{
    return rectangle_width;
}

float Grid2D::getRectangleHeight() const
{
    return rectangle_height;
}

const CenterRectangle& Grid2D::getRectangle(int index) const
{
    return grid.at(index);
}

//sets
void Grid2D::setGridWidth(int width)
{
    grid_width = width;
}

void Grid2D::setGridHeight(int height)
{
    grid_height = height;
}

void Grid2D::setRectangleWidth(float width)
{
    rectangle_width = width;
}

void Grid2D::setRectangleHeight(float height)
{
    rectangle_height = height;
}

//private
void Grid2D::fillWidthHeight(int size)
{
    for (int n = 0; n < size; n++)
    {
        grid.at(n).setWidth(rectangle_width);
        grid.at(n).setHeight(rectangle_height);
    }
}
