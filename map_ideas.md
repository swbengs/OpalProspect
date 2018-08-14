File to write down anything related to the dwarf fortress map. From how to split it up to be drawn, to how to store it on disk.

## Hidden flag and floors above an open space
An issue has been found where the floor above a tunnel has the hidden texture even though you should know the floor layer material. How to fix this is not easy. Either I need to store all floors as a seperate RLE string, or make an exception table.
I prefer the extra RLE. This also requires changes to the loading code and how to write out in the Lua script.

## Texture space and grass/fungus
Currently 233 texture slots are used of 256. There is way more than 20 types of grass and underground fungus. So they will eat up the remaining spots and then some. So my idea is to take soils out of the terrain texture and make one with
soils, wood, and other organic material types. Also need to have grass and fungus textures only used with floors. And only the top. Otherwise you get the hilarious problem of seeing grass underground on the ceiling and the same for fungus once you
breach the cavern.

## Blocks/Walls vs Floors
As I was testing my first script version I noticed that when you mine out a vein, the floor left behind is the layer material and not the mined out material. This is one major reason why saving the floor material as well makes sense. From below you
will only see the layer material instead of the ore/gem/HFS.

## Hidden material and the edge of the map
Another issue is doing seperate material for the floor and block/wall. To have them draw means that on the border you will see the floor as its material, but the block/wall will be the hidden texture. This will look odd. To fix it requires checking
any hidden floor that is drawn, but only on the bottom side. The top and sides should still be drawn as hidden. This requires more models or changing how we generate the terrain.

## Trees and their trunks
The tree trunks themself are classified as the wall shape. This means my script picks them up and thinks they are something to be drawn. Causes hilarious results of floating stone/soil

