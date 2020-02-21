#pragma once

//std lib includes
#include <vector>

//other includes
#include "NaturalTerrain.hpp"
#include "..\Shapes\ModelIndex.hpp"
#include "..\OpenGL\ModelController.hpp" //not the best way but we need access to the already created model info to make our own

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
Description: Class to convert natural terrain class into a model that can be drawn. We only store the blocks/floors that have at least one face to be drawn.
*/

class NaturalTerrainModelBuilder
{
public:
    void loadFromFile(std::string filename, const ModelController& model_controller, ModelIndex& terrain_model);
    void loadFromMemory(const NaturalTerrain& memory, const ModelController& model_controller, ModelIndex& terrain_model); //reads from the given natural terrain and model controller to add faces to the given model for the terrain
    void debugLoadFromMemory(const NaturalTerrain& memory); //good for testing and debugging

    Point3DUInt getWorldDimensions() const;

private:
    struct natural_tile_draw_info //struct for what needs to be added to the model, as in what is drawn. 
    {
        //sides that should be drawn
        bool left;
        bool right;
        bool bottom;
        bool top;
        bool front;
        bool back;
        unsigned int tile_index; //what natural tile to grab from
        DF_Draw_Tile_Type shape;
    };

    // Struct to store needed info on what to draw for a merged face collection
    struct natural_merge_tile_draw_info
    {
        // Sides that should be drawn
        bool left;
        bool right;
        bool bottom;
        bool top;
        bool front;
        bool back;

        unsigned int tile_index; // Natural tile to grab from for origin coordinates and material info
        DF_Draw_Tile_Type shape;

        float width; // X total for merged faces(1 to N)
        float height; // Y total for merged faces(1 to N)
        float length; // Z total for merged faces(1 to N)
    };

    std::vector<natural_tile_draw_info> tiles; //only blocks that have at least one side to be drawn are added here
    std::vector<natural_merge_tile_draw_info> merged_tiles;
    NaturalTerrain terrain;

    void addTile(natural_tile_draw_info tile);
    void create(Point3DUInt dimensions);
    
    bool isSolid(DF_Draw_Tile_Type type) const; //check if the type is solid
    bool shouldDraw(const natural_tile_draw_info& info) const; //final check to see if we should add this tile to be drawn

    void freeData();

    //methods to build the model
    void addBoxFace(NormalFace face, const Point3D& offset, ModelIndex& terrain_model) const; //add offset to all vertex and then add the model
    void addBoxFaces(unsigned int current_index, unsigned int tile_position_index, const ModelIndex& box_model, ModelIndex& terrain_model, bool is_floor) const; //checks if proper bool is set and adds the face with the proper offset
    void buildModelNaive(const ModelController& model_controller, ModelIndex& terrain_model); //takes the natural tile draw info and uses that to access the models data directly along with the coordinates to place and rotate the face(s) correctly. And those faces are added to the model
    void checkingLoopNaive(); //method that contains the main loop to check all terrain for what should be drawn
    void checkingLoopMergeSimple(); // Loop to check only X and Z axis for merging
    void checkNeighbors(natural_tile_draw_info& tile, bool is_floor); //takes index of current block and will handle cases for all neighbors. Modifies given tile info pod
    void checkHorizontalTile(bool& side, unsigned int start_index, unsigned int check_index, DF_Draw_Tile_Type current_shape); //check given tile side in vs the index passed in. Sets the boolean. Only checks x and z axis
    void checkVerticalTile(bool& side, unsigned int start_index, unsigned int check_index, bool is_floor, bool checking_up); //same as above but checks y axis
};

