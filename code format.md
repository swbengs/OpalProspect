##C89 and C99(VS 2015 may support some C99, I am not too sure though)
##C++ 11(https://en.wikipedia.org/wiki/C%2B%2B11 so there won't be confusion)

#Convetions
Try your best to use C++ 11 features when possible. If you find more places with pointer = NULL feel free to change it to nullptr instead. Not a big deal but it's nice to stay consistent. auto is real handy when dealing with iterators for example.

1. C code should have .h and .c file extensions
2. C++ code should use .hpp and .cpp file extensions

#Coordinate handedness
All code is to be written as left handed. All matrix assume this is the case. Old style OpenGL switched to right hand for the perspective matrix, but I want to stay consistent the entire way. Any modeling program worth anything should be able to output them in a left coordinate system no problem.
Therefore, once again everything is written for left hand. +X is right, +Y is up, +Z is heading out from the camera.
Models face the camera meaning their front is at -z. The models right is at -x, and it's left goes to the +x. Support for rotation exists so any model facing the wrong way can be rotated to face properly.

#Class, local, and other naming conventions
Classes are named with a capital first letter and all other words start with a capital letter. MyClass is an example.
Class members and local variables are all lowercase with an underscore between words. my_variable is an example.

#GLSL
GLSL variables start with i for in variables and o for out ones. iColor is a color coming into the shader, oColor is heading out. This may change when the shaders get more complicated.
Variables that are not in or out ones should be lowercase.

1. Vertex shaders are .vert extension
2. Fragment shaders are .frag extension
3. Geometry shaders are .geom extension
4. 3.3 does not support tesselation or compute shaders so don't worry about them.

