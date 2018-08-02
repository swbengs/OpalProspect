#pragma once

//std lib includes
#include <vector>

//other includes
#include "NaturalTile.hpp"
#include "..\Shapes\Grid3DYOffset.hpp"

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
Description: Class to store the natural terrain.
TODO: switch to grid class that does not save the locations. Calculate them as needed instead
*/

class NaturalTerrain
{
public:
    NaturalTerrain();

    void create();
    void create(DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type, DF_Natural_Tile_Material material);

    //gets
    NaturalTile getBlock(unsigned int index) const;
    Point3D getBlockPosition(unsigned int index) const;
    NaturalTile getFloor(unsigned int index) const;
    Point3D getFloorPosition(unsigned int index) const;
    const std::vector<NaturalTile>& getBlocks() const;
    const std::vector<NaturalTile>& getFloors() const;
    Point3DUInt getGridDimensions() const;
    size_t getCount() const;

    //sets
    void setGridDimensions(unsigned int width, unsigned int height, unsigned int length);

    void setIndexDrawType(unsigned int index, DF_Draw_Tile_Type draw_type); //useful for testing, not as much for the release version
    void setIndexDrawType(unsigned int index, DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type);
    void setIndexDrawTypeAround(unsigned int index, DF_Draw_Tile_Type block_draw, DF_Draw_Tile_Type floor_draw);
    void setIndexMaterial(unsigned int index, DF_Natural_Tile_Material material);
    void setIndexMaterial(unsigned int index, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material);
    void setIndexMaterialAround(unsigned int index, DF_Natural_Tile_Material block_material, DF_Natural_Tile_Material floor_material);
    void setLayerBlockMaterial(unsigned int layer, DF_Natural_Tile_Material material);
    void setLayerFloorMaterial(unsigned int layer, DF_Natural_Tile_Material material);
    void setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type draw_type); //useful for debug and that is all
    void setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type block_draw_type, DF_Draw_Tile_Type floor_draw_type);
    void setLayerMaterial(unsigned int layer, DF_Natural_Tile_Material material);

private:
    Grid3DYOffset block_grid;
    Grid3DYOffset floor_grid;
    std::vector<NaturalTile> blocks;
    std::vector<NaturalTile> floors;
};

