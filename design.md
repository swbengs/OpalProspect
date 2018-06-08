This document is an overview of what's been done and what still needs to be done. Try to keep this about general topics and not specifics.
This is to help give an idea what needs to be done and what is currently being worked on. Further below I go into specifics about what is being done and why.

##Updated: 6/8/2018

#Critical issues(try and do this first)
1. Code cleanup and license adding. Much of the code is fairly old and should be updated to include the license and the some basic description of what it does.
All headers should have license info now. Need to check that they all have a description about what they do.(All files should have a license last I checked. Many are missing a description still)

#Language(s)
C(almost entirely only for supported libraries)
C++ 11(bulk of the project)
LUA 5.2(the version that DFHack was using last I checked. Will be used to write script to gather fortress map data)
OpenGL 3.3 and it's GLSL shader language(version 3.3 I believe the number is. Check the provided shader files for the exact number)

#Draw engine specifics
1. OpenGL 3.3 is the version I am building for. Allows more modern shader programming without requiring too new of a card. 4.5 support may be added at a later date when more important features are done(no promises though).
2. Array Textures(Finished) 16x16 pixel textures currently. Anyone is free to add their own higher quality textures.
3. Indexed models aka gl draw elements(good progress)
4. Basic shadow maps(not started)
5. Simple models for workstations and other built structures.
6. Currently all data is broken up and stored in multiple VBOs. Vertex, UV, and normals each have a seperate buffer. Might be easier to manage if it was all interweaved instead. Hampers our ability to change model data though. Tradeoffs!

#Dwarf Fortress stuff
1. LUA script to extract map info(not started)
2. Way of reading in file created by LUA script into visualizer(not started)
3. Textures for all terrain types(started but only barely) See the screenshots included and the 8x12 pixel copies from DF. Re draw as 16x16 pixel textures. Actual realistic textures or your own style are more than welcome! I am not an artist.

#Current ideas/plans
1: Terrain will be done as an two interweaved grids. One for the tiles themself, and one for the floors that seperate them. 
This will allow the two types to be the same or even different. I already have a 2D and 3D grid class read to go. Won't be hard to make
one that allows an offset, and then combine two offset grids to make this single class. Will be used to generate what tiles/floors are 
visiable and make either one or multiple models to be drawn. 

#Current WIP(s)
1. Finishing model drawing automation. Currently you can load them in and fill in the model POD to draw, but it should all be filled in
by the system.(DONE just needs actual tests written to make sure it works correctly. Appears to work when used to draw)
2. Getting most of the test world's map textures placed correctly for first attempt at drawing the DF world
3. Write ArrayTextureController to be simlar to model controller.(DONE)
4. 


#Specifics
-=Finishing model drawing automation=-
Currently can look up with model name which VAO it exists in. Need to be able to store and lookup textures by name as well. Should be able
to use the name only, and not the full path. Requires rewritting ArrayTexture.cpp a little and adding a texture controller.

Need VAO reference, texture reference, which is their opengl binding location, the index offset, and count of indicies. 
The offest refers tothat specific VAO only. Since a model can contain any number of them we must save this location and have a way to 
look it up. With thesewe can draw any model on command. The other info is just there for help, errors, and debuging.

An example is a box. It's a 3D rectangle which may be a cube. It has 6 faces made up of 2 triangles each that share two verticies each.
Thus you can store each face as 4 unique verticies and use 6 indicies per face to describe them. Thus 36 indicies and 24 verticies.
If you had multiple boxes in a VAO(yes it's actually stored in a VBO but we can bind just the VAO to use them) 
you can just do 36 * wanted_box as offset and 36 for the count. However, we can store any model in a VAO

#Dwarf Fortress textures
My current system is to copy the actual texture from DF. This is an 8x12 image. Then I draw by hand a similar one in 16x16 and color it the same.
Once we have all of the different types we just need the color info. Writing a system to do this automatically will take too long so I do it by hand.
