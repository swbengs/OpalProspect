#include "CenterRectangle.hpp"

CenterRectangle::CenterRectangle()
{
    setXY(0.0f, 0.0f);
}

CenterRectangle::CenterRectangle(float X, float Y) : Rectangle(0.0f, 0.0f)
{
    setXY(X, Y);
}

//gets
float CenterRectangle::getX() const
{
    return center.x;
}

float CenterRectangle::getY() const
{
    return center.y;
}

const Point2D& CenterRectangle::getXY() const
{
    return center;
}

Point2D CenterRectangle::getLiteralBottomLeft() const
{
    Point2D point = getBottomLeft();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

Point2D CenterRectangle::getLiteralBottomRight() const
{
    Point2D point = getBottomRight();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

Point2D CenterRectangle::getLiteralTopLeft() const
{
    Point2D point = getTopLeft();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

Point2D CenterRectangle::getLiteralTopRight() const
{
    Point2D point = getTopRight();
    point.setXY(point.x + this->getX(), point.y + this->getY());

    return point;
}

//sets
void CenterRectangle::setX(float X)
{
    center.x = X;
}

void CenterRectangle::setY(float Y)
{
    center.y = Y;
}

void CenterRectangle::setXY(float X, float Y)
{
    center.setXY(X, Y);
}

void CenterRectangle::setXY(const Point2D& point)
{
    center = point;
}
