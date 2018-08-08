#pragma once

#include <string>
#include "tile_types.hpp"

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

std::string DFTileTypeMaterialString(DF_Tile_Type_Material e)
{
    switch (e)
    {
    case DF_AIR:
        return "air";
    case DF_ASHES:
        return "ashes";
    case DF_BROOK:
        return "brook";
    case DF_CAMPFIRE:
        return "campfire";
    case DF_CONSTRUCTION:
        return "construction";
    case DF_DRIFTWOOD:
        return "driftwood";
    case DF_FEATURE:
        return "feature";
    case DF_FIRE:
        return "fire";
    case DF_FROZEN_LIQUID:
        return "frozen liquid";
    case DF_GRASS_DARK:
        return "grass dark";
    case DF_GRASS_DEAD:
        return "grass dead";
    case DF_GRASS_DRY:
        return "grass dry";
    case DF_GRASS_LIGHT:
        return "grass light";
    case DF_HFS:
        return "hfs";
    case DF_LAVA_STONE:
        return "lava stone";
    case DF_MAGMA:
        return "magma";
    case DF_MINERAL:
        return "mineral";
    case DF_MUSHROOM:
        return "mushroom";
    case DF_PLANT:
        return "plant";
    case DF_POOL:
        return "pool";
    case DF_ROOT:
        return "root";
    case DF_SOIL:
        return "soil";
    case DF_STONE:
        return "stone";
    case DF_TREE:
        return "tree";
    case DF_UNDERWORLD_GATE:
        return "underworld gate";
    default:
        return "bad DF_Tile_Type_Material enum ";
    }
}

std::string DFDrawTypeString(DF_Draw_Tile_Type e)
{
    switch (e)
    {
        //gem start
    case DF_DRAW_AIR:
        return "air";
    case DF_DRAW_BLOCK:
        return "block";
    case DF_DRAW_FLOOR:
        return "floor";
    case DF_DRAW_LIQUID:
        return "liquid";
    case DF_DRAW_RAMP_NORTH:
        return "ramp_north";
    case DF_DRAW_RAMP_EAST:
        return "ramp_east";
    case DF_DRAW_RAMP_SOUTH:
        return "ramp_south";
    case DF_DRAW_RAMP_WEST:
        return "ramp_west";
    default:
        return "bad DF_Draw_Tile_Type enum ";
    }
}

std::unordered_map<std::string, DF_Draw_Tile_Type> getReverseOfDFDrawTypeStringTable()
{
    std::unordered_map<std::string, DF_Draw_Tile_Type> temp;

    for (size_t i = 0; i < DF_DRAW_TYPE_COUNT; i++)
    {
        DF_Draw_Tile_Type d = static_cast<DF_Draw_Tile_Type>(i); //so we only have to do one cast
        temp[DFDrawTypeString(d)] = d; //get string and put into table
    }

    return temp;
}
