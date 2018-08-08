//class header
#include "NaturalTerrainFileLoader.hpp"

//std lib includes
#include <sstream>
#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <fstream>

//other includes
#include "..\BasicLog.hpp"

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

bool NaturalTerrainFileLoader::loadWorld(std::string filename, NaturalTerrain& terrain)
{
    if (readFile(filename, terrain))
    {
        if (parseRunLengthStrings(terrain))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//private
bool NaturalTerrainFileLoader::readFile(std::string filename, NaturalTerrain& terrain)
{
    std::ifstream file;
    file.open(filename);
    if (file.is_open())
    {
        std::string version;
        unsigned int world_width, world_height, world_length;
        file >> version;
        file >> world_width;
        file >> world_height;
        file >> world_length;

        run_length_natural_material.reserve(world_height);
        run_length_natural_type.reserve(world_height);

        for (size_t i = 0; i < world_height; i++)
        {
            std::string material, type;

            file >> material;
            file >> type;

            run_length_natural_material.push_back(material);
            run_length_natural_type.push_back(type);
        }

        terrain.setGridDimensions(world_width, world_height, world_length);

        file.close();
        return true;
    }
    else
    {
        std::stringstream stream;
        stream << "terrain file " << filename << " not found\n";
        BasicLog::getInstance().writeError(stream.str());
        return false;
    }
}

bool NaturalTerrainFileLoader::parseRunLengthStrings(NaturalTerrain & terrain)
{
    std::unordered_map<std::string, DF_Natural_Tile_Material> material_table = getReverseOfDFNaturalStringTable();

    return false;
}

