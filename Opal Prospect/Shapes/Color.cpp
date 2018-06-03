#include "Color.hpp"

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

Color::Color()
{
    set(0.0f, 0.0f, 0.0f, 0.0f);
}

Color::Color(float red, float green, float blue, float alpha)
{
    set(red, green, blue, alpha);
}

//gets
float Color::getRed() const
{
    return r;
}

float Color::getGreen() const
{
    return g;
}

float Color::getBlue() const
{
    return b;
}

float Color::getAlpha() const
{
    return a;
}

//sets
void Color::setRed(float red)
{
    r = red;
}

void Color::setGreen(float green)
{
    g = green;
}

void Color::setBlue(float blue)
{
    b = blue;
}

void Color::setAlpha(float alpha)
{
    a = alpha;
}

void Color::set(float red, float green, float blue, float alpha)
{
    setRed(red);
    setGreen(green);
    setBlue(blue);
    setAlpha(alpha);
}

void Color::setRed(char red)
{
    r = convert(red);
}

void Color::setGreen(char green)
{
    g = convert(green);
}

void Color::setBlue(char blue)
{
    b = convert(blue);
}

void Color::setAlpha(char alpha)
{
    a = convert(alpha);
    
}

void Color::set(char red, char green, char blue, char alpha)
{
    setRed(red);
    setGreen(green);
    setBlue(blue);
    setAlpha(alpha);
}

//privates
float Color::convert(char color)
{
    return (float(color) / 255.0f);
}
