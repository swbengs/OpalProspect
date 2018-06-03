# OpalProspectPrivate
Public repository for Opal Prospect, a 3D viewer for Dwarf Fortress.

This project is to allow you to save fortress info from a LUA script, and then keep that forever. It will allow you to save it at 
embark, anytime during your play session, and whenever you feel the fortress is done. You will be able to see how the fort grew.
Currently I am still working on the draw engine, and no support is yet available to grab information from DFHack.

TODO:
1: Add more info about what versions of the below libraries I am using and even a .dll download so you don't have to aquire and build them
yourself.
2: CMake support so it isn't a windows only program.

Info about how to write code is currently in code format.txt.

MIT license. Include in all files just to be safe. Stored in LICENSE.txt

Info about the current design is in design.txt.

Currently it is designed to be built in Microsoft Visual Studio 2015. I want to add support for CMake later so it can easily be built on other platforms.

Thank you to DFHack, GLEW, GLFW, GLM, LibPNG, and ZLib for their open source code. Without you and your teams, none of this would be possible!

This project uses the aforementioned libraries but I will list them again. Once I get used to marking up the file I will add them in a table with links, their copyright/license info and so on.
DFHack
GLEW
GLFW
GLM
LibPNG
ZLib