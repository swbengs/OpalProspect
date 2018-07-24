//class header
#include "ArrayTexture.hpp"

//std lib includes
#include <iostream>

//other includes
#include "glew.h"
#include "OGLHelpers.hpp"

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

ArrayTexture::ArrayTexture()
{
    id = 0;
    texture_name = "";
}

void ArrayTexture::bind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, getID());
}

void ArrayTexture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void ArrayTexture::loadImages(std::vector<std::string> file_paths)
{
    for (size_t i = 0; i < file_paths.size(); i++)
    {
        Image temp;
        temp.setFilePath(file_paths[i]);
        temp.loadImage();
        images.push_back(temp);
    }
}

void ArrayTexture::createTexture()
{
    const int color_components = 4;
}

void ArrayTexture::destroy()
{
    const int count = 1;
    unbind();
    glDeleteTextures(count, &id);
}

unsigned int ArrayTexture::getID() const
{
    return id;
}

int ArrayTexture::getImageWidth() const
{
    if (images.size() == 0) //don't cause exception if there are no loaded images
    {
        return 0;
    }
    else
    {
        return images[0].getWidth();
    }
}

int ArrayTexture::getImageHeight() const
{
    if (images.size() == 0)
    {
        return 0;
    }
    else
    {
        return images[0].getWidth();
    }
}

size_t ArrayTexture::getImageCount() const
{
    return images.size();
}

std::string ArrayTexture::getTextureName() const
{
    return texture_name;
}

void ArrayTexture::setTextureName(std::string name)
{
    texture_name = name;
}
