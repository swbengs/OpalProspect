#pragma once

#include "ModelIndex.hpp"
#include "NormalBox.hpp"
#include "NormalFace.hpp"

/*
Class that takes a hand made shape and converts it into a model from the Model class.
An example would be taking a NormalBox and coverting it to a Model.
*/

class ShapeToModel
{
public:
    void convertToModelIndex(const NormalBox& box, ModelIndex& model) const;

private:

};
