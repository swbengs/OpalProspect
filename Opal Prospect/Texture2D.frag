#version 330
uniform sampler2D uniTexture;
in vec2 UV;
out vec4 outColor;

void main()
{
    outColor = texture(uniTexture, UV);
}