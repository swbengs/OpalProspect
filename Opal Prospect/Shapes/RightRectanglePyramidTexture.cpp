#include "RightRectanglePyramidTexture.hpp"

//std lib includes

//other includes

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

RightRectanglePyramidTexture::RightRectanglePyramidTexture()
{
    setTextureNumber(0);
}

void RightRectanglePyramidTexture::fillTextureTriangleFace(TextureTriangle& front_triangle, TextureTriangle& back_triangle, TextureTriangle& left_triangle, TextureTriangle& right_triangle, TextureFace& bottom_face) const
{
    Point3D bottom_left, bottom_right, top_left, top_right;

    fillUVPoints(bottom_left, bottom_right, top_left, top_right);
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, text_num_bottom);
    bottom_face.setUV(bottom_left, bottom_right, top_left, top_right);

    fillTriangleUVTextureNumber(bottom_left, bottom_right, top_left, text_num_front);
    front_triangle.setABCUV(bottom_left, bottom_right, top_left);
    fillTriangleUVTextureNumber(bottom_left, bottom_right, top_left, text_num_back);
    back_triangle.setABCUV(bottom_left, bottom_right, top_left);
    fillTriangleUVTextureNumber(bottom_left, bottom_right, top_left, text_num_left);
    left_triangle.setABCUV(bottom_left, bottom_right, top_left);
    fillTriangleUVTextureNumber(bottom_left, bottom_right, top_left, text_num_right);
    right_triangle.setABCUV(bottom_left, bottom_right, top_left);
}

unsigned int RightRectanglePyramidTexture::getFrontTextureNumber() const
{
    return text_num_front;
}

unsigned int RightRectanglePyramidTexture::getBackTextureNumber() const
{
    return text_num_back;
}

unsigned int RightRectanglePyramidTexture::getLeftTextureNumber() const
{
    return text_num_left;
}

unsigned int RightRectanglePyramidTexture::getRightTextureNumber() const
{
    return text_num_right;
}

unsigned int RightRectanglePyramidTexture::getBottomTextureNumber() const
{
    return text_num_bottom;
}

void RightRectanglePyramidTexture::setTextureNumber(unsigned int texture)
{
    text_num_front = texture;
    text_num_back = texture;
    text_num_left = texture;
    text_num_right = texture;
    text_num_bottom = texture;
}

void RightRectanglePyramidTexture::fillUVPoints(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right) const
{
    float min = 0.0f;
    float max = 1.0f;

    bottom_left.x = min;
    bottom_left.y = min;
    bottom_right.x = max;
    bottom_right.y = min;
    top_left.x = min;
    top_left.y = max;
    top_right.x = max;
    top_right.y = max;
}

void RightRectanglePyramidTexture::fillUVTextureNumber(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right, unsigned int texture_number) const
{
    bottom_left.z = (static_cast<float>(texture_number));
    bottom_right.z = (static_cast<float>(texture_number));
    top_left.z = (static_cast<float>(texture_number));
    top_right.z = (static_cast<float>(texture_number));
}

void RightRectanglePyramidTexture::fillTriangleUVPoints(Point3D & bottom_left, Point3D & bottom_right, Point3D & top_left) const
{
    float min = 0.0f;
    float max = 1.0f;

    bottom_left.x = min;
    bottom_left.y = min;
    bottom_right.x = max;
    bottom_right.y = min;
    top_left.x = min;
    top_left.y = max;
}

void RightRectanglePyramidTexture::fillTriangleUVTextureNumber(Point3D & bottom_left, Point3D & bottom_right, Point3D & top_left, unsigned int texture_number) const
{
    bottom_left.z = (static_cast<float>(texture_number));
    bottom_right.z = (static_cast<float>(texture_number));
    top_left.z = (static_cast<float>(texture_number));
}

