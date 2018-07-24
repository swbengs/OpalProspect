//class header
#include "Image.hpp"

//std lib includes
#include <string>
#include <iostream>

//other includes
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



Image::Image()
{
    image_width = 0;
    image_height = 0;
}

int Image::getWidth() const
{
    return image_width;
}

int Image::getHeight() const
{
    return image_height;
}

std::string Image::getFilename() const
{
    return file_path.getFilename();
}

const std::vector<unsigned char>& Image::getImageData() const
{
    return image_data;
}

void Image::setFilePath(std::string path)
{
    file_path.setFullPath(path);
}

//private
/*
This method flips image since it starts at the top left, while OpenGL starts from the bottom left. This makes it look correct when rendered
*/
void Image::flipVertical(int width, int height)
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
            std::swap(image_data.at(current_row + m), image_data.at(flip_row + m));
        }
    }
}

void Image::loadImage(std::string filename)
{
    png_image image;
    const int color_components = 4;

    //library is in C so some C calls are used. C++ is used when possible
    memset(&image, 0, (sizeof image));
    image.version = PNG_IMAGE_VERSION;

    if (png_image_begin_read_from_file(&image, filename.c_str()) != 0) //0 means it failed
    {
        image.format = PNG_FORMAT_RGBA;

        image_data.resize(PNG_IMAGE_SIZE(image)); //create the buffer to hold the image

        if (image_data.size() == PNG_IMAGE_SIZE(image) &&
            png_image_finish_read(&image, nullptr/*background*/, image_data.data(),
                0/*row_stride*/, nullptr/*colormap*/) != 0)
        {
            //do something with the image

            image_width = image.width;
            image_height = image.height;
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
        std::cout << "image file doesn't exist\n";
        std::cout << filename << "\n \n";
    }

    flipVertical(getWidth() * color_components, getHeight());
}

