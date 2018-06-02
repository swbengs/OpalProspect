#pragma once

#include <array>

#include "Rectangle.hpp"

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
Class for a rectangle with vertex points and an element array for indexed drawing
*/

class VertexRectangle : public Rectangle
{
public:
    VertexRectangle();
    VertexRectangle(bool isCCW);

    //4 points * 4 floats each
    void fillVertexIndexed(std::array<float, 16> &data) const; //fills in 4d coordinates z is always 0.0 and w is 1.0
    //2 triangles * 3 index each
    void fillIndex(size_t start, std::array<unsigned int, 6> &data) const;

    //gets
    bool getIsCCW() const;
    //sets
    void setIsCCW(bool isCCW);
private:
    bool is_CCW;
};
