#pragma once

/*
Class representing a color. It is stored as floats but also accepts the standard 0-255 color range as input
*/

class Color
{
public:
    Color();
    Color(float red, float green, float blue, float alpha);

    //gets
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    float getAlpha() const;
    //sets
    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);
    void setAlpha(float alpha);
    void set(float red, float green, float blue, float alpha);

    void setRed(char red);
    void setGreen(char green);
    void setBlue(char blue);
    void setAlpha(char alpha);
    void set(char red, char green, char blue, char alpha);

private:
    float r;
    float g;
    float b;
    float a;

    float convert(char color); //take a 0 to 255 representation and make it into the range of 0.0 to 1.0
};
