This file describes what to do in order to build the project. 

## You need the headers for GLEW, GLFW, GLM, ZLIB, and LIBPNG and their include directories added in the solution. You also require their .lib files for Windows. This project assumes that GLFW, GLEW, ZLIB, and LIBPNG are all DLL files.

All the neccesary files are in "Opal Prospect\libs". To make building easy place everything within "C:\Programming\Projects\Opal Prospect". This way you don't need to change anything and it should just build.

libs\library have the library files aka .lib, and the headers are within \glm \glew and so on. If you place the solution file in a different folder you'll have to set all the include and library include locations to be your directory. My exact library location is "C:\Programming\Projects\Opal Prospect\Opal Prospect\libs" to give you an idea how it looks.
You do this through 
1. Project->Opal Prospect properties->C/C++->General->Additional include folders for include folders
2. Project->Opal Prospect properties->Linker->Additional library directories for the library files.

### Just modify the directories I have there. They show each one that needs to be added.

