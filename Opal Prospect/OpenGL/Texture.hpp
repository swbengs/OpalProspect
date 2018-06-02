#pragma once

#include <string>
#include <vector>

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
Class to load and store a texture.
*/

class Texture
{
public:
    Texture();

    void bind() const;
    void unbind() const;
    void createTexture(); //creates the id and loads the texture file the given filename
    void destroy();

    //gets
    unsigned int getID() const;
    std::string getFilename() const;
    int getWidth() const;
    int getHeight() const;
    //sets
    void setFilename(std::string filename);
private:
    unsigned int id; //opengl ID to this texture
    std::string name;
    std::vector<unsigned char> texture_data;
    int texture_width; //in pixels
    int texture_height; //in pixels

    void loadTexture(std::string filename, int& texture_width, int& texture_height, std::vector<unsigned char>& vector);
    void flipVertical(int width, int height, std::vector<unsigned char>& vector);
};
