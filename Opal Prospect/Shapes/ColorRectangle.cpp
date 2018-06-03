#include "ColorRectangle.hpp"

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
