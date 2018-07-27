#pragma once

#include <string>

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
Description: Declaration of the different types tiles that exist and the internal ones I use as well
*/

enum DF_DrawTileType //types used for drawing. We care about the generic type not the specific. So it can be a block without saying what kind of block eg iron/obsidian etc
{
    AIR, //empty
    BLOCK,//regular block you can mine
    FLOOR, //each block has a floor below it of the same type unless the dwarves modify it
    LIQUID, //magma or water
    RAMP //not a stair
};

enum DF_TileTypeMaterial
{
    DF_AIR, //empty tile
    DF_ASHES,
    DF_BROOK,
    DF_CAMPFIRE,
    DF_CONSTRUCTION,
    DF_DRIFTWOOD,
    DF_FEATURE,
    DF_FIRE,
    DF_FROZEN_LIQUID, //ice
    DF_GRASS_DARK,
    DF_GRASS_DEAD,
    DF_GRASS_DRY,
    DF_GRASS_LIGHT,
    DF_HFS, //happy fun stuff
    DF_LAVA_STONE,
    DF_MAGMA,
    DF_MINERAL, //pockets veins and so on
    DF_MUSHROOM,
    DF_PLANT,
    DF_POOL,
    DF_ROOT,
    DF_SOIL, //forms layers
    DF_STONE, //forms layers
    DF_TREE,
    DF_UNDERWORLD_GATE
};

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

