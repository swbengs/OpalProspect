#include "Box.hpp"

Box::Box()
{
    setWidthHeightLength(0.0f, 0.0f, 0.0f);
}

//gets
float Box::getWidth() const
{
    return whl.x;
}

float Box::getHeight() const
{
    return whl.y;
}

float Box::getLength() const
{
    return whl.z;
}

Point3D Box::getWidthHeightLength() const
{
    return whl;
}

Point3D Box::getFrontBottomLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * -0.5f, getLength() * -0.5f);
}

Point3D Box::getFrontBottomRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * -0.5f, getLength() * -0.5f);
}

Point3D Box::getFrontTopLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * 0.5f, getLength() * -0.5f);
}

Point3D Box::getFrontTopRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * 0.5f, getLength() * -0.5f);
}

Point3D Box::getBackBottomLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * -0.5f, getLength() * 0.5f);
}

Point3D Box::getBackBottomRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * -0.5f, getLength() * 0.5f);
}

Point3D Box::getBackTopLeft() const
{
    return Point3D(getWidth() * -0.5f, getHeight() * 0.5f, getLength() * 0.5f);
}

Point3D Box::getBackTopRight() const
{
    return Point3D(getWidth() * 0.5f, getHeight() * 0.5f, getLength() * 0.5f);
}

//sets
void Box::setWidth(float width)
{
    whl.x = width;
}

void Box::setHeight(float height)
{
    whl.y = height;
}

void Box::setLength(float length)
{
    whl.z = length;
}

void Box::setWidthHeightLength(float width, float height, float length)
{
    setWidth(width);
    setHeight(height);
    setLength(length);
}
