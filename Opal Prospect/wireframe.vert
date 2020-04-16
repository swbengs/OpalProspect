#version 330
layout (location = 0) in vec4 inVertex;

uniform mat4 wireframeMVP;

void main()
{
    gl_Position = wireframeMVP * inVertex;
}
