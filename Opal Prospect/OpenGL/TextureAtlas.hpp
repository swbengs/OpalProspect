#pragma once

#include "Texture.hpp"

#include "Shapes\Grid2D.hpp"
#include "Shapes\VertexRectangle.hpp"

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