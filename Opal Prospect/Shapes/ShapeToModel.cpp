#include "ShapeToModel.hpp"

/*
MIT License

Copyright (c) 2018 Scott Bengs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
