#pragma once

//std lib includes

//other includes
#include "Point3D.hpp"
#include "Box.hpp"

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

/*
Description: Class to store dwarf fortress style voxel grid
*/


class DFVoxelGrid
{
public:
    bool isBottomSide(unsigned int index) const;
    bool isTopSide(unsigned int index) const;
    bool isLeftSide(unsigned int index) const;
    bool isRightSide(unsigned int index) const;
    bool isFrontSide(unsigned int index) const;
    bool isBackSide(unsigned int index) const;

    unsigned int getIndexDown(unsigned int index) const;
    unsigned int getIndexUp(unsigned int index) const;
    unsigned int getIndexLeft(unsigned int index) const;
    unsigned int getIndexRight(unsigned int index) const;
    unsigned int getIndexFront(unsigned int index) const;
    unsigned int getIndexBack(unsigned int index) const;

    //gets
    Point3D getBlockPosition(unsigned int index) const;
    Point3D getFloorPosition(unsigned int index) const;

    unsigned int getGridCount() const;
    unsigned int getGridWidth() const;
    unsigned int getGridHeight() const;
    unsigned int getGridLength() const;

    float getBoxWidth() const;
    float getBoxHeight() const;
    float getBoxLength() const;
    float getFloorHeight() const;

    //sets
    void setGridWidth(unsigned int width);
    void setGridHeight(unsigned int height);
    void setGridLength(unsigned int length);
    void setGridWidthLengthHeight(unsigned int width, unsigned int height, unsigned int length);

    void setBoxWidth(float width);
    void setBoxHeight(float height);
    void setBoxLength(float length);
    void setBoxWidthLengthHeight(float width, float height, float length);
    void setFloorHeight(float height);

private:
    Box box;
    float floor_height; // Floor width and length will match 

    unsigned int grid_width;
    unsigned int grid_height;
    unsigned int grid_length;
};

