//
// Created by 徳備彩人 on 2020/03/15.
//

#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

#include "vec3.h"

class Light {
public:
    Vec3 color;

    explicit Light(const Vec3& _color) : color(_color) {};

    Vec3 Le() const {
        return color;
    }
};

#endif //RAYTRACING_LIGHT_H
