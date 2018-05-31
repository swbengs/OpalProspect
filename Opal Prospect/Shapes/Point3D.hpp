#pragma once

#include <vector>

#include "Point2D.hpp"

/* 
Class representing a 3d coordinate
*/

struct Point3D : public Point2D
{
public:
    Point3D() = default;
    Point3D(float X, float Y, float Z);

    void fillArray3D(std::vector<float>& vector) const;
    void fillArray3D(size_t start, std::vector<float>& vector) const;

    //sets
    void setXYZ(float X, float Y, float Z);

    float z;
};