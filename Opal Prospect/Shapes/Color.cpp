#include "Color.hpp"

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
