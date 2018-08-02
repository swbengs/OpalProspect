#version 330
uniform sampler2DArray uniTexture;
in vec3 UVZ;
out vec4 color;

void main()
{
    color = texture(uniTexture, UVZ);
}