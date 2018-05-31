#pragma once

#include <string>
#include <vector>

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
