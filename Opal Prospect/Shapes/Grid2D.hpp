#pragma once

#include <vector>
#include "CenterRectangle.hpp"

//Creates a grid in the first quadrant with a given width and height. The first rectangle's bottom left will be at 0,0. The last rectangle will be the furthest top right. All rectangles are of equal size.

class Grid2D
{
public:
    Grid2D();

    void create(); //create the grid. Any previous grid is deleted and only the new one will exist.

    //gets
    int getGridWidth() const;
    int getGridHeight() const;
    float getRectangleWidth() const;
    float getRectangleHeight() const;
    const CenterRectangle& getRectangle(int index) const;
    //sets
    void setGridWidth(int width);
    void setGridHeight(int height);
    void setRectangleWidth(float width);
    void setRectangleHeight(float height);

private:
    std::vector<CenterRectangle> grid;
    int grid_width;
    int grid_height;
    float rectangle_width;
    float rectangle_height;
    
    void fillWidthHeight(int size); //fills entire grid rectangle height and width
};
