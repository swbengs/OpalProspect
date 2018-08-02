#version 330
layout (location = 0) in vec4 vertex;
layout (location = 1) in vec3 UV;
layout (location = 2) in vec4 normal;
out vec3 UVZ;

uniform mat4 MVP;

void main()
{
    UVZ = UV;

    gl_Position = MVP * vertex;
}