#include "ModelController.hpp"

//std lib includes
#include <iostream>
#include <assert.h>

//other includes

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

void ModelController::addModel(const ModelIndex &model)
{
    //fill in what we can get right now
    model_pod pod;
    //set defaults for the parts we can't fill in
    pod.index_offset_bytes = 0;
    pod.texture_reference = 0;
    pod.vao_reference = 0;

    //fill in what we can
    pod.model_name = model.getModelName();
    pod.texture_name = model.getTextureName();
    pod.index_count = model.getActualPointCount();
    models.push_back(model);
    pods.push_back(pod);
    references[model.getModelName()] = static_cast<unsigned int>(pods.size()); //cast just in case it's on a 64 bit system
}

size_t ModelController::getCount() const
{
    return models.size();
}

const ModelIndex& ModelController::getModel(unsigned int reference) const
{
    assert(inBounds(reference));
    return models[reference - 1];
}

model_pod ModelController::getModelPOD(unsigned int reference) const
{
    assert(inBounds(reference));
    return pods[reference - 1];
}

unsigned int ModelController::getModelReference(std::string model_name) const
{
    auto search = references.find(model_name);
    if (search != references.end()) //found
    {
        return search->second;
    }
    else
    {
        //std::cout << "model " << model_name << " does not exist from ModelController\n";
        return 0;
    }
}

ModelIndex& ModelController::modifyModel(unsigned int reference)
{
    assert(inBounds(reference));
    return models[reference - 1];
}

model_pod& ModelController::modifyModelPOD(unsigned int reference)
{
    assert(inBounds(reference));
    return pods[reference - 1];
}

bool ModelController::inBounds(unsigned int reference) const
{
    unsigned int actual = reference - 1;
    return (actual >= 0 && actual < models.size());
}

