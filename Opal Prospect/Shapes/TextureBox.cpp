#include "TextureBox.hpp"

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

TextureBox::TextureBox()
{
    setTextureNumber(0);
}

void TextureBox::fillTextureFace(TextureFace& front_face, TextureFace& back_face, TextureFace& left_face, TextureFace& right_face, TextureFace& top_face, TextureFace& bottom_face) const
{
    Point3D bottom_left, bottom_right, top_left, top_right;
    float x_scaler = getWidth();
    float y_scaler = getHeight();
    float z_scaler = getLength();

    fillUVPoints(bottom_left, bottom_right, top_left, top_right, x_scaler, y_scaler); // Front and back are based on width and height
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getFrontTextureNumber());
    front_face.setUV(bottom_left, bottom_right, top_left, top_right);
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getBackTextureNumber());
    back_face.setUV(bottom_left, bottom_right, top_left, top_right);

    fillUVPoints(bottom_left, bottom_right, top_left, top_right, z_scaler, y_scaler); // Left and right are length and height
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getLeftTextureNumber());
    left_face.setUV(bottom_left, bottom_right, top_left, top_right);
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getRightTextureNumber());
    right_face.setUV(bottom_left, bottom_right, top_left, top_right);

    fillUVPoints(bottom_left, bottom_right, top_left, top_right, x_scaler, z_scaler); // Top and Bottom are width and length
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getTopTextureNumber());
    top_face.setUV(bottom_left, bottom_right, top_left, top_right);
    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getBottomTextureNumber());
    bottom_face.setUV(bottom_left, bottom_right, top_left, top_right);
}

//gets
unsigned int TextureBox::getFrontTextureNumber() const
{
    return text_num_front;
}

unsigned int TextureBox::getBackTextureNumber() const
{
    return text_num_back;
}

unsigned int TextureBox::getLeftTextureNumber() const
{
    return text_num_left;
}

unsigned int TextureBox::getRightTextureNumber() const
{
    return text_num_right;
}

unsigned int TextureBox::getTopTextureNumber() const
{
    return text_num_top;
}

unsigned int TextureBox::getBottomTextureNumber() const
{
    return text_num_bottom;
}

//sets
void TextureBox::setTextureNumber(unsigned int texture)
{
    setFrontTextureNumber(texture);
    setBackTextureNumber(texture);
    setLeftTextureNumber(texture);
    setRightTextureNumber(texture);
    setTopTextureNumber(texture);
    setBottomTextureNumber(texture);
}

void TextureBox::setFrontTextureNumber(unsigned int texture)
{
    text_num_front = texture;
}

void TextureBox::setBackTextureNumber(unsigned int texture)
{
    text_num_back = texture;
}

void TextureBox::setLeftTextureNumber(unsigned int texture)
{
    text_num_left = texture;
}

void TextureBox::setRightTextureNumber(unsigned int texture)
{
    text_num_right = texture;
}

void TextureBox::setTopTextureNumber(unsigned int texture)
{
    text_num_top = texture;
}

void TextureBox::setBottomTextureNumber(unsigned int texture)
{
    text_num_bottom = texture;
}

//private
void TextureBox::fillUVPoints(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right, float u_scaler, float v_scaler) const
{
    //TODO: Make it be based on width, length, and height of the face. 0 will stay 0 but the 1s can be longer to allow repeating and combining faces
    const float min = 0.0f;
    const float max = 1.0f;

    bottom_left.x = min;
    bottom_left.y = min;
    bottom_right.x = max * u_scaler;
    bottom_right.y = min;
    top_left.x = min;
    top_left.y = max * v_scaler;
    top_right.x = max * u_scaler;
    top_right.y = max * v_scaler;
}

void TextureBox::fillUVTextureNumber(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right, unsigned int texture_number) const
{
    bottom_left.z = (static_cast<float>(texture_number));
    bottom_right.z = (static_cast<float>(texture_number));
    top_left.z = (static_cast<float>(texture_number));
    top_right.z = (static_cast<float>(texture_number));
}
