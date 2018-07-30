#pragma once

//std lib includes
#include <string>
//other includes
#include "tile_types.hpp"
#include "natural_tiles.hpp"

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
Description: This class is for storing a single natural tile. This means a ramp, liquid, block, or floor that is made of soil, rough stone, ore, gems, and liquids. Nothing smoothed or constructed by a dwarf
These tiles comprise the entire world before dwarves modify it with constructions. Will need # of blocks in the map times 2 natural tiles. one for the floor and one for the block itself
*/

class NaturalTile
{
public:
    NaturalTile();

    //gets
    DF_Natural_Tile_Material getTileMaterial() const;
    DF_Draw_Tile_Type getDrawType() const;

    //sets
    void setTileMaterial(DF_Natural_Tile_Material type);
    void setDrawType(DF_Draw_Tile_Type type);
private:
    DF_Natural_Tile_Material tile_material; //used to get texture information
    DF_Draw_Tile_Type draw_type; //used to see if it is drawn, and if so what kind of model to draw and so on
};

