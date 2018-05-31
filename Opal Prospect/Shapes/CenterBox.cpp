#include "Shapes\CenterBox.hpp"

CenterBox::CenterBox()
{
    setWidthHeightLength(0.0f, 0.0f, 0.0f);
    setXYZ(0.0f, 0.0f, 0.0f);
}

CenterBox::CenterBox(const Box& box) : Box(box)
{
    setXYZ(0.0f, 0.0f, 0.0f);
}

//gets
float CenterBox::getX() const
{
    return center.x;
}

float CenterBox::getY() const
{
    return center.y;
}

float CenterBox::getZ() const
{
    return center.z;
}

const Point3D& CenterBox::getXYZ() const
{
    return center;
}

Point3D CenterBox::getLiteralFrontBottomLeft() const
{
    Point3D point = getFrontBottomLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralFrontBottomRight() const
{
    Point3D point = getFrontBottomRight();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralFrontTopLeft() const
{
    Point3D point = getFrontTopLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralFrontTopRight() const
{
    Point3D point = getFrontTopRight();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackBottomLeft() const
{
    Point3D point = getBackBottomLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackBottomRight() const
{
    Point3D point = getBackBottomRight();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackTopLeft() const
{
    Point3D point = getBackTopLeft();
    addCenter(point);

    return point;
}

Point3D CenterBox::getLiteralBackTopRight() const
{
    Point3D point = getBackTopRight();
    addCenter(point);

    return point;
}

//sets
void CenterBox::setX(float X)
{
    center.x = X;
}

void CenterBox::setY(float Y)
{
    center.y = Y;
}

void CenterBox::setZ(float Z)
{
    center.z = Z;
}

void CenterBox::setXYZ(float X, float Y, float Z)
{
    center.setXYZ(X, Y, Z);
}

void CenterBox::setXYZ(const Point3D& point)
{
    center = point;
}

//privates
void CenterBox::addCenter(Point3D& point) const
{
    point.setXYZ(point.x + getX(), point.y + getY(), point.z + getZ());
}
