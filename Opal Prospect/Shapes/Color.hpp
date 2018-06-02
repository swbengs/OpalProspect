#pragma once

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
