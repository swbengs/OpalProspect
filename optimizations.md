This file describes what optimizations I have done, plan to do, or am debating.

Many of these will end up mixing but I'll try to keep them relative to what is affected more.

## Dwarf Fortress related

### Run Length Encoding(plan to)
Greatly save hard drive space when writing out the terrain data from DFHack. aaabbbbccccab can turn into 3a4b4c1a1b . The longer the run, the more space is saved.

### Voxel Grid(plan to)
Have a grid class that does not save any data except the width, height, and length of the grid. Any position needed should just be calculated off a 1D index. Could save well over 500MB on a 48x300x48 4x4 embark. That is how large 3 floats per block and per floor add up to. O.o

## OpenGL related

### Face merging(plan to)
Combine faces that are exactly the same. My version will only do x and z axis since the floors blocks inbetween are a different size. Can convert into 1/X faces per layer. X being how many of the same face show up in a row. 

So 10 in a row is 1/10th the vertex data required. 1 Big face with repeating texture vs 10 small ones.

### Array Textures(Already in use)
3.0 added new and improved texture atlas capabilties. The benefits are too large to write here. Can have up to a 256 sized array in OpenGL 3.3.

