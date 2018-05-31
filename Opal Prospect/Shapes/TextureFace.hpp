#pragma once

#include "VertexFace.hpp"

#include "Shapes\Point3D.hpp"

/*
Class that stores the texture UV for a face. The UV have a third coordinate for the level, referring to the array texture index.
*/

class TextureFace : public VertexFace
{
public:
    TextureFace();

    //gets
    Point3D getBottomLeftUV() const;
    Point3D getBottomRightUV() const;
    Point3D getTopLeftUV() const;
    Point3D getTopRightUV() const;

    //sets
    void setBottomLeftUV(Point3D uv);
    void setBottomRightUV(Point3D uv);
    void setTopLeftUV(Point3D uv);
    void setTopRightUV(Point3D uv);
    void setUV(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right);

private:
    Point3D bottom_left_uv;
    Point3D bottom_right_uv;
    Point3D top_left_uv;
    Point3D top_right_uv;
};