#pragma once

#include <string>
#include <vector>

/*
Class to load and store a texture.
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

    //sets
    void setTextureWidth(int width);
    void setTextureHeight(int height);
    void setFilename(std::string filename);

    void testLoading(std::vector<unsigned char>& store_data);

private:
    unsigned int id; //opengl ID to this texture
    std::string name; //filename
    std::vector<unsigned char> atlas_data;

    //these two are given by user/file
    int texture_width; //in pixels for each individual texture in the array
    int texture_height; 

    //these 3 are calculated
    int atlas_width; //atlas variables pertain to the count of textures in width and height
    int atlas_height;
    int atlas_depth;//in total layers. OpenGL 3.0 and above has 256 minimum. 4.0 and above has 2048 or more

    void loadTexture(std::string filename, int& texture_width, int& texture_height, std::vector<unsigned char>& vector);
    void flipVertical(int width, int height, std::vector<unsigned char>& vector);
    void uploadTexture(int z_offset, void* data) const;

    void extractTexture(std::vector<unsigned char>& data, size_t start, int atlas_x, int atlas_y, int pixel_size) const;
};
