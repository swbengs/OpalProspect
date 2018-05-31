#version 330
layout (location = 0) in vec2 iVertex;
layout (location = 1) in vec4 iColor;
out vec4 outColor;

void main()
{
    outColor = iColor;

    gl_Position = vec4(iVertex, 0.0, 1.0);
}