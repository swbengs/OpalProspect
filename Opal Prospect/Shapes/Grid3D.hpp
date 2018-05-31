#pragma once

#include <vector>
#include "Shapes\CenterBox.hpp"

//Creates a grid in the first quadrant with a given width and height. The first rectangle's bottom left will be at 0,0. The last rectangle will be the furthest top right. All rectangles are of equal size.

class Grid3D
{
public:
    Grid3D();

    void create(); //create the grid. Any previous grid is deleted and only the new one will exist.

    //gets
    int getGridSize() const;
    int getGridWidth() const;
    int getGridHeight() const;
    int getGridLength() const;

    float getBoxWidth() const;
    float getBoxHeight() const;
    float getBoxLength() const;
    CenterBox getBox(int index) const;
    //sets
    void setGridWidth(int width);
    void setGridHeight(int height);
    void setGridLength(int length);

    void setBoxWidth(float width);
    void setBoxHeight(float height);
    void setBoxLength(float length);

private:
    std::vector<Point3D> grid;
    Box box;

    int grid_width;
    int grid_height;
    int grid_length;
};
