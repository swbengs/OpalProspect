#version 330
uniform sampler2DArray uniTexture;
in vec3 UV;
out vec4 oColor;

void main()
{
    oColor = texture(uniTexture, UV);
}