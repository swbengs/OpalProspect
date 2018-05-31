#pragma once

#include <vector>

#include "Point3D.hpp"

/*
Class representing a 3d coordinate
*/

struct Point4D : public Point3D
{
public:

    Point4D() = default;
    Point4D(float X, float Y, float Z, float W);

    void fillArray4D(std::vector<float>& vector) const;
    void fillArray4D(size_t start, std::vector<float>& vector) const;

    //sets
    void setXYZW(float X, float Y, float Z, float W);
    void setXYZW(Point3D point3, float W);

    float w;
};
