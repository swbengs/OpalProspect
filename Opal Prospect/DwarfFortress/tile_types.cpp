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

std::string DFTileTypeMaterialString(DF_TileTypeMaterial e)
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
        return "bad DF_TileTypeMaterial enum ";
    }
}

