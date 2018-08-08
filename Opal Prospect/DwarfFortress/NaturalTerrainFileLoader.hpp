#pragma once

//std lib includes
#include <string>
#include <vector>

//other includes
#include "NaturalTerrain.hpp"

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
Description: Class to load in a file that contains the world size, a table of natural terrain blocks/floors/ramps, and finally the run length strings that represent each layer(y axis)
*/

class NaturalTerrainFileLoader
{
public:
    bool loadWorld(std::string filename, NaturalTerrain& terrain);

private:
    struct run_length_pair
    {
        unsigned char letter;
        unsigned int number;
    };

    std::vector<std::string> run_length_natural_material;
    std::vector<std::string> run_length_natural_type;
    std::unordered_map<unsigned char, DF_Natural_Tile_Material> material_table;
    std::unordered_map<unsigned char, DF_Draw_Tile_Type> type_table;


    bool readFile(std::string filename, NaturalTerrain& terrain); //read the given file and fill in the two run length vectors
    bool parseRunLengthStrings(NaturalTerrain& terrain);
};

