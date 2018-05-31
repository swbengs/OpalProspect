#pragma once

#include "VertexRectangle.hpp"
#include "Color.hpp"

/*
Class for a colored rectangle of a single color
*/

class ColorRectangle : public VertexRectangle
{
public:
    void fillColor(std::array<float, 24> &data) const;
    void fillColorIndexed(std::array<float, 16> &data) const;

    //gets
    const Color& getColor() const;
    //sets
    void setRGBA(float red, float green, float blue, float alpha);
    void setRGBA(char red, char green, char blue, char alpha);
private:
    Color color;
};
