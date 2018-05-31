#pragma once

/*
Class to store a face with only a vertex and index for it. A face meaning 4 points creating a rectangle
*/

#include <vector>

#include "Point3D.hpp"

class VertexFace
{
public:
    VertexFace();

    //gets
    Point3D getBottomLeftVertex() const;
    Point3D getBottomRightVertex() const;
    Point3D getTopLeftVertex() const;
    Point3D getTopRightVertex() const;

    unsigned int getBottomLeftIndex() const;
    unsigned int getBottomRightIndex() const;
    unsigned int getTopLeftIndex() const;
    unsigned int getTopRightIndex() const;

    //sets
    void setBottomLeftVertex(Point3D point);
    void setBottomRightVertex(Point3D point);
    void setTopLeftVertex(Point3D point);
    void setTopRightVertex(Point3D point);
    void setVertex(Point3D bottom_left, Point3D bottom_right, Point3D top_left, Point3D top_right);

    void setBottomLeftIndex(unsigned int index);
    void setBottomRightIndex(unsigned int index);
    void setTopLeftIndex(unsigned int index);
    void setTopRightIndex(unsigned int index);
    void setIndex(unsigned int bottom_left, unsigned int bottom_right, unsigned int top_left, unsigned int top_right);

private:
    Point3D bottom_left_vertex;
    Point3D bottom_right_vertex;
    Point3D top_left_vertex;
    Point3D top_right_vertex;

    unsigned int bottom_left_index;
    unsigned int bottom_right_index;
    unsigned int top_left_index;
    unsigned int top_right_index;
};
