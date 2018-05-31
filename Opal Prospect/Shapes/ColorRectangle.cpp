#include "ColorRectangle.hpp"

void ColorRectangle::fillColor(std::array<float, 24> &data) const
{
    int n = 0;

    //bottom left
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //bottom right
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //top left
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //top left
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //bottom right
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //top right
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n] = color.getAlpha();
}

void ColorRectangle::fillColorIndexed(std::array<float, 16> &data) const
{
    int n = 0;

    //bottom left
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //bottom right
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //top left
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n++] = color.getAlpha();

    //top right
    data[n++] = color.getRed();
    data[n++] = color.getGreen();
    data[n++] = color.getBlue();
    data[n] = color.getAlpha();
}

//gets
const Color& ColorRectangle::getColor() const
{
    return color;
}

//sets
void ColorRectangle::setRGBA(float red, float green, float blue, float alpha)
{
    color.set(red, green, blue, alpha);
}

void ColorRectangle::setRGBA(char red, char green, char blue, char alpha)
{
    color.set(red, green, blue, alpha);
}
