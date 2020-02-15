#pragma once

//std lib includes
#include <vector>

//other includes
#include "NaturalTile.hpp"
#include "../Shapes/DFVoxelGrid.hpp"
#include "../Shapes/Point3DUInt.hpp"

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
    void create(DF_Draw_Tile_Type draw_type, DF_Natural_Tile_Material material);

    void freeData();

    //gets
    NaturalTile getTile(unsigned int index) const;
    Point3D getBlockPosition(unsigned int index) const;
    Point3D getFloorPosition(unsigned int index) const;
    const std::vector<NaturalTile>& getTiles() const;
    Point3DUInt getGridDimensions() const;
    size_t getCount() const;

    unsigned int getIndexDown(unsigned int index);
    unsigned int getIndexUp(unsigned int index);
    unsigned int getIndexLeft(unsigned int index);
    unsigned int getIndexRight(unsigned int index);
    unsigned int getIndexFront(unsigned int index);
    unsigned int getIndexBack(unsigned int index);

    //sets
    void setGridDimensions(unsigned int width, unsigned int height, unsigned int length);

    void setIndexDrawType(unsigned int index, DF_Draw_Tile_Type draw_type); //useful for testing, not as much for the release version
    void setIndexDrawTypeN(unsigned int index, unsigned int count, DF_Draw_Tile_Type draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int));
    void setIndexDrawTypeAround(unsigned int index, DF_Draw_Tile_Type draw);
    void setIndexDrawTypeAroundN(unsigned int index, unsigned int count, DF_Draw_Tile_Type draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int));
    void setIndexDrawTypeAroundToEdge(unsigned int index, DF_Draw_Tile_Type draw, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int));
    void setIndexMaterial(unsigned int index, DF_Natural_Tile_Material material);
    void setIndexMaterialN(unsigned int index, unsigned int count, DF_Natural_Tile_Material material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int));
    void setIndexMaterialAround(unsigned int index, DF_Natural_Tile_Material material);
    void setIndexMaterialAroundN(unsigned int index, unsigned int count, DF_Natural_Tile_Material material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int));
    void setIndexMaterialAroundToEdge(unsigned int index, DF_Natural_Tile_Material material, unsigned int(*function)(unsigned int, unsigned int, unsigned int, unsigned int));
    void setLayerBlockMaterial(unsigned int layer, DF_Natural_Tile_Material material);
    void setLayerDrawType(unsigned int layer, DF_Draw_Tile_Type draw_type); //useful for debug and that is all
    void setLayerMaterial(unsigned int layer, DF_Natural_Tile_Material material);

private:
    DFVoxelGrid tile_grid;
    std::vector<NaturalTile> tiles;
};

