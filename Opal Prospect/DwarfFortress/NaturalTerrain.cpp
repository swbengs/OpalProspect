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
    block_grid.setBoxWidthLengthHeight(DF_BLOCK_WIDTH, DF_BLOCK_HEIGHT, DF_BLOCK_LENGTH);
    block_grid.setYOffset(DF_FLOOR_HEIGHT);
    block_grid.setYStride(DF_FLOOR_HEIGHT);

    floor_grid.setBoxWidthLengthHeight(DF_FLOOR_WIDTH, DF_FLOOR_HEIGHT, DF_FLOOR_LENGTH);
    floor_grid.setYOffset(0.0f);
    floor_grid.setYStride(DF_BLOCK_HEIGHT);
}

void NaturalTerrain::create()
{
    block_grid.create();
    floor_grid.create();
    const size_t count = block_grid.getGridCount();
    blocks.resize(count);
    const NaturalTile floor(DF_DRAW_FLOOR, DF_ALEXANDRITE);
    floors.resize(count, floor);
}

void NaturalTerrain::create(DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type, DF_Natural_Tile_Material material)
{
    block_grid.create();
    floor_grid.create();
    const size_t count = block_grid.getGridCount();
    const NaturalTile block(block_draw_type, material);
    const NaturalTile floor(floor_draw_type, material);
    blocks.resize(count, block);
    floors.resize(count, floor);
}

NaturalTile NaturalTerrain::getBlock(unsigned int index) const
{
    assert(index < block_grid.getGridCount());
    return blocks[index];
}

Point3D NaturalTerrain::getBlockPosition(unsigned int index) const
{
    return block_grid.getBox(index).getXYZ();
}

NaturalTile NaturalTerrain::getFloor(unsigned int index) const
{
    assert(index < floor_grid.getGridCount());
    return floors[index];
}

Point3D NaturalTerrain::getFloorPosition(unsigned int index) const
{
    return floor_grid.getBox(index).getXYZ();
}

const std::vector<NaturalTile>& NaturalTerrain::getBlocks() const
{
    return blocks;
}

const std::vector<NaturalTile>& NaturalTerrain::getFloors() const
{
    return floors;
}

Point3DUInt NaturalTerrain::getGridDimensions() const
{
    return Point3DUInt(block_grid.getGridWidth(), block_grid.getGridHeight(), block_grid.getGridLength());
}

size_t NaturalTerrain::getCount() const
{
    return block_grid.getGridCount();
}

void NaturalTerrain::setGridDimensions(unsigned int width, unsigned int height, unsigned int length)
{
    block_grid.setGridWidthLengthHeight(width, height, length);
    floor_grid.setGridWidthLengthHeight(width, height, length);
}

void NaturalTerrain::setIndexDrawType(unsigned int index, DF_Draw_Tile_Type draw_type)
{
    setIndexDrawType(index, draw_type, draw_type);
}

void NaturalTerrain::setIndexDrawType(unsigned int index, DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type)
{
    assert(index < block_grid.getGridCount());
    blocks[index].setDrawType(block_draw_type);
    floors[index].setDrawType(floor_draw_type);
}

void NaturalTerrain::setIndexMaterial(unsigned int index, DF_Natural_Tile_Material material)
{
    assert(index < block_grid.getGridCount());
    blocks[index].setTileMaterial(material);
    floors[index].setTileMaterial(material);
}

void NaturalTerrain::setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type draw_type)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        blocks[i].setDrawType(draw_type);
        floors[i].setDrawType(draw_type);
    }
}

void NaturalTerrain::setLayerMaterial(unsigned int layer, DF_Natural_Tile_Material material)
{
    assert(layer < block_grid.getGridHeight());
    unsigned int layer_size = block_grid.getGridWidth() * block_grid.getGridLength();
    unsigned int start = layer_size*layer;
    for (unsigned int i = layer_size*layer; i < start + layer_size; i++)
    {
        blocks[i].setTileMaterial(material);
        floors[i].setTileMaterial(material);
    }
}

