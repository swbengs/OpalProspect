#pragma once

#include <vector>
#include "OpenGL\TextureAtlas.hpp"

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
