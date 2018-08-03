#version 330
uniform sampler2DArray uniTexture;

in vec3 UVZ;
in vec3 light_color;

out vec4 color;

void main()
{
    color = texture(uniTexture, UVZ) * vec4(light_color, 1.0);
}
