#include "ArrayTexture.hpp"

#include "glew.h"
#include "png.h"

#include <iostream>
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
    name = "";
    texture_width = 0;
    texture_height = 0;
    atlas_width = 0;
    atlas_height = 0;
    atlas_depth = 0;
}

void ArrayTexture::bind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, getID());
}

void ArrayTexture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void ArrayTexture::createTexture()
{
    const int color_components = 4;

    //values to fill in so it's more easily readable
    const int level = 0; //not using mipmaps so it's always 0
    const int border = 0; //no border being used so set to 0
    void* data = nullptr; //will upload data later so leave it NULL

    //UV(xy) = ST
    if (name.compare("") != 0) //make sure it contains something
    {
        //both in pixels
        int image_width;
        int image_height;
        int id_count = 1; //how many ids do you want

        glGenTextures(id_count, &id); //create an id and bind it
        bind();

        loadTexture(name, image_width, image_height, atlas_data); //takes the filename and loads from it

        flipVertical(image_width*color_components, image_height, atlas_data);

        //calculate atlas width, height, and depth
        atlas_width = image_width / getWidth();
        atlas_height = image_height / getHeight();
        atlas_depth = getAtlasWidth() * getAtlasHeight();

        OGLHelpers::getOpenGLError("pre teximage3d");
        //void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data);
        glTexImage3D(GL_TEXTURE_2D_ARRAY, level, GL_RGBA8, getWidth(), getHeight(), getAtlasDepth(), border, GL_RGBA, GL_UNSIGNED_BYTE, data); //fill in the data on the graphics card

        OGLHelpers::getOpenGLError("post teximage3d");

        //GL_NEAREST, GL_LINEAR
        glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_MIRRORED_REPEAT, GL_REPEAT, or GL_MIRROR_CLAMP_TO_EDGE
        glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        OGLHelpers::getOpenGLError("post texparam");

        int pixel_size = sizeof(unsigned char) * color_components;

        std::vector<unsigned char> pixel_data;
        pixel_data.resize(pixel_size * getWidth() * getHeight()); //we need actual elements to be there

        //load each atlas part seperately
        int start = 0;

        for (int n = 0; n < getAtlasDepth(); n++)
        {
            //integer math is correct here. don't convert to float/doubles
            int atlas_y = n / getAtlasWidth();
            int atlas_x = n - getAtlasWidth() * atlas_y;

            extractTexture(pixel_data, start, atlas_x, atlas_y, pixel_size);
            uploadTexture(n, pixel_data.data());
            OGLHelpers::getOpenGLError("loop array texture uploads", true);
        }

        OGLHelpers::getOpenGLError("post array texture uploads");
        std::cout << "\n \n";

        unbind();
    }
}

void ArrayTexture::destroy()
{
    int count = 1;
    unbind();
    glDeleteTextures(count, &id);
}

//gets
unsigned int ArrayTexture::getID() const
{
    return id;
}

int ArrayTexture::getWidth() const
{
    return texture_width;
}

int ArrayTexture::getHeight() const
{
    return texture_height;
}

int ArrayTexture::getAtlasWidth() const
{
    return atlas_width;
}

int ArrayTexture::getAtlasHeight() const
{
    return atlas_height;
}

int ArrayTexture::getAtlasDepth() const
{
    return atlas_depth;
}

size_t ArrayTexture::getAtlasCount() const
{
    return getAtlasDepth();
}

std::string ArrayTexture::getFilename() const
{
    return name;
}

//sets
void ArrayTexture::setTextureWidth(int width)
{
    texture_width = width;
}

void ArrayTexture::setTextureHeight(int height)
{
    texture_height = height;
}

void ArrayTexture::setFilename(std::string filename)
{
    name = filename;
}

void ArrayTexture::testLoading(std::vector<unsigned char>& store_data)
{
    int color_components = 4;

    //values to fill in so it's more easily readable
    //int level = 0; //not using mipmaps so it's always 0
    //int border = 0; //no border being used so set to 0
    //void* data = NULL; //will upload data later so leave it NULL

    if (name.compare("") != 0) //make sure it contains something
    {
        //both in pixels
        int image_width;
        int image_height;
        //int id_count = 1; //how many ids do you want

        //glGenTextures(id_count, &id); //create an id and bind it
        //bind();

        loadTexture(name, image_width, image_height, atlas_data); //takes the filename and loads from it

        flipVertical(image_width*color_components, image_height, atlas_data);

        //calculate atlas width, height, and depth
        atlas_width = image_width / getWidth();
        atlas_height = image_height / getHeight();
        atlas_depth = getAtlasWidth() * getAtlasHeight();

        //void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * data);
        //glTexImage3D(GL_TEXTURE_2D_ARRAY, level, GL_RGBA8, getWidth(), getHeight(), getAtlasDepth(), border, GL_RGBA, GL_UNSIGNED_BYTE, data); //fill in the data on the graphics card

                                                                                                                                               //GL_NEAREST, GL_LINEAR
        //glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        //glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_MIRRORED_REPEAT, GL_REPEAT, or GL_MIRROR_CLAMP_TO_EDGE
        //glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        //glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        int pixel = sizeof(unsigned char) * color_components;

        std::vector<unsigned char> pixel_data;
        pixel_data.resize(pixel * getWidth() * getHeight()); //we need actual elements to be there

                                                       //load each atlas part seperately
        int start = 0;

        for (int n = 0; n < getAtlasDepth(); n++)
        {
            //integer math is correct here. don't convert to float/doubles
            int atlas_y = n / getAtlasWidth();
            int atlas_x = n - getAtlasWidth() * atlas_y;

            extractTexture(pixel_data, start, atlas_x, atlas_y, pixel);
            //uploadTexture(n, data.data());
            for (unsigned int a = 0; a < pixel_data.size(); a++)
            {
                store_data.push_back(pixel_data[a]);
            }
            
        }

        unbind();
    }
}

//private
void ArrayTexture::loadTexture(std::string filename, int& width, int& height, std::vector<unsigned char>& vector)
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
    else
    {
        std::cout << "file doesn't exist\n";
        std::cout << filename << "\n \n";
    }
}

void ArrayTexture::flipVertical(int width, int height, std::vector<unsigned char>& vector)
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

void ArrayTexture::uploadTexture(int z_offset, void* data) const
{
    int level = 0;
    int x_offset = 0;
    int y_offset = 0;
    int count = 1;

    //z offset specifies what level you want to start on. 0 is base. You can upload it all from 0 or just do them idividually

    //void glTexSubImage3D(	GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, x_offset, y_offset, z_offset, getWidth(), getHeight(), count, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void ArrayTexture::extractTexture(std::vector<unsigned char>& data, size_t start, int atlas_x, int atlas_y, int pixel_size) const
{
    int texture_row_size = pixel_size * getWidth(); //single texture
    int atlas_row_size = texture_row_size * getAtlasWidth(); //entire atlas which is texture row size * atlas width
    int atlas_column_total_size = atlas_row_size * getHeight();

    int bottom_left_start = atlas_x * texture_row_size + atlas_y * atlas_column_total_size;

    //read one row at a time for texture height
    for (int y = 0; y < getHeight(); y++)
    {
        for (int x = 0; x < texture_row_size; x++)
        {
            data[start + x + y * texture_row_size] = atlas_data[bottom_left_start + x + y * atlas_row_size];
            //data.at(start + x + y * texture_row_size) = atlas_data.at(bottom_left_start + x + y * atlas_row_size);
        }
    }
}
