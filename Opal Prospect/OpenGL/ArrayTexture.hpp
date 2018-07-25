#pragma once

//std lib includes
#include <string>
#include <vector>
#include <unordered_map>

//other includes
#include "Image.hpp"

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
Description: Class to store array texture that is made up of a maximum of 256 files. All images must be the same format and size(width and height). No support for an atlas(single large image that contains many smaller ones inside it). Must all be individual image files.
*/

class ArrayTexture
{
public:
    ArrayTexture();

    void bind() const;
    void unbind() const;
    void loadImages(std::vector<std::string> file_paths); //loads the images but does not upload to video card. Clears all previous loaded images so send up complete vector with all filenames
    void createTexture(); //creates the id and loads the texture file the given filename
    void destroy(); //cleans up this texture on the OpenGL side. Frees the id and calls command to clear the buffer

    //gets
    unsigned int getID() const;
    int getImageWidth() const;
    int getImageHeight() const;
    size_t getImageCount() const;
    std::string getTextureName() const;
    unsigned int getTextureNumberReference(std::string filename) const;

    //sets
    void setTextureName(std::string name);

private:
    unsigned int id; //opengl ID to this texture
    std::string texture_name; //does not need to match filename
    std::vector<Image> images;
    std::unordered_map<std::string, unsigned int> texture_numbers; //what z offset is needed to access the texture within this array with the given name

    void uploadCompleteTexture(int count, void* data) const;
};

