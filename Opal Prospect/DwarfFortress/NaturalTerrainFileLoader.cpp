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
        if (parseRunLengthStrings())
        {
            createTerrain(terrain);
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

bool NaturalTerrainFileLoader::parseRunLengthStrings()
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

    const std::string& material_rle = run_length_natural_material[layer];
    const std::string& type_rle = run_length_natural_type[layer];

    unsigned int count = 0;

    unsigned int single_index = 0;
    for (size_t i = 0; i < material_rle.size(); i++)
    {
        if (isdigit(material_rle[i]))
        {
            single[single_index] = material_rle[i];
            single_index++;
            if (single_index > max_digits)
            {
                BasicLog::getInstance().writeError("number exceeds maximum digit allowance for a single layer\n");
                return false;
            }
        }
        else //add single character, the non number one and seperate the number and character
        {
            single[single_index] = material_rle[i];
            single_index = 0;
            char* end;
            unsigned long number_long = strtoul(single.data(), &end, 10);
            unsigned int number = static_cast<unsigned int>(number_long);
            unsigned char c = *end;

            if (number == 0)
            {
                BasicLog::getInstance().writeError("rle number is 0. Should be at least 1\n");
                return false;
            }

            count += number;

            if (count > layer_size)
            {
                BasicLog::getInstance().writeError("total count from rle exceeds layer size\n");
                return false;
            }

            run_length_pair pair;
            pair.letter = c;
            pair.number = number;

            material_pairs.push_back(pair);

            //reset single
            for (size_t n = 0; n < single.size(); n++)
            {
                single[n] = '\0';
            }
        }
    }

    count = 0;
    single_index = 0;
    for (size_t i = 0; i < type_rle.size(); i++)
    {
        if (isdigit(type_rle[i]))
        {
            single[single_index] = type_rle[i];
            single_index++;
            if (single_index > max_digits)
            {
                BasicLog::getInstance().writeError("number exceeds maximum digit allowance for a single layer\n");
                return false;
            }
        }
        else //add single character, the non number one and seperate the number and character
        {
            single[single_index] = type_rle[i];
            single_index = 0;
            char* end;
            unsigned long number_long = strtoul(single.data(), &end, 10);
            unsigned int number = static_cast<unsigned int>(number_long);
            unsigned char c = *end;

            if (number == 0)
            {
                BasicLog::getInstance().writeError("rle number is 0. Should be at least 1\n");
                return false;
            }

            count += number;

            if (count > layer_size)
            {
                BasicLog::getInstance().writeError("total count from rle exceeds layer size\n");
                return false;
            }

            run_length_pair pair;
            pair.letter = c;
            pair.number = number;

            type_pairs.push_back(pair);

            //reset single
            for (size_t n = 0; n < single.size(); n++)
            {
                single[n] = '\0';
            }
        }
    }

    return true;
}

void NaturalTerrainFileLoader::createTerrain(NaturalTerrain& terrain)
{
    terrain.create();
    const unsigned int world_size = world_width * world_height * world_length;

    unsigned int current_index = 0; //current of total world size
    for (size_t i = 0; i < material_pairs.size(); i++)
    {
        const unsigned char c = material_pairs[i].letter;
        const unsigned int number = material_pairs[i].number;

        for (unsigned int n = 0; n < number; n++)
        {
            terrain.setIndexMaterial(current_index, material_table[c]);
            current_index++;
        }
    }

    assert(current_index == world_size);

    current_index = 0; //current of total world size
    for (size_t i = 0; i < type_pairs.size(); i++)
    {
        const unsigned char c = type_pairs[i].letter;
        const unsigned int number = type_pairs[i].number;

        for (unsigned int n = 0; n < number; n++)
        {
            const DF_Draw_Tile_Type draw = type_table[c];
            DF_Draw_Tile_Type block_draw;
            DF_Draw_Tile_Type floor_draw;

            switch (draw)
            {
            case DF_DRAW_AIR:
                block_draw = draw;
                floor_draw = draw;
                break;
            case DF_DRAW_BLOCK:
                block_draw = draw;
                floor_draw = DF_DRAW_FLOOR;
                break;
            case DF_DRAW_FLOOR:
                block_draw = DF_DRAW_AIR;
                floor_draw = DF_DRAW_FLOOR;
                break;
            case DF_DRAW_LIQUID:
                block_draw = DF_DRAW_AIR;
                floor_draw = DF_DRAW_AIR;
            case DF_DRAW_RAMP_EAST:
                block_draw = DF_DRAW_AIR;
                floor_draw = DF_DRAW_FLOOR;
                break;
            case DF_DRAW_RAMP_NORTH:
                block_draw = DF_DRAW_AIR;
                floor_draw = DF_DRAW_FLOOR;
                break;
            case DF_DRAW_RAMP_SOUTH:
                block_draw = DF_DRAW_AIR;
                floor_draw = DF_DRAW_FLOOR;
                break;
            case DF_DRAW_RAMP_WEST:
                block_draw = DF_DRAW_AIR;
                floor_draw = DF_DRAW_FLOOR;
                break;
            default:
                block_draw = draw;
                floor_draw = draw;
            }
            terrain.setIndexDrawType(current_index, block_draw, floor_draw);
            current_index++;
        }
    }

    assert(current_index == world_size);
}

