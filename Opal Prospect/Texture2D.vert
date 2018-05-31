#version 330
layout (location = 0) in vec4 inVertex;
layout (location = 1) in vec2 inUV;
out vec2 UV;

uniform mat4 MVP;

void main()
{
    UV = inUV;

    gl_Position = MVP * inVertex;
}
