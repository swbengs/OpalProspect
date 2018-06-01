#include "NormalBox.hpp"

NormalBox::NormalBox()
{
    front_normal.setXYZ(0.0f, 0.0f, 0.0f);
    back_normal.setXYZ(0.0f, 0.0f, 0.0f);
    left_normal.setXYZ(0.0f, 0.0f, 0.0f);
    right_normal.setXYZ(0.0f, 0.0f, 0.0f);
    top_normal.setXYZ(0.0f, 0.0f, 0.0f);
    bottom_normal.setXYZ(0.0f, 0.0f, 0.0f);
}

void NormalBox::fillNormalFace(NormalFace& front_face, NormalFace& back_face, NormalFace& left_face, NormalFace& right_face, NormalFace& top_face, NormalFace& bottom_face) const
{
    //front back left right top bottom
    front_face.setNormal(getFrontNormal(), getFrontNormal(), getFrontNormal(), getFrontNormal());
    back_face.setNormal(getBackNormal(), getBackNormal(), getBackNormal(), getBackNormal());
    left_face.setNormal(getLeftNormal(), getLeftNormal(), getLeftNormal(), getLeftNormal());
    right_face.setNormal(getRightNormal(), getRightNormal(), getRightNormal(), getRightNormal());
    top_face.setNormal(getTopNormal(), getTopNormal(), getTopNormal(), getTopNormal());
    bottom_face.setNormal(getBottomNormal(), getBottomNormal(), getBottomNormal(), getBottomNormal());
}

//gets
const Point3D& NormalBox::getFrontNormal() const
{
    return front_normal;
}

const Point3D& NormalBox::getBackNormal() const
{
    return back_normal;
}

const Point3D& NormalBox::getLeftNormal() const
{
    return left_normal;
}

const Point3D& NormalBox::getRightNormal() const
{
    return right_normal;
}

const Point3D& NormalBox::getTopNormal() const
{
    return top_normal;
}

const Point3D& NormalBox::getBottomNormal() const
{
    return bottom_normal;
}

//sets
void NormalBox::setFrontNormal(const Point3D& normal)
{
    front_normal = normal;
}

void NormalBox::setBackNormal(const Point3D& normal)
{
    back_normal = normal;
}

void NormalBox::setLeftNormal(const Point3D& normal)
{
    left_normal = normal;
}

void NormalBox::setRightNormal(const Point3D& normal)
{
    right_normal = normal;
}

void NormalBox::setTopNormal(const Point3D& normal)
{
    top_normal = normal;
}

void NormalBox::setBottomNormal(const Point3D& normal)
{
    bottom_normal = normal;
}

void NormalBox::setNormal(const Point3D& front, const Point3D& back, const Point3D& left, const Point3D& right, const Point3D& top, const Point3D& bottom)
{
    front_normal = front;
    back_normal = back;
    left_normal = left;
    right_normal = right;
    top_normal = top;
    bottom_normal = bottom;
}
