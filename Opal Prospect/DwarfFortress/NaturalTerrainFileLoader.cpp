//class header
#include "NaturalTerrainFileLoader.hpp"

//std lib includes
#include <sstream>
#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <stdlib.h> //atoi isdigit

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

        std::string table_input;
        file >> table_input;
        if (table_input.compare("natural_materials") != 0)
        {
            std::stringstream stream;
            stream << "Natural Material table missing from " << filename << " or is in the wrong place.\n";
            BasicLog::getInstance().writeError(stream.str());
            return false;
        }

        std::unordered_map<std::string, DF_Natural_Tile_Material> reverse_material_table = getReverseOfDFNaturalStringTable(); //string to enum table

        bool end_found = false;
        do
        {
            file >> table_input;
            if (table_input.compare("natural_materials_end") != 0 && !file.eof())
            {
                unsigned char c = table_input[0];
                file >> table_input;
                material_table[c] = reverse_material_table[table_input];
            }
            else
            {
                end_found = true;
            }
        } while (!end_found);

        file >> table_input;
        if (table_input.compare("natural_types") != 0)
        {
            std::stringstream stream;
            stream << "Natural Type table missing from " << filename << " or is in the wrong place.\n";
            BasicLog::getInstance().writeError(stream.str());
            return false;
        }

        std::unordered_map<std::string, DF_Draw_Tile_Type> reverse_type_table = getReverseOfDFDrawTypeStringTable(); //string to enum table

        end_found = false;
        do
        {
            file >> table_input;
            if (table_input.compare("natural_types_end") != 0 && !file.eof())
            {
                unsigned char c = table_input[0];
                file >> table_input;
                type_table[c] = reverse_type_table[table_input];
            }
            else
            {
                end_found = true;
            }
        } while (!end_found);

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
    unsigned int max_digits = 0;
    const unsigned int layer_size = world_width * world_length;
    double layer_size_double = static_cast<double>(layer_size); //need to do double math to check for how many digits we should make

    do
    {
        max_digits++;
        layer_size_double /= 10.0;
    } while (layer_size_double > 1.0);

    for (unsigned int i = 0; i < world_height; i++)
    {
        if (parseLayer(i, layer_size, max_digits))
        {

        }
        else
        {
            std::stringstream stream;
            stream << "issue parsing at layer number: " << i << "\n";
            BasicLog::getInstance().writeError(stream.str());
            return false;
        }
    }

    return true;
}

bool NaturalTerrainFileLoader::parseLayer(unsigned int layer, unsigned int layer_size, unsigned int max_digits)
{
    std::string single;
    single.resize(max_digits + 1); //need extra space for single character

    return true;
}

