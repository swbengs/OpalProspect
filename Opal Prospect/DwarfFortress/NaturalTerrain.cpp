//class header
#include "NaturalTerrain.hpp"

//std lib includes
#include <assert.h>

//other includes
#include "df_constants.hpp"

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

//class code

NaturalTerrain::NaturalTerrain()
{
    //setup the boxes within the grids. Don't create or set the # of them yet
    tile_grid.setBoxWidthLengthHeight(DF_BLOCK_WIDTH, DF_BLOCK_HEIGHT, DF_BLOCK_LENGTH);
    tile_grid.setYOffset(DF_FLOOR_HEIGHT);
    tile_grid.setYStride(DF_FLOOR_HEIGHT);
}

void NaturalTerrain::create()
{
    const size_t count = tile_grid.getGridCount();
    tiles.resize(count);
}

void NaturalTerrain::create(DF_Draw_Tile_Type draw_type, DF_Natural_Tile_Material material)
{
    const size_t count = tile_grid.getGridCount();
    const NaturalTile block(draw_type, material);
    tiles.resize(count, block);
}

void NaturalTerrain::freeData()
{
    tiles = std::vector<NaturalTile>();
}

NaturalTile NaturalTerrain::getTile(unsigned int index) const
{
    assert(index < tile_grid.getGridCount());
    return tiles[index];
}

Point3D NaturalTerrain::getBlockPosition(unsigned int index) const
{
    return tile_grid.getPosition(index);
}

Point3D NaturalTerrain::getFloorPosition(unsigned int index) const
{
    // TODO: Get the position with offset so floor is placed correctly
    return tile_grid.getPosition(index);
}

const std::vector<NaturalTile>& NaturalTerrain::getTiles() const
{
    return tiles;
}

Point3DUInt NaturalTerrain::getGridDimensions() const
{
    return Point3DUInt(tile_grid.getGridWidth(), tile_grid.getGridHeight(), tile_grid.getGridLength());
}

size_t NaturalTerrain::getCount() const
{
    return tile_grid.getGridCount();
}

unsigned int NaturalTerrain::getIndexDown(unsigned int index)
{
    return tile_grid.getIndexDown(index);
}

unsigned int NaturalTerrain::getIndexUp(unsigned int index)
{
    return tile_grid.getIndexUp(index);
}

unsigned int NaturalTerrain::getIndexLeft(unsigned int index)
{
    return tile_grid.getIndexLeft(index);
}

unsigned int NaturalTerrain::getIndexRight(unsigned int index)
{
    return tile_grid.getIndexRight(index);
}

unsigned int NaturalTerrain::getIndexFront(unsigned int index)
{
    return tile_grid.getIndexFront(index);
}

unsigned int NaturalTerrain::getIndexBack(unsigned int index)
{
    return tile_grid.getIndexBack(index);
}

void NaturalTerrain::setGridDimensions(unsigned int width, unsigned int height, unsigned int length)
{
    tile_grid.setGridWidthLengthHeight(width, height, length);
}

void NaturalTerrain::setIndexDrawType(unsigned int index, DF_Draw_Tile_Type draw_type)
{
    setIndexDrawType(index, draw_type);
}

void NaturalTerrain::setIndexDrawType(unsigned int index, DF_Draw_Tile_Type draw_type)
{
    assert(index < tile_grid.getGridCount());
    tiles[index].setDrawType(draw_type);
}

void NaturalTerrain::setIndexDrawTypeN(unsigned int index, unsigned int count, DF_Draw_Tile_Type draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexDrawType(index, draw);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexDrawType(current_index, draw);
    }
}

void NaturalTerrain::setIndexDrawTypeAround(unsigned int index, DF_Draw_Tile_Type draw)
{
    const unsigned int up = tile_grid.getIndexUp(index);
    const unsigned int down = tile_grid.getIndexDown(index);
    const unsigned int left = tile_grid.getIndexLeft(index);
    const unsigned int right = tile_grid.getIndexRight(index);
    const unsigned int back = tile_grid.getIndexBack(index);
    const unsigned int front = tile_grid.getIndexFront(index);

    if (index != up)
    {
        tiles[up].setDrawType(draw);
    }

    if (index != down)
    {
        tiles[down].setDrawType(draw);
    }

    if (index != left)
    {
        tiles[left].setDrawType(draw);
    }

    if (index != right)
    {
        tiles[right].setDrawType(draw);
    }

    if (index != back)
    {
        tiles[back].setDrawType(draw);
    }

    if (index != front)
    {
        tiles[front].setDrawType(draw);
    }
}

