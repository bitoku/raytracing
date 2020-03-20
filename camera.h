//
// Created by 徳備彩人 on 2020/03/05.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "vec3.h"
#include "ray.h"

class Camera {
public:
    Vec3 camPos;
    Vec3 camForward;
    Vec3 camRight;
    Vec3 camUp;

    Camera(const Vec3& _camPos, const Vec3& _camForward) : camPos(_camPos), camForward(_camForward) {
        orthonormalBasis(camForward, camRight, camUp);

        std::cout << "camPos:" << camPos << std::endl;
        std::cout << "camForward:" << camForward << std::endl;
        std::cout << "camRight:" << camRight << std::endl;
        std::cout << "camUp:" << camUp << std::endl;
    }

    virtual Ray getRay(double u, double v) const = 0;
};

class PinholeCamera : public Camera {
public:
    double pinholeDist;

    PinholeCamera(const Vec3& _camPos, const Vec3& _camForward, const double _pinholeDist) :
        Camera(_camPos, _camForward), pinholeDist(_pinholeDist) {}

    Ray getRay(double u, double v) const override {
        Vec3 sensorPos = camPos + u * camRight + v * camUp;
        Vec3 pinholePos = camPos + camForward * pinholeDist;
        return {sensorPos, normalize(pinholePos - sensorPos)};
    };
};
#endif //RAYTRACING_CAMERA_H
