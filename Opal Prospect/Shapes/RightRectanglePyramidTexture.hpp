#pragma once
//parent
#include "RightRectanglePyramidVertex.hpp"
//other includes
#include "TextureFace.hpp"
#include "TextureTriangle.hpp"

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
Description: This structure is still not fully decided on. Give a basic description of what this class does at a minimum. More detail is always welcome.
*/

class RightRectanglePyramidTexture : public RightRectanglePyramidVertex
{
public:
    RightRectanglePyramidTexture();

    void fillTextureTriangleFace(TextureTriangle& front_triangle, TextureTriangle& back_triangle, TextureTriangle& left_triangle, TextureTriangle& right_triangle, TextureFace& bottom_face) const;
    //gets
    unsigned int getFrontTextureNumber() const;
    unsigned int getBackTextureNumber() const;
    unsigned int getLeftTextureNumber() const;
    unsigned int getRightTextureNumber() const;
    unsigned int getBottomTextureNumber() const;
    //sets
    void setTextureNumber(unsigned int texture); //sets all of them to the same texture number

private:
    unsigned int text_num_front; //following 5 are which texture within an atlas to use. Can all be the same or all be something different
    unsigned int text_num_back;
    unsigned int text_num_left;
    unsigned int text_num_right;
    unsigned int text_num_bottom;

    void fillUVPoints(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right) const;
    void fillUVTextureNumber(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right, unsigned int texture_number) const;
    void fillTriangleUVPoints(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left) const;
    void fillTriangleUVTextureNumber(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, unsigned int texture_number) const;
};

