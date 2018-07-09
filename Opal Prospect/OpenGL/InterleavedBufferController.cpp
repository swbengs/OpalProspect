//class header
#include "InterleavedBufferController.hpp"

//std lib includes
#include <iostream>
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

//class code

InterleavedBufferController::InterleavedBufferController()
{
    std::cout << "max vertex: " << MAXIMUM_VERTEX_BUFFER_SIZE << " max index: " << MAXIMUM_INDEX_BUFFER_SIZE << "\n";
}

unsigned int InterleavedBufferController::addModel(ModelIndex & model)
{
    return 0;
}

void InterleavedBufferController::bindVAO(unsigned int reference) const
{
    if (inBounds(reference))
    {
        vaos[reference - 1].bindVAO();
    }
    else
    {
        std::cout << "bindVAO reference " << reference << " does not exist\n";
    }
}

void InterleavedBufferController::destroyBuffers()
{
    for (unsigned int i = 0; i < vaos.size(); i++)
    {
        vaos[i].destroy();
    }
}

size_t InterleavedBufferController::getVAOCount() const
{
    return vaos.size();
}

unsigned int InterleavedBufferController::getVAOID(unsigned int reference) const
{
    if (inBounds(reference))
    {
        return vaos[reference - 1].getID();
    }
    else
    {
        std::cout << "getVAOID reference " << reference << " does not exist\n";
        return 0;
    }
}

unsigned int InterleavedBufferController::getModelVAOReference(std::string model_name) const
{
    auto search = model_infos.find(model_name);
    if (search != model_infos.end()) //found
    {
        return search->second.vao_reference;
    }
    else
    {
        //std::cout << "model " << model_name << " does not exist\n";
        return 0;
    }
}

unsigned int InterleavedBufferController::getIndexByteOffset(std::string model_name) const
{
    auto search = model_infos.find(model_name);
    if (search != model_infos.end()) //found
    {
        return search->second.index_byte_offset;
    }
    else
    {
        //std::cout << "model " << model_name << " does not exist\n";
        return 0;
    }
}

unsigned int InterleavedBufferController::getIndexCount(std::string model_name) const
{
    auto search = model_infos.find(model_name);
    if (search != model_infos.end()) //found
    {
        return search->second.index_count;
    }
    else
    {
        //std::cout << "model " << model_name << " does not exist\n";
        return 0;
    }
}

int InterleavedBufferController::findSuitableBuffer(size_t total_size, size_t index_size) const
{
    return 0;
}

void InterleavedBufferController::bufferModel(int index, ModelIndex & model)
{
}

void InterleavedBufferController::makeBuffer()
{
    InterleavedVAO3D temp;
    temp.setMaximumVertexSize(MAXIMUM_VERTEX_BUFFER_SIZE);
    temp.setMaximumIndexSize(MAXIMUM_INDEX_BUFFER_SIZE);
    temp.create();
    vaos.push_back(temp);
    index_byte_offset_totals.push_back(0);
}

bool InterleavedBufferController::inBounds(unsigned int reference) const
{
    unsigned int actual = reference - 1;
    return (actual >= 0 && actual < vaos.size());
}
