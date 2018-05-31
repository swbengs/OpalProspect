#pragma once

#include "Box.hpp"

#include <array>

#include "VertexFace.hpp"
#include "Point3D.hpp"

/*

*/

class VertexBox : public Box
{
public:
    void fillVertexFace(VertexFace& front_face, VertexFace& back_face, VertexFace& left_face, VertexFace& right_face, VertexFace& top_face, VertexFace& bottom_face) const;
    void fillIndexFace(VertexFace& front_face, VertexFace& back_face, VertexFace& left_face, VertexFace& right_face, VertexFace& top_face, VertexFace& bottom_face)const;

    //6 faces * 4 points * 4 floats each = 96 floats
    void fillVertexIndexed(std::array<float, 96> &data) const; //fills in 4d coordinates
    //6 faces * 2 triangles * 3 index each
    void fillIndex(size_t start, std::array<unsigned int, 36> &data) const;
private:
    void fillFaceVertex(size_t start, float* data, Point3D &bottom_left, Point3D &bottom_right, Point3D &top_left, Point3D &top_right) const;
    void fillPoint(size_t start, float *data, Point3D &point) const;
    //data start is where in the int pointer you want to start writing at, and index start is what index number to start from. For example if it's the second box you would have 2 * size of box index
    void fillFaceIndex(size_t data_start, size_t index_offset, unsigned int *data, int bottom_left, int bottom_right, int top_left, int top_right) const;
};
