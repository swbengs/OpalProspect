//class header
#include "NaturalTile.hpp"

//std lib includes

//other includes

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

NaturalTile::NaturalTile()
{
    tile_material = DF_Natural_Tile_Material(0);
    draw_type = DF_Draw_Tile_Type(0);
}

DF_Natural_Tile_Material NaturalTile::getTileMaterial() const
{
    return tile_material;
}

DF_Draw_Tile_Type NaturalTile::getDrawType() const
{
    return draw_type;
}

void NaturalTile::setTileMaterial(DF_Natural_Tile_Material type)
{
    tile_material = type;
}

void NaturalTile::setDrawType(DF_Draw_Tile_Type type)
{
    draw_type = type;
}
