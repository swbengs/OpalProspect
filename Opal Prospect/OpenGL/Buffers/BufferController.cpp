#include "BufferController.hpp"

#include <iostream>
#include <string>

#include "OpenGL\OGLHelpers.hpp"

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

BufferController::BufferController()
{ }

unsigned int BufferController::addModel(ModelIndex &model)
{
    if (getModelVAOReference(model.getModelName()) == 0) //not found
    {
        //first check if the model will even fit
        size_t size = model.getTotalSize();
        if (size > MAXIMUM_BUFFER_SIZE)
        {
            std::cout << "Model " << model.getModelName() << " is too large to fit in any buffer\n";
            return 0;
        }

        OGLHelpers::getOpenGLError("pre buffering", true);

        int buffer = findSuitableBuffer(size, model.getIndexTotalSize());
        if (buffer == -1)
        {
            makeBuffer();
            buffer = vaos.size() - 1;
        }

        bufferModel(buffer, model);
        std::cout << "putting in VAO " << (buffer + 1) << "\n";
        OGLHelpers::getOpenGLError("post buffering", true);

        unsigned int reference = static_cast<unsigned int>(buffer + 1);
        references[model.getModelName()] = reference; //insert into hashmap
        //std::cout << model.getModelName();

        return reference;
    }
    else
    {
        std::cout << "Model " << model.getModelName() << " already in a buffer\n";
        return 0;
    }
}

void BufferController::bindVAO(unsigned int reference) const
{
    if (inBounds(reference))
    {
        vaos[reference - 1].bind();
    }
    else
    {
        std::cout << "bindVAO reference " << reference << " does not exist\n";
    }
}

void BufferController::destroyBuffers()
{
    for (unsigned int i = 0; i < vaos.size(); i++)
    {
        vaos[i].destroy();
    }
}

size_t BufferController::getCount()
{
    return vaos.size();
}

//gets
unsigned int BufferController::getVAOID(unsigned int reference) const
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

unsigned int BufferController::getModelVAOReference(std::string model_name) const
{
    auto search = references.find(model_name);
    if (search != references.end()) //found
    {
        return search->second;
    }
    else
    {
        //std::cout << "model " << model_name << " does not exist\n";
        return 0;
    }
}

unsigned int BufferController::getModelIndexOffset(std::string model_name) const
{
    return 0;
}

//private
int BufferController::findSuitableBuffer(size_t total_size, size_t index_size) const
{
    for (unsigned int i = 0; i < vaos.size(); i++)
    {
        if (vaos[i].getRemainingSize() >= total_size && vaos[i].getRemainingIndexSize() >= index_size)
        {
            return static_cast<int>(i);
        }
    }

    return -1; //-1 is a non usable index
}

void BufferController::bufferModel(int index, ModelIndex &model)
{
    VertexUVNormalIndexVAO3D& vao = vaos[index];
    vao.bind();

    std::vector<float> vertexs;
    model.fillVertex(vertexs);
    
    std::vector<float> uvs;
    model.fillUV(uvs);
    
    std::vector<float> normals;
    model.fillNormal(normals);
    
    std::vector<unsigned int> indexes;
    model.setIndexOffset(vao.getIndexOffset());
    model.fillIndex(indexes);
    vao.setIndexOffset(vao.getIndexOffset() + model.getUniquePointCount());

    OGLHelpers::getOpenGLError("pre all vertex data binds", true);
    vao.bindVertex();
    vao.bufferVertex(vertexs);
    OGLHelpers::getOpenGLError("post vertex", true);

    vao.bindUV();
    vao.bufferUV(uvs);
    OGLHelpers::getOpenGLError("post uv", true);

    vao.bindNormal();
    vao.bufferNormal(normals);
    OGLHelpers::getOpenGLError("post normal", true);

    vao.bindIndex();
    vao.bufferIndex(indexes);
    OGLHelpers::getOpenGLError("post index", true);

    vao.unBind();
}

void BufferController::makeBuffer()
{
    VertexUVNormalIndexVAO3D temp;
    temp.setMaximumSize(MAXIMUM_BUFFER_SIZE);
    temp.create();
    vaos.push_back(temp);
}

bool BufferController::inBounds(unsigned int reference) const
{
    unsigned int actual = reference - 1;
    return (actual >= 0 && actual < vaos.size());
}
