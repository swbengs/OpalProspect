#include "TextureFace.hpp"

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

TextureFace::TextureFace()
{

}

void TextureFace::scaleUV(unsigned int u_scale, unsigned int v_scale)
{
    bottom_left_uv.scale(u_scale, v_scale, 1);
    bottom_right_uv.scale(u_scale, v_scale, 1);
    top_left_uv.scale(u_scale, v_scale, 1);
    top_right_uv.scale(u_scale, v_scale, 1);
}

//gets
Point3D TextureFace::getBottomLeftUV() const
{
    return bottom_left_uv;
}

Point3D TextureFace::getBottomRightUV() const
{
    return bottom_right_uv;
}

Point3D TextureFace::getTopLeftUV() const
{
    return top_left_uv;
}

Point3D TextureFace::getTopRightUV() const
{
    return top_right_uv;
}

//sets
void TextureFace::setBottomLeftUV(Point3D uv)
{
    bottom_left_uv = uv;
}

void TextureFace::setBottomRightUV(Point3D uv)
{
    bottom_right_uv = uv;
}

void TextureFace::setTopLeftUV(Point3D uv)
{
    top_left_uv = uv;
}

void TextureFace::setTopRightUV(Point3D uv)
{
    top_right_uv = uv;
}

void TextureFace::setUV(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right)
{
    bottom_left_uv = bottom_left;
    bottom_right_uv = bottom_right;
    top_left_uv = top_left;
    top_right_uv = top_right;
}
