#pragma once

#include "TextureBox.hpp"

#include "NormalFace.hpp"
#include "Point3D.hpp"

class NormalBox : public TextureBox
{
public:
    void fillNormalFace(NormalFace& front_face, NormalFace& back_face, NormalFace& left_face, NormalFace& right_face, NormalFace& top_face, NormalFace& bottom_face) const;

    //gets
    const Point3D& getFrontNormal() const;
    const Point3D& getBackNormal() const;
    const Point3D& getLeftNormal() const;
    const Point3D& getRightNormal() const;
    const Point3D& getTopNormal() const;
    const Point3D& getBottomNormal() const;

    //sets
    void setFrontNormal(const Point3D& normal);
    void setBackNormal(const Point3D& normal);
    void setLeftNormal(const Point3D& normal);
    void setRightNormal(const Point3D& normal);
    void setTopNormal(const Point3D& normal);
    void setBottomNormal(const Point3D& normal);
    void setNormal(const Point3D& front, const Point3D& back, const Point3D& left, const Point3D& right, const Point3D& top, const Point3D& bottom);

private:
    Point3D front_normal, back_normal, left_normal, right_normal, top_normal, bottom_normal;
};
