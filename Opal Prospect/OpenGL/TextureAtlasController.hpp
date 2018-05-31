#pragma once

#include <vector>
#include "OpenGL\TextureAtlas.hpp"

/*
Class that contains all texture atlas, and their locations starting byte.
*/

class TextureAtlasController
{
public:
    TextureAtlasController();

    void addAtlas(TextureAtlas& atlas);
    TextureAtlas& modifyAtlas(unsigned int index);

    //gets
    const TextureAtlas& getAtlas(unsigned int index);
    unsigned int getAtlasStart(unsigned int index) const;
    unsigned int getIndexSize() const;
    unsigned int getSize() const;
    //sets
    void setIndexSize(unsigned int size);

private:
    unsigned int index_size;

    std::vector<TextureAtlas> atlases;
    std::vector<unsigned int> starts; //byte location of each atlas's starting point
};
