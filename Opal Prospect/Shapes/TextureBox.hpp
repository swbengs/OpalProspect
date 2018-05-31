#pragma once

#include "VertexBox.hpp"

#include "TextureFace.hpp"
#include "Point3D.hpp"

class TextureBox : public VertexBox
{
public:
    TextureBox();

    void fillTextureFace(TextureFace& front_face, TextureFace& back_face, TextureFace& left_face, TextureFace& right_face, TextureFace& top_face, TextureFace& bottom_face) const;

    //gets
    unsigned int getFrontTextureNumber() const;
    unsigned int getBackTextureNumber() const;
    unsigned int getLeftTextureNumber() const;
    unsigned int getRightTextureNumber() const;
    unsigned int getTopTextureNumber() const;
    unsigned int getBottomTextureNumber() const;
    //sets
    void setTextureNumber(unsigned int texture); //sets all of them to the same texture number

    void setFrontTextureNumber(unsigned int texture);
    void setBackTextureNumber(unsigned int texture);
    void setLeftTextureNumber(unsigned int texture);
    void setRightTextureNumber(unsigned int texture);
    void setTopTextureNumber(unsigned int texture);
    void setBottomTextureNumber(unsigned int texture);

private:
    unsigned int text_num_front; //following 6 are which texture within an atlas to use. Can all be the same or all be something different
    unsigned int text_num_back;
    unsigned int text_num_left;
    unsigned int text_num_right;
    unsigned int text_num_top;
    unsigned int text_num_bottom;

    void fillUVPoints(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right) const;
    void TextureBox::fillUVTextureNumber(Point3D& bottom_left, Point3D& bottom_right, Point3D& top_left, Point3D& top_right, unsigned int texture_number) const;
};
