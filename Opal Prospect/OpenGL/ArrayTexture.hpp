#pragma once

//std lib includes
#include <string>
#include <vector>

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

/*
Class to load and store a texture that is array of textures. 256 max supported z depth with OpenGL 3.3. 4.0+ adds support for 1024 or more I believe. Also can load multiple files and combine them into a single array texture as long as they all
share the same individual size. Instead of a texture atlas, one big image that you divide with texture coordinates, you have lots of smaller textures of the same size. Such as 16x16px
*/

class ArrayTexture
{
public:
    ArrayTexture();

    void bind() const;
    void unbind() const;
    void createTexture(); //creates the id and loads the texture file the given filename
    void destroy();

    //gets
    unsigned int getID() const;
    std::string getFilename() const;
    int getWidth() const;
    int getHeight() const;
    int getAtlasWidth() const;
    int getAtlasHeight() const;
    int getAtlasDepth() const;
    size_t getAtlasCount() const;

    //sets
    void setTextureWidth(int width);
    void setTextureHeight(int height);
    void setFilename(std::string filename);

    //loads the image and does everything but interact with opengl. Use this to test without having a context created
    void testLoading(std::vector<unsigned char>& store_data);

private:
    unsigned int id; //opengl ID to this texture
    std::string name; //filename
    std::vector<std::vector<unsigned char>> atlas_data; //this way we can have the images completely seperate. Each image is loaded into its own unsigned char vector we can access

    //these two are given by file
    int texture_width; //in pixels for each individual texture in the array
    int texture_height; 

    //these 3 are calculated
    int atlas_width; //atlas variables pertain to the count of textures in width and height
    int atlas_height;
    int atlas_depth;//in total layers. OpenGL 3.0 and above has 256 minimum. 4.0 and above has 2048 or more

    void loadTexture(std::string filename, int& texture_width, int& texture_height, std::vector<std::vector<unsigned char>>& vector);
    void flipVertical(int width, int height, std::vector<unsigned char>& vector);
    void uploadTexture(int z_offset, void* data) const;

    void extractTexture(std::vector<unsigned char>& data, std::vector<unsigned char>& atlas, size_t start, int atlas_x, int atlas_y, int pixel_size) const;
};
