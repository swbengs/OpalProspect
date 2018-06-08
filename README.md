# OpalProspect
Public repository for Opal Prospect, a 3D viewer for Dwarf Fortress.

This project is to allow you to save fortress info from a LUA script, and then keep that forever. It will allow you to save it at 
embark, anytime during your play session, and whenever you feel the fortress is done. You will be able to see how the fort grew.
Currently I am still working on the draw engine, and no support is yet available to grab information from DFHack.

# TODO and WIP
1. Change all text files to markdown files and make them pretty. Add more information about design.
2. Keep adding to draw engine so we hit version 0.1 before the summer is over.
3. Get more DF images and convert to 16x16 pixel textures for list item above this one.
4. CMake support so it isn't a windows only program. All the major code bits should work with other OS. Have to make a way of changing the directory paths to be OS independant though.

### Info about how to write code is currently in code format.md.

### Info about the current design is in design.md.

### Info on building is in built.md

### Info on running is in run.md

## MIT license. Include in all files just to be safe. Stored in LICENSE.md

Currently it is designed to be built in Microsoft Visual Studio 2015. I want to add support for CMake later so it can easily be built on other platforms.

# Thank you to DFHack, GLEW, GLFW, GLM, LibPNG, and ZLib for their open source code. Without you and your teams, none of this would be possible!

Lib name | Lib version | Website | License
-------- | ----------- | ------- | -------
DFHack | 43.05 r1 | https://github.com/DFHack/dfhack | Zlib
GLEW | 1.13.0 | https://github.com/nigels-com/glew | https://github.com/nigels-com/glew#copyright-and-licensing
GLFW | 3.1.2 | http://www.glfw.org/ | Zlib/libpng
GLM | 0.9.7.1 | https://glm.g-truc.net/0.9.9/index.html | http://glm.g-truc.net/copying.txt
LibPNG | 1.6.20 | http://www.libpng.org/pub/png/libpng.html | http://www.libpng.org/pub/png/src/libpng-LICENSE.txt
ZLib | 1.2.8 | https://zlib.net/ | Zlib

#### All the license files I could find are now added to the folder with their source code in case there is any confusion. If their license appeared to be different I just included a link to their site license info. If any of this information is wrong let me know and I'll correct it ASAP.

