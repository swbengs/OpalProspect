#pragma once

#include <string>

//keep track of state to reduce pipeline requests. only add the parts we're interested in
struct opengl_state
{
    unsigned int vao_id; //bound vao id
    unsigned int texture_id; //bound texture id
    unsigned int program_id; //bound program id
};

//struct to draw a model
struct model_pod
{
    //vao ref, index byte offset, texture ref needed to draw 
    unsigned int vao_reference; //what VAO to bind
    unsigned int index_offset_bytes; //where in buffer to start reading
    unsigned int index_count; //how many to turn into GL_TRIANGLES
    unsigned int texture_reference; //what texture to bind
    //helpful things to store
    std::string model_name;
    std::string texture_name;
};

//stores only the things needed to draw an object that uses a texture
struct texture_pod
{
    float x;
    float y;
    unsigned int texture_number; //in an atlas there are 1 or more textures. So if there are 256 texutres in an atlas, it could be 0 through 255
    unsigned int level; //this is the member used for ordering. Higher means it is drawn last

    bool operator< (const texture_pod& r) const
    {
        return level < r.level;
    }
};

//stores only the things needed to draw an object that uses only color
struct color_pod
{
    float x;
    float y;
    float w;
    float h;
};
