#include "OpenGL\TextureAtlasController.hpp"

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
