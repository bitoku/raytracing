//
// Created by 徳備彩人 on 2020/03/16.
//

#ifndef RAYTRACING_SKY_H
#define RAYTRACING_SKY_H

#include "vec3.h"
#include "ray.h"

class Sky {
public:
    virtual Vec3 getRadiance(const Ray& ray) const = 0;
};

class UniformSky : public Sky {
public:
    Vec3 color;

    explicit UniformSky(const Vec3& _color) : color(_color) {}

    Vec3 getRadiance(const Ray& ray) const override {
        return color;
    }
};

class SimpleSky : public Sky {
public:
    SimpleSky() = default;

    Vec3 getRadiance(const Ray& ray) const override {
        double t = (ray.direction.y * 1) / 2;
        return (1 - t) * Vec3(1) + t * Vec3(0.6, 0.7, 1);
    }
};
#endif //RAYTRACING_SKY_H
