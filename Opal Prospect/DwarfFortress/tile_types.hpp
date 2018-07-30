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

enum DF_Draw_Tile_Type //types used for drawing. We care about the generic type not the specific. So it can be a block without saying what kind of block eg iron/obsidian etc
{
    DF_DRAW_AIR, //empty
    DF_DRAW_BLOCK,//regular block you can mine
    DF_DRAW_FLOOR, //each block has a floor below it of the same type unless the dwarves modify it
    DF_DRAW_LIQUID, //magma or water or ice(anything with transparancy)
    DF_DRAW_RAMP_NORTH, //not a stair
    DF_DRAW_RAMP_EAST,
    DF_DRAW_RAMP_SOUTH,
    DF_DRAW_RAMP_WEST
};

enum DF_Tile_Type_Material
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

