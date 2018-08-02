#version 330
layout (location = 0) in vec4 vertex;
layout (location = 1) in vec3 UV;
layout (location = 2) in vec4 normal;

out vec3 UVZ; //texture coordinates
out vec3 light_color; //final color of all light calculated in vertex shader

uniform mat4 MVP; //the standard
uniform vec3 ambient_color;
uniform vec3 sun_light_color;
uniform vec4 sun_light_direction;

void main()
{
    UVZ = UV;

    float brightness = dot(sun_light_direction, normal);
    brightness = clamp(brightness, 0.0, 1.0);

    light_color = brightness * sun_light_color;

    light_color.x = clamp(light_color.x, ambient_color.x, 1.0); //make sure it is at least ambient light level but not higher than 1
    light_color.y = clamp(light_color.y, ambient_color.y, 1.0); //make sure it is at least ambient light level but not higher than 1
    light_color.z = clamp(light_color.z, ambient_color.z, 1.0); //make sure it is at least ambient light level but not higher than 1
    gl_Position = MVP * vertex;
}
