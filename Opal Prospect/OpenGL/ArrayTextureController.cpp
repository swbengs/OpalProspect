//class header
#include "ArrayTextureController.hpp"

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

void ArrayTextureController::addTexture(const ArrayTexture &texture)
{
    textures.push_back(texture);
    references[texture.getTextureName()] = textures.size();
}

void ArrayTextureController::bindTexture(unsigned int reference) const
{
    if (inBounds(reference))
    {
        textures[reference - 1].bind();
    }
    else
    {
        std::cout << "bindVAO reference " << reference << " does not exist\n";
    }
}

size_t ArrayTextureController::getCount() const
{
    return textures.size();
}

const ArrayTexture& ArrayTextureController::getTexture(unsigned int reference) const
{
    return textures[reference - 1];
}

unsigned int ArrayTextureController::getTextureID(unsigned int reference) const
{
    if (inBounds(reference))
    {
        return textures[reference - 1].getID();
    }
    else
    {
        std::cout << "texture reference " << reference << " does not exist\n";
        return 0;
    }
}

unsigned int ArrayTextureController::getTextureReference(std::string texture_name) const
{
    auto search = references.find(texture_name);
    if (search != references.end()) //found
    {
        return search->second;
    }
    else
    {
        //std::cout << "model " << model_name << " does not exist from ArrayTextureController\n";
        return 0;
    }
}

unsigned int ArrayTextureController::getTextureNumber(std::string image_name) const
{
    for (size_t i = 0; i < textures.size(); i++)
    {
        unsigned int reference = textures[i].getTextureNumberReference(image_name);
        if (reference > 0)
        {
            return reference - 1;
        }
    }
    //if we get here we did not find it. Return bad.png

    for (size_t i = 0; i < textures.size(); i++)
    {
        unsigned int reference = textures[i].getTextureNumberReference("bad.png");
        if (reference > 0)
        {
            std::cout << image_name << " not found. Returning bad.png\n";
            return reference - 1;
        }
    }

    std::cout << image_name << " not found. Can't find bad.png\n";
    return 0; //worst casse we can't find either so return 0, which is a bad reference
}

ArrayTexture& ArrayTextureController::modifyTexture(unsigned int reference)
{
    return textures[reference - 1];
}

bool ArrayTextureController::inBounds(unsigned int reference) const
{
    unsigned int actual = reference - 1;
    return (actual >= 0 && actual < textures.size());
}
