#pragma once

//std lib includes
#include <vector>
#include <unordered_map>
#include <string>

//other includes
#include "DrawEngineStructs.hpp"
#include "ArrayTexture.hpp"

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
Description: This class stores and maintains all the textures. References start at 1 and count up. Reference of 0 is similar to null, since it does not exist
*/

class ArrayTextureController
{
public:
    void addTexture(const ArrayTexture &texture);

    void bindTexture(unsigned int reference) const;

    //gets
    size_t getCount() const;
    const ArrayTexture& getTexture(unsigned int reference) const; //for reading only
    unsigned int getTextureReference(std::string texture_name) const;
    unsigned int getTextureNumber(std::string image_name) const;

    ArrayTexture& modifyTexture(unsigned int reference); //for writing and reading
private:
    std::vector<ArrayTexture> textures;
    std::unordered_map<std::string, unsigned int> references;

    bool inBounds(unsigned int reference) const;
};

