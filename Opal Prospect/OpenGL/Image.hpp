#pragma once

//std lib includes
#include <vector>

//other includes
#include "..\FilePath.hpp"

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
Description: Class to hold an image and the filename to that image. Automatically flipped vertically to be ready for OpenGL use.
*/

class Image
{
public:
    Image();

    //gets
    int getWidth() const;
    int getHeight() const;
    std::string getFilename() const;
    const std::vector<unsigned char>& getImageData() const;

    //sets
    void setFilePath(std::string path); //sets the full filepath and the filename is extracted from this

private:
    int image_width;
    int image_height;
    std::vector<unsigned char> image_data;
    FilePath file_path;

    void flipVertical(int width, int height);
    void loadImage(std::string filename);
};

