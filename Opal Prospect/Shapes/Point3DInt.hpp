#pragma once

#include <vector>

/* 
Class representing a 3d coordinate as an int
*/

struct Point3DInt
{
public:

    Point3DInt() = default;
    Point3DInt(int X, int Y, int Z);

    void fillArray(std::vector<int>& vector) const;
    void fillArray(size_t start, std::vector<int>& vector) const;

    //sets
    void setXYZ(int X, int Y, int Z);

    int x;
    int y;
    int z;
};