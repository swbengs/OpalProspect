#include "Rectangle.hpp"

Rectangle::Rectangle()
{
    setWidthHeight(0.0f, 0.0f);
}

Rectangle::Rectangle(float width, float height)
{
    setWidthHeight(width, height);
}

//gets
float Rectangle::getWidth() const
{
    return hw.x;
}

float Rectangle::getHeight() const
{
    return hw.y;
}

const Point2D& Rectangle::getWidthHeight() const
{
    return hw;
}

Point2D Rectangle::getBottomLeft() const
{
    return Point2D(-0.5f * getWidth(), -0.5f * getHeight());
}

Point2D Rectangle::getBottomRight() const
{
    return Point2D(0.5f * getWidth(), -0.5f * getHeight());
}

Point2D Rectangle::getTopLeft() const
{
    return Point2D(-0.5f * getWidth(), 0.5f * getHeight());
}

Point2D Rectangle::getTopRight() const
{
    return Point2D(0.5f * getWidth(), 0.5f * getHeight());
}

//sets
void Rectangle::setWidth(float width)
{
    hw.x = width;
}

void Rectangle::setHeight(float height)
{
    hw.y = height;
}

void Rectangle::setWidthHeight(float width, float height)
{
    hw.setXY(width, height);
}

void Rectangle::setWidthHeight(const Point2D& point)
{
    hw = point;
}
