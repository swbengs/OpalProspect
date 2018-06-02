#pragma once

#include <vector>
#include "CenterRectangle.hpp"

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

//Creates a grid in the first quadrant with a given width and height. The first rectangle's bottom left will be at 0,0. The last rectangle will be the furthest top right. All rectangles are of equal size.

class Grid2D
{
public:
    Grid2D();

    void create(); //create the grid. Any previous grid is deleted and only the new one will exist.

    //gets
    int getGridWidth() const;
    int getGridHeight() const;
    float getRectangleWidth() const;
    float getRectangleHeight() const;
    const CenterRectangle& getRectangle(int index) const;
    //sets
    void setGridWidth(int width);
    void setGridHeight(int height);
    void setRectangleWidth(float width);
    void setRectangleHeight(float height);

private:
    std::vector<CenterRectangle> grid;
    int grid_width;
    int grid_height;
    float rectangle_width;
    float rectangle_height;
    
    void fillWidthHeight(int size); //fills entire grid rectangle height and width
};
