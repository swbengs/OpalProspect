This document is an overview of what's been done and what still needs to be done. Try to keep this about general topics and not specifics.
This is to help give an idea what needs to be done and what is currently being worked on. Further below I go into specifics about what is being done and why.

## Updated: 8/30/2018

# Critical issues(try and do this first)
1. Code cleanup and license adding. Much of the code is fairly old and should be updated to include the license and the some basic description of what it does.
All headers should have license info now. Need to check that they all have a description about what they do.(All files should have a license last I checked. Many are missing a description still)

# Language(s)
1. C89 and C99(almost entirely only for supported libraries and mostly C89)
2. C++ 11(bulk of the project)
3. LUA 5.2(the version that DFHack was using last I checked. Will be used to write script to gather fortress map data)
4. OpenGL 3.3 and it's GLSL shader language(version 3.3 I believe the number is. Check the provided shader files for the exact number)

# Draw engine specifics
1. OpenGL 3.3 is the version I am building for. Allows more modern shader programming without requiring too new of a card. 4.5 support may be added at a later date when more important features are done(no promises though).
2. Array Textures 16x16 pixel textures currently. Anyone is free to add their own higher quality textures.
3. Indexed models aka gl draw elements
4. Basic shadow maps
5. Simple models for workstations and other built structures.
6. Interleaved and non interleaved VBO.

# Dwarf Fortress stuff
1. LUA script to extract map info(not started)
2. Way of reading in file created by LUA script into visualizer(not started)
3. Textures for all terrain types(started but only barely) See the screenshots included and the 8x12 pixel copies from DF. Re draw as 16x16 pixel textures. Actual realistic textures or your own style are more than welcome! I am not an artist.

# Current WIP(s)
1. Face merging and voxel grid
2. Getting all or most of the textures ready

# Specifics
## Finishing model drawing automation
Currently can look up with model name which VAO it exists in. Need to be able to store and lookup textures by name as well. Should be able
to use the name only, and not the full path. Requires rewritting ArrayTexture.cpp a little and adding a texture controller.

Need VAO reference, texture reference, which is their opengl binding location, the index offset, and count of indicies. 
The offest refers tothat specific VAO only. Since a model can contain any number of them we must save this location and have a way to 
look it up. With thesewe can draw any model on command. The other info is just there for help, errors, and debuging.

An example is a box. It's a 3D rectangle which may be a cube. It has 6 faces made up of 2 triangles each that share two verticies each.
Thus you can store each face as 4 unique verticies and use 6 indicies per face to describe them. Thus 36 indicies and 24 verticies.
If you had multiple boxes in a VAO(yes it's actually stored in a VBO but we can bind just the VAO to use them) 
you can just do 36 * wanted_box as offset and 36 for the count. However, we can store any model in a VAO

## Dwarf Fortress textures
My current system is to copy the actual texture from DF. This is an 8x12 image. Then I draw by hand a similar one in 16x16 and color it the same.

Once we have all of the different types we just need the color info. Writing a system to do this automatically will take too long so I do it by hand. 

All the tiles are an ASCII character so once you get the main ones drawn you just fill in the unique color for that material. 3 types of soil ASCII, which might be shared with some stone tiles.

A couple of different ore and gem ASCII art.
