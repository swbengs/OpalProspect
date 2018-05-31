#include "TextureFace.hpp"

TextureFace::TextureFace()
{

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
