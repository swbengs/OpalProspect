#pragma once

#include "TextureFace.hpp"

#include <vector>

#include "Shapes\Point3D.hpp"

/*
Class that stores the normals for a face
*/

class NormalFace : public TextureFace
{
public:
    NormalFace();

    //gets
    Point3D getBottomLeftNormal() const;
    Point3D getBottomRightNormal() const;
    Point3D getTopLeftNormal() const;
    Point3D getTopRightNormal() const;

    //sets
    void setBottomLeftNormal(Point3D normal);
    void setBottomRightNormal(Point3D normal);
    void setTopLeftNormal(Point3D normal);
    void setTopRightNormal(Point3D normal);
    void setNormal(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right);

private:
    Point3D bottom_left_normal;
    Point3D bottom_right_normal;
    Point3D top_left_normal;
    Point3D top_right_normal;
};