//class header
#include "ArrayTexture.hpp"

//std lib includes
#include <iostream>
#include <sstream>

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
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, getID());
}

void ArrayTexture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void ArrayTexture::loadImages(std::vector<std::string> file_paths)
{
    std::stringstream stream;
    stream << "Textures" << FilePath::getOSSeperator() << "bad.png";
    std::string fallback = stream.str();
    for (size_t i = 0; i < file_paths.size(); i++)
    {
        Image temp;
        temp.setFilePath(file_paths[i]);
        //temp.loadImage();
        temp.loadImageFallback(file_paths[i], fallback);
        images.push_back(temp);
    }
}

void ArrayTexture::createTexture()
{
    const int color_components = 4;
    const int id_count = 1;
    const int level = 0; //not using mipmaps so it's always 0
    const int border = 0; //no border being used so set to 0
    void* data = nullptr;
    std::vector<unsigned char> complete_texture;

    if (images.size() == 0)
    {
        std::cout << "No images have been loaded. Exiting\n";
        return; //nothing to setup so just exit
    }

    if (id > 0)
    {
        destroy(); //make sure we clean up our current texture before we generate another
    }

    glGenTextures(id_count, &id); //create an id and bind it
    bind();

    OGLHelpers::getOpenGLError("pre teximage3d");
    //void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data);
    glTexImage3D(GL_TEXTURE_2D_ARRAY, level, GL_RGBA8, images[0].getWidth(), images[0].getHeight(), static_cast<int>(getImageCount()), border, GL_RGBA, GL_UNSIGNED_BYTE, data); //fill in the data on the graphics card

    OGLHelpers::getOpenGLError("post teximage3d");

    //GL_NEAREST, GL_LINEAR
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_MIRRORED_REPEAT, GL_REPEAT, or GL_MIRROR_CLAMP_TO_EDGE
    //glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_TEXTURE_WRAP_S);
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_TEXTURE_WRAP_T);

    OGLHelpers::getOpenGLError("post texparam");

    complete_texture.reserve(images[0].getSize() * getImageCount()); //holds the complete texture that is uploaded in one go. Only reserve them since we insert later

    for (size_t i = 0; i < images.size(); i++)
    {
        const std::vector<unsigned char>& ref = images[i].getImageData();
        complete_texture.insert(complete_texture.end(), ref.begin(), ref.end());
        texture_numbers[images[i].getFilename()] = i;
    }

    uploadCompleteTexture(static_cast<int>(getImageCount()), complete_texture.data());
    OGLHelpers::getOpenGLError("post array texture uploads");

    unbind();
}

void ArrayTexture::destroy()
{
    const int count = 1;
    unbind();
    if (id > 0)
    {
        glDeleteTextures(count, &id);
    }
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

unsigned int ArrayTexture::getTextureNumberReference(std::string filename) const
{
    auto it = texture_numbers.find(filename);
    if (it == texture_numbers.end())
    {
        //std::cout << "name: " << filename << " was not found\n";
        return 0;
    }
    else
    {
        return it->second + 1;
    }
}

void ArrayTexture::setTextureName(std::string name)
{
    texture_name = name;
}

/*
Sends the entire texture up in one go instead of individual layers
*/
void ArrayTexture::uploadCompleteTexture(int count, void* data) const
{
    const int level = 0;
    const int x_offset = 0;
    const int y_offset = 0;
    const int z_offset = 0; //start at the beginning
    //z offset specifies what level you want to start on. 0 is base. You can upload it all from 0 or just do them idividually

    //void glTexSubImage3D(	GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, x_offset, y_offset, z_offset, images[0].getWidth(), images[0].getHeight(), count, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

