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
*/

class NaturalTile
{
public:
    NaturalTile();

    //gets
    DF_Natural_Tile getTileType() const;
    DF_DrawTileType getDrawType() const;

    //sets
    void setTileType(DF_Natural_Tile type);
    void setDrawType(DF_DrawTileType type);
private:
    DF_Natural_Tile tile_type; //used to get texture information
    DF_DrawTileType draw_type; //used to see if it is drawn, and if so what kind of model to draw and so on
};

