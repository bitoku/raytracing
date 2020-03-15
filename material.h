//
// Created by 徳備彩人 on 2020/03/15.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "vec3.h"
#include "random.h"

class Material {
public:
    virtual Vec3 sample(const Vec3& wo, Vec3& wi, double& pdf) const = 0;
};

class Diffuse : public Material {
public:
    Vec3 rho;

    explicit Diffuse(const Vec3& _rho) : rho(_rho) {};

    Vec3 sample(const Vec3& wo, Vec3& wi, double& pdf) const override {
        double u = rnd();
        double v = rnd();
        double theta = 0.5 * std::acos(1 - 2*u);
        double phi = 2 * M_PI * v;

        double x = std::cos(phi) * std::sin(theta);
        double y = std::cos(theta);
        double z = std::sin(phi) * std::sin(theta);
        wi = Vec3(x, y, z);

        pdf = std::cos(theta) / M_PI;

        return rho / M_PI;
    }
};

Vec3 reflect(const Vec3& v, const Vec3& n) {
    return -v + 2*dot(v, n) * n;
}

double cosTheta(const Vec3& v) {
    return v.y;
}

class Mirror : public Material {
public:
    Mirror() = default;;

    Vec3 sample(const Vec3& wo, Vec3& wi, double& pdf) const override {
        wi = reflect(wo, Vec3(0, 1, 0));

        pdf = 1.0;
        return 1 / cosTheta(wi) * Vec3(1);
    }
};
#endif //RAYTRACING_MATERIAL_H
