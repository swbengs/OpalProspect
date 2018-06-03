#include "Texture.hpp"
#include "GL\glew.h"
#include "png.h"

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

Texture::Texture()
{
    id = 0;
    name = "";
    texture_width = 0;
    texture_height = 0;
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, getID());
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::createTexture()
{
    int color_components = 4;

    int level = 0;
    int border = 0;

    //UV(xy) = ST
    if (name.compare("") != 0) //make sure it contains something
    {
        glGenTextures(1, &id); //create an id and bind it
        bind();

        loadTexture(name, texture_width, texture_height, texture_data); //takes the filename and loads from that

        flipVertical(getWidth()*color_components, getHeight(), texture_data);

        //glTexImage2D(GL_TEXTURE_2D, level, internalformat, width, height, border, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA8, getWidth(), getHeight(), border, GL_RGBA, GL_UNSIGNED_BYTE, texture_data.data()); //fill in the data on the graphics card

        //texture parameters below
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        /* GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_MIRRORED_REPEAT, GL_REPEAT, or GL_MIRROR_CLAMP_TO_EDGE.
        */
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
}

void Texture::destroy()
{
    unbind();
    glDeleteTextures(1, &id);
}

//gets
unsigned int Texture::getID() const
{
    return id;
}

int Texture::getWidth() const
{
    return texture_width;
}

int Texture::getHeight() const
{
    return texture_height;
}

//sets
std::string Texture::getFilename() const
{
    return name;
}

//sets
void Texture::setFilename(std::string filename)
{
    name = filename;
}

//private
void Texture::loadTexture(std::string filename, int& width, int& height, std::vector<unsigned char>& vector)
{
    png_image image;

    memset(&image, 0, (sizeof image));
    image.version = PNG_IMAGE_VERSION;

    if (png_image_begin_read_from_file(&image, filename.c_str()) != 0) //0 means it failed
    {
        image.format = PNG_FORMAT_RGBA;

        //buffer = malloc(PNG_IMAGE_SIZE(image));
        //unsigned char* buffer = new unsigned char[PNG_IMAGE_SIZE(image)];
        vector.resize(PNG_IMAGE_SIZE(image)); //create the buffer to hold the image

        if (vector.size() == PNG_IMAGE_SIZE(image) &&
            png_image_finish_read(&image, NULL/*background*/, vector.data(),
                0/*row_stride*/, NULL/*colormap*/) != 0)
        {
            //do something with the image

            width = image.width;
            height = image.height;
            //vector was filled with the image data
        }
        else
        {
            /* Calling png_free_image is optional unless the simplified API was
            * not run to completion.  In this case if there wasn't enough
            * memory for 'buffer' we didn't complete the read, so we must free
            * the image:
            */

            //image could not load
        }
    }
}

void Texture::flipVertical(int width, int height, std::vector<unsigned char>& vector)
{
    int current_row;
    int flip_row;

    for (int n = 0; n < height / 2; n++)
    {
        //std::cout << n << "\n";
        current_row = n*width;
        flip_row = width * (height - 1 - n);

        for (int m = 0; m < width; m++)
        {
            std::swap(vector.at(current_row + m), vector.at(flip_row + m));
        }
    }
}
