//
// Created by 徳備彩人 on 2020/03/05.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H


#include "vec3.h"
#include "ray.h"
#include "hit.h"

class Sphere {
public:
    Vec3 center;
    double radius;
    Sphere(const Vec3& _center, double _radius) : center(_center), radius(_radius) {}

    bool intersect(const Ray& ray, Hit& res) const {
        double b = dot(ray.direction, ray.origin - center);
        double c = (ray.origin - center).length2() - radius*radius;
        double D = b*b - c;
        if (D < 0) {
            return false;
        }
        double t1 = -b - std::sqrt(D);
        double t2 = -b + std::sqrt(D);
        if (t1 > COLLISION_MAX || t2 < 0) {
            return false;
        }
        double t = t1;
        if (t < 0) {
            t = t2;
            if (t2 > COLLISION_MAX) {
                return false;
            }
        }
        res.t = t;
        res.hitPos = ray(t);
        res.hitNormal = normalize(res.hitPos - center);
        res.hitSphere = this;

        return true;
    }
};

#endif //RAYTRACING_SPHERE_H
