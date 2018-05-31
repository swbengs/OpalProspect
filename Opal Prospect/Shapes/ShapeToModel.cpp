#include "ShapeToModel.hpp"

void ShapeToModel::convertToModelIndex(const NormalBox& box, ModelIndex& model) const
{
    NormalFace front_face, back_face, left_face, right_face, top_face, bottom_face;

    box.fillVertexFace(front_face, back_face, left_face, right_face, top_face, bottom_face);
    box.fillIndexFace(front_face, back_face, left_face, right_face, top_face, bottom_face);
    box.fillTextureFace(front_face, back_face, left_face, right_face, top_face, bottom_face);
    box.fillNormalFace(front_face, back_face, left_face, right_face, top_face, bottom_face);

    model.addFace(front_face);
    model.addFace(back_face);
    model.addFace(left_face);
    model.addFace(right_face);
    model.addFace(top_face);
    model.addFace(bottom_face);
}
