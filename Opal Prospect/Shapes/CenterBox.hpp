#pragma once

#include "Shapes\Box.hpp"

//Rectangle with a center

class CenterBox : public Box
{
public:
    CenterBox();
    CenterBox(const Box& box);

    //gets
    float getX() const;
    float getY() const;
    float getZ() const;
    const Point3D& getXYZ() const;

    //these gets are based on where the center is. So if the center is at 100, 0, you would add 100 to the x value and 0 to the y value
    Point3D getLiteralFrontBottomLeft() const;
    Point3D getLiteralFrontBottomRight() const;
    Point3D getLiteralFrontTopLeft() const;
    Point3D getLiteralFrontTopRight() const;

    Point3D getLiteralBackBottomLeft() const;
    Point3D getLiteralBackBottomRight() const;
    Point3D getLiteralBackTopLeft() const;
    Point3D getLiteralBackTopRight() const;

    //sets
    void setX(float X);
    void setY(float Y);
    void setZ(float Z);
    void setXYZ(float X, float Y, float Z);
    void setXYZ(const Point3D& point);

private:
    Point3D center;

    void addCenter(Point3D& point) const;
};
