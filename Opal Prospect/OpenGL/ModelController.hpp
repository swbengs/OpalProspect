#pragma once

//std lib includes
#include <vector>
#include <unordered_map>
#include <string>
#include <assert.h>

//other includes
#include "DrawEngineStructs.hpp"
#include "..\Shapes\ModelIndex.hpp"

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

/*
Description: This class is used to store all models and how they are accessed. Also contains one model pod for each model contained within. Interfaces with BufferController to add information on what VAO the model is stored in and index info to draw it
*/

class ModelController
{
public:
    void addModel(ModelIndex&& model);

    size_t getCount() const;
    const ModelIndex& getModel(unsigned int reference) const; //for reading only
    model_pod getModelPOD(unsigned int reference) const;
    unsigned int getModelReference(std::string model_name) const;

    ModelIndex& modifyModel(unsigned int reference); //for writing and reading
    model_pod& modifyModelPOD(unsigned int reference);
private:
    std::vector<ModelIndex> models;
    std::vector<model_pod> pods;
    std::unordered_map<std::string, unsigned int> references;

    bool inBounds(unsigned int reference) const;
};

