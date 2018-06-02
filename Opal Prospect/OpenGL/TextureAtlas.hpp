#pragma once

#include "Texture.hpp"

#include "Shapes\Grid2D.hpp"
#include "Shapes\VertexRectangle.hpp"

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
Texture atlas class that uses a borderless atlas. All rectangles are the same size.
*/

class TextureAtlas : public Texture
{
public:
    void fillUVIndexedRectangle(int index, std::array<float, 8> &data) const;
    //fills in the given array with the 6 inputed texture numbers
    void fillUVIndexedBox(std::array<float, 48> &data, unsigned int front, unsigned int back, unsigned int left, unsigned int right, unsigned int top, unsigned int bottom) const;

    void generateAtlas(); //fills in the atlas

    //gets
    int getAtlasWidth() const;
    int getAtlasHeight() const;
    int getAtlasSize() const;
    float getRectangleWidth() const;
    float getRectangleHeight() const;
    const VertexRectangle& TextureAtlas::getVertexRectangle() const;
    //sets
    void setRectangleWidth(float width);
    void setRectangleHeight(float height);

private:
    Grid2D grid;
    VertexRectangle vertex;

    void fillFaceTexture(const CenterRectangle &rect, size_t start, float* data) const;
    bool checkBounds(int index) const;
};