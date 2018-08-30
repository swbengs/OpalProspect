This file describes how to run the program once it is built.

You need all the .dll files, .png files, and arrayTexture.frag and arrayTexture.vert

Full list below. All files come with the project. .exe must be built or from a project release zip.

1. arrayTexture.frag
2. arrayTexture.vert
3. glew32.dll
4. glfw3.dll
5. libpng16.dll
6. zlib.dll
7. the Textures folder(leave everything as is inside it)
8. .exe file

## DFHack and running
As of version 0.1.5 you will be asked for a terrain filename. This is your saved world data you wish to load that was generated via the Lua script.
43.05r1 is the earliest supported version of Dwarf Fortress I support. You need the same version of DFHack. Follow their instructions on how to install it. Then place opal.lua into the dfhack\scripts folder.
Run the game, load your map, and type opal filename(replace with whatever filename you want) into dfhack's terminal

## Example(assumes you have DF and DFHack installed and ready to run. Opal prospect is also ready to go. You genereated a world and embarked at a site) This is for save 1 which is a fortress embark.
1. Start Dwarf Fortress
2. Load save #1
3. Once you are ingame and paused, type "opal first.txt" without the quotes. It must be just a single word. If you want spaces use the _ to mimic spaces
4. Wait a few seconds to a minute. The file called "first.txt" will be created in your Dwarf Fortress.exe location. Mine is "C:\Users\Scott\Documents\dwarf fortress\df_43_05_r1\df plus hack\first.txt"
5. Start Opal Prospect.
6. It will ask "what file do you want to load". Give it "C:\Users\Scott\Documents\dwarf fortress\df_43_05_r1\df plus hack\first.txt" without the quotes and it will load first.txt
7. Enjoy!

You obviously will have a different path and can name the file whatever you want. You are free to place it anywhere. 
You could put it into the same directory as opal prospect.exe and then just type the name in without a path and it will work as well. so when it asks what file just enter "first.txt"