void NaturalTerrain::setIndexDrawTypeAroundN(unsigned int index, unsigned int count, DF_Draw_Tile_Type draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexDrawTypeAround(index, draw);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexDrawTypeAround(current_index, draw);
    }
}

void NaturalTerrain::setIndexDrawTypeAroundToEdge(unsigned int index, DF_Draw_Tile_Type draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    unsigned int current_index = index;
    unsigned int previous_index;

    setIndexDrawTypeAround(current_index, draw);
    previous_index = current_index;
    current_index = function(current_index, xyz.x, xyz.y, xyz.z);

    while (current_index != previous_index)
    {
        setIndexDrawTypeAround(current_index, draw);
        previous_index = current_index;
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
    }
}

void NaturalTerrain::setIndexMaterial(unsigned int index, DF_Natural_Tile_Material material)
{
    assert(index < tile_grid.getGridCount());
    tiles[index].setTileMaterial(material);
}

void NaturalTerrain::setIndexMaterialN(unsigned int index, unsigned int count, DF_Natural_Tile_Material material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexMaterial(index, material);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexMaterial(current_index, material);
    }
}

void NaturalTerrain::setIndexMaterialAround(unsigned int index, DF_Natural_Tile_Material material)
{
    const unsigned int up = tile_grid.getIndexUp(index);
    const unsigned int down = tile_grid.getIndexDown(index);
    const unsigned int left = tile_grid.getIndexLeft(index);
    const unsigned int right = tile_grid.getIndexRight(index);
    const unsigned int back = tile_grid.getIndexBack(index);
    const unsigned int front = tile_grid.getIndexFront(index);

    if (index != up)
    {
        tiles[up].setTileMaterial(material);
    }

    if (index != down)
    {
        tiles[down].setTileMaterial(material);
    }

    if (index != left)
    {
        tiles[left].setTileMaterial(material);
    }

    if (index != right)
    {
        tiles[right].setTileMaterial(material);
    }

    if (index != back)
    {
        tiles[back].setTileMaterial(material);
    }

    if (index != front)
    {
        tiles[front].setTileMaterial(material);
    }
}

void NaturalTerrain::setIndexMaterialAroundN(unsigned int index, unsigned int count, DF_Natural_Tile_Material material, unsigned int (*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    setIndexMaterialAround(index, material);
    unsigned int current_index = index;

    for (unsigned int i = 0; i < count; i++)
    {
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
        setIndexMaterialAround(current_index, material);
    }
}

void NaturalTerrain::setIndexMaterialAroundToEdge(unsigned int index, DF_Natural_Tile_Material material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int))
{
    Point3DUInt xyz = getGridDimensions();
    unsigned int current_index = index;
    unsigned int previous_index;

    setIndexMaterialAround(current_index, material);
    previous_index = current_index;
    current_index = function(current_index, xyz.x, xyz.y, xyz.z);

    while (current_index != previous_index)
    {
        setIndexMaterialAround(current_index, material);
        previous_index = current_index;
        current_index = function(current_index, xyz.x, xyz.y, xyz.z);
    }
}

void NaturalTerrain::setLayerBlockMaterial(unsigned int layer, DF_Natural_Tile_Material material)
{
    assert(layer < tile_grid.getGridHeight());
    unsigned int layer_size = tile_grid.getGridWidth() * tile_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        tiles[i].setTileMaterial(material);
    }
}

void NaturalTerrain::setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type draw_type)
{
    assert(layer < tile_grid.getGridHeight());
    unsigned int layer_size = tile_grid.getGridWidth() * tile_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        tiles[i].setDrawType(draw_type);
    }
}

void NaturalTerrain::setLayerMaterial(unsigned int layer, DF_Natural_Tile_Material material)
{
    assert(layer < tile_grid.getGridHeight());
    unsigned int layer_size = tile_grid.getGridWidth() * tile_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        tiles[i].setTileMaterial(material);
    }
}

