//
// Created by 徳備彩人 on 2020/03/05.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "vec3.h"
#include "ray.h"
#include "random.h"

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

class ThinLensCamera : public Camera {
public:
    double a;
    double b;
    double f;
    double lensRadius;
    Vec3 lensCenter;

    ThinLensCamera(const Vec3 &camPos, const Vec3 &camForward, const Vec3& focusPoint, double _a, double _lensRadius) :
    Camera(camPos, camForward), a(_a), lensRadius(_lensRadius) {
        double cos = dot(camForward, normalize(focusPoint - camPos));
        b = cos * (focusPoint - camPos).length() - a;
        f = 1 / (1/a + 1/b);
        lensCenter = camPos + camForward * a;
    }

    Ray getRay(double u, double v) const override {
        Vec3 sensorPos = camPos + u * camRight + v * camUp;
        Vec3 r = normalize(lensCenter - sensorPos);
        Vec3 focusPoint = sensorPos + (a + b) / dot(camForward, r) * r;

        double x, y;
        sampleDisk(x, y);
        Vec3 lensPos = lensRadius * (x * camRight + v * camUp) + lensCenter;

        return {lensPos, normalize(focusPoint - lensPos)};
    }
};
#endif //RAYTRACING_CAMERA_H
