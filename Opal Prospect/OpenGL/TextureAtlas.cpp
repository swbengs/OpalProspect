#include "TextureAtlas.hpp"

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

void TextureAtlas::fillUVIndexedRectangle(int index, std::array<float, 8> &data) const
{
    int good_index = 0;
    if (checkBounds(index)) //ensure the given index is within the range of our atlas
    {
        good_index = index;
    }
    
    fillFaceTexture(grid.getRectangle(good_index), 0, data.data());
}

void TextureAtlas::fillUVIndexedBox(std::array<float, 48> &data, unsigned int front, unsigned int back, unsigned int left, unsigned int right, unsigned int top, unsigned int bottom) const
{
    int good_index = 0;

    //order is front, back, left, right, top, and bottom

    if (checkBounds(front))
    {
        good_index = front;
    }
    fillFaceTexture(grid.getRectangle(good_index), 0, data.data());

    if (checkBounds(back))
    {
        good_index = back;
    }
    fillFaceTexture(grid.getRectangle(good_index), 8, data.data());

    if (checkBounds(left))
    {
        good_index = left;
    }
    fillFaceTexture(grid.getRectangle(good_index), 16, data.data());

    if (checkBounds(right))
    {
        good_index = right;
    }
    fillFaceTexture(grid.getRectangle(good_index), 24, data.data());

    if (checkBounds(top))
    {
        good_index = top;
    }
    fillFaceTexture(grid.getRectangle(good_index), 32, data.data());

    if (checkBounds(bottom))
    {
        good_index = bottom;
    }
    fillFaceTexture(grid.getRectangle(good_index), 40, data.data());
}

void TextureAtlas::generateAtlas()
{
    //texture width / rectangle width = how many fit horizontal
    //repeat with height for vertical size
    int Width = int(getWidth() / vertex.getWidth()); //vertex and grid share the same rectangle width and height
    int Height = int(getHeight() / vertex.getHeight());

    grid.setGridWidth(Width);
    grid.setGridHeight(Height);
    grid.create();
}

//gets
int TextureAtlas::getAtlasWidth() const
{
    return grid.getGridWidth();
}

int TextureAtlas::getAtlasHeight() const
{
    return grid.getGridHeight();
}

int TextureAtlas::getAtlasSize() const
{
    return getAtlasWidth() * getAtlasHeight();
}

float TextureAtlas::getRectangleWidth() const
{
    return grid.getRectangleWidth();
}

float TextureAtlas::getRectangleHeight() const
{
    return grid.getRectangleHeight();
}

const VertexRectangle& TextureAtlas::getVertexRectangle() const
{
    return vertex;
}

//sets
void TextureAtlas::setRectangleWidth(float Width)
{
    vertex.setWidth(Width);
    grid.setRectangleWidth(Width);
}

void TextureAtlas::setRectangleHeight(float Height)
{
    vertex.setHeight(Height);
    grid.setRectangleHeight(Height);
}

//privates
void TextureAtlas::fillFaceTexture(const CenterRectangle &rect, size_t start, float* data) const
{
    Point2D point;

    float xRatio = 1.0f / float(getWidth()); //converts an x cordinate to the range 0 to 1
    float yRatio = 1.0f / float(getHeight()); //converts an y cordinate to the range 0 to 1
    size_t n = start;

    //bottom left
    point = rect.getLiteralBottomLeft();
    data[n++] = point.x * xRatio;
    data[n++] = point.y * yRatio;

    //bottom right
    point = rect.getLiteralBottomRight();
    data[n++] = point.x * xRatio;
    data[n++] = point.y * yRatio;

    //top left
    point = rect.getLiteralTopLeft();
    data[n++] = point.x * xRatio;
    data[n++] = point.y * yRatio;

    //top right
    point = rect.getLiteralTopRight();
    data[n++] = point.x * xRatio;
    data[n] = point.y * yRatio;
}

bool TextureAtlas::checkBounds(int index) const
{
    return (index < getAtlasSize());
}
