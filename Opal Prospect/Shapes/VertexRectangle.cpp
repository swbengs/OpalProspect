#include "VertexRectangle.hpp"

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

VertexRectangle::VertexRectangle()
{
    is_CCW = true;
}

VertexRectangle::VertexRectangle(bool isCCW)
{
    is_CCW = isCCW;
}

void VertexRectangle::fillVertexIndexed(std::array<float, 16> &data) const
{
    size_t n = 0;
    Point2D bottom_left = getBottomLeft();
    Point2D bottom_right = getBottomRight();
    Point2D top_left = getTopLeft();
    Point2D top_right = getTopRight();

    //bottom left
    data[n++] = bottom_left.x;
    data[n++] = bottom_left.y;
    data[n++] = 0.0f;; //z
    data[n++] = 1.0f; //w

    //bottom right
    data[n++] = bottom_right.x;
    data[n++] = bottom_right.y;
    data[n++] = 0.0f;
    data[n++] = 1.0f;

    //top left
    data[n++] = top_left.x;
    data[n++] = top_left.y;
    data[n++] = 0.0f;
    data[n++] = 1.0f;

    //top right
    data[n++] = top_right.x;
    data[n++] = top_right.y;
    data[n++] = 0.0f;
    data[n] = 1.0f;
}

void VertexRectangle::fillIndex(size_t start, std::array<unsigned int, 6> &data) const
{
    //fills in 6 index but only needs 4
    //index 0 is bottom left, 1 is bottom right, 2 is top left, 3 is top right

    size_t n = 0;
    size_t offset = start * 4; //each new rectangle starts at n*4 index

    if (getIsCCW())
    {
        //triangle 1 BL BR TL
        data[n++] = 0 + offset;
        data[n++] = 1 + offset;
        data[n++] = 2 + offset;

        //triangle 2 TL BR TR
        data[n++] = 2 + offset;
        data[n++] = 1 + offset;
        data[n] = 3 + offset;
    }
    else
    {
        //triangle 1 TL BR BL
        data[n++] = 2 + offset;
        data[n++] = 1 + offset;
        data[n++] = 0 + offset;

        //triangle 2 BL BR TR
        data[n++] = 0 + offset;
        data[n++] = 1 + offset;
        data[n] = 3 + offset;
    }
}

//gets
bool VertexRectangle::getIsCCW() const
{
    return is_CCW;
}

//sets
void VertexRectangle::setIsCCW(bool isCCW)
{
    is_CCW = isCCW;
}
