#include "TextureBox.hpp"

TextureBox::TextureBox()
{
    setTextureNumber(0);
}

void TextureBox::fillTextureFace(TextureFace& front_face, TextureFace& back_face, TextureFace& left_face, TextureFace& right_face, TextureFace& top_face, TextureFace& bottom_face) const
{
    Point3D bottom_left, bottom_right, top_left, top_right;

    fillUVPoints(bottom_left, bottom_right, top_left, top_right);

    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getFrontTextureNumber());
    front_face.setUV(bottom_left, bottom_right, top_left, top_right);

    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getBackTextureNumber());
    back_face.setUV(bottom_left, bottom_right, top_left, top_right);

    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getLeftTextureNumber());
    left_face.setUV(bottom_left, bottom_right, top_left, top_right);

    fillUVTextureNumber(bottom_left, bottom_right, top_left, top_right, getRightTextureNumber());
    right_face.setUV(bottom_left, bottom_right, top_left, top_right);

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
void TextureBox::fillUVPoints(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right) const
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

void TextureBox::fillUVTextureNumber(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right, unsigned int texture_number) const
{
    bottom_left.z = (static_cast<float>(texture_number));
    bottom_right.z = (static_cast<float>(texture_number));
    top_left.z = (static_cast<float>(texture_number));
    top_right.z = (static_cast<float>(texture_number));
}
