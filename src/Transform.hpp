#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include <glm/glm.hpp>

struct Transform
{
    glm::vec2 position;
    glm::vec2 scale;
    float angle;
};

#endif