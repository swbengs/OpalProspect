#include "NormalFace.hpp"

NormalFace::NormalFace()
{

}

//gets
Point3D NormalFace::getBottomLeftNormal() const
{
    return bottom_left_normal;
}

Point3D NormalFace::getBottomRightNormal() const
{
    return bottom_right_normal;
}

Point3D NormalFace::getTopLeftNormal() const
{
    return top_left_normal;
}

Point3D NormalFace::getTopRightNormal() const
{
    return top_right_normal;
}

//sets
void NormalFace::setBottomLeftNormal(Point3D normal)
{
    bottom_left_normal = normal;
}

void NormalFace::setBottomRightNormal(Point3D normal)
{
    bottom_right_normal = normal;
}

void NormalFace::setTopLeftNormal(Point3D normal)
{
    top_left_normal = normal;
}

void NormalFace::setTopRightNormal(Point3D normal)
{
    top_right_normal = normal;
}

void NormalFace::setNormal(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right)
{
    bottom_left_normal = bottom_left;
    bottom_right_normal = bottom_right;
    top_left_normal = top_left;
    top_right_normal = top_right;
}
