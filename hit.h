//
// Created by 徳備彩人 on 2020/03/05.
//

#ifndef RAYTRACING_HIT_H
#define RAYTRACING_HIT_H

#include "vec3.h"

const int COLLISION_MAX = 10000;

class Sphere;

class Hit {
public:
    double t;  // 衝突距離
    Vec3 hitPos;
    Vec3 hitNormal;
    const Sphere* hitSphere{};

    Hit() {
        t = COLLISION_MAX;
    }
};
#endif //RAYTRACING_HIT_H
