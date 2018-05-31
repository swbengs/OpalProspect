#version 330
layout (location = 0) in vec4 inVertex;
layout (location = 1) in vec3 inUV;
out vec3 UV;

uniform mat4 MVP;

void main()
{
    UV = inUV;

    gl_Position = MVP * inVertex;
}