#pragma once

#include "Point3D.hpp"

/*
Class for a Box.
*/

class Box
{
public:
    Box();

    //gets
    float getWidth() const;
    float getHeight() const;
    float getLength() const;
    Point3D getWidthHeightLength() const;

    Point3D getFrontBottomLeft() const;
    Point3D getFrontBottomRight() const;
    Point3D getFrontTopLeft() const;
    Point3D getFrontTopRight() const;

    Point3D getBackBottomLeft() const;
    Point3D getBackBottomRight() const;
    Point3D getBackTopLeft() const;
    Point3D getBackTopRight() const;

    //sets
    void setWidth(float width);
    void setHeight(float height);
    void setLength(float length);
    void setWidthHeightLength(float width,  float height,  float length);
private:
    Point3D whl; //width height length
};

