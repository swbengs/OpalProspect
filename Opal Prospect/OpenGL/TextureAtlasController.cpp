#include "OpenGL\TextureAtlasController.hpp"

TextureAtlasController::TextureAtlasController()
{
    index_size = 0;
}

void TextureAtlasController::addAtlas(TextureAtlas& atlas)
{
    atlases.push_back(atlas);

    if (getSize() == 1)
    {
        starts.push_back(0); //number of textures in the atlas * index size
        //so for example, using rectangles you need 24 bytes per texture * atlas size
        //24 = 6 index * 4 bytes each(unsigned int)
    }
    else
    {
        unsigned int total = 0;
        for (unsigned int n = 0; n < getSize()-1; n++)
        {
            total += total + atlases.at(n).getAtlasSize();
        }
        starts.push_back(total * getIndexSize());
    }
}

TextureAtlas& TextureAtlasController::modifyAtlas(unsigned int index)
{
    return atlases.at(index);
}

//gets
const TextureAtlas& TextureAtlasController::getAtlas(unsigned int index)
{
    return atlases.at(index);
}

unsigned int TextureAtlasController::getAtlasStart(unsigned int index) const
{
    return starts.at(index);
}

unsigned int TextureAtlasController::getIndexSize() const
{
    return index_size;
}

unsigned int TextureAtlasController::getSize() const
{
    return atlases.size();
}

//sets
void TextureAtlasController::setIndexSize(unsigned int size)
{
    index_size = size;
}
