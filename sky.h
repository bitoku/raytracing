//
// Created by 徳備彩人 on 2020/03/16.
//

#ifndef RAYTRACING_SKY_H
#define RAYTRACING_SKY_H

#include "vec3.h"
#include "ray.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

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

class IBL : public Sky {
public:
    int width{};
    int height{};

    float* hdr_image;
    explicit IBL(const std::string& filename) {
        int n;
        hdr_image = stbi_loadf(filename.c_str(), &width, &height, &n, 0);
    }
    ~IBL() {
        stbi_image_free(hdr_image);
    }

    Vec3 getRadiance(const Ray& ray) const override {
        double theta = std::acos(ray.direction.y);
        double phi = std::atan2(ray.direction.z, ray.direction.x);
        if (phi < 0) phi += 2 * M_PI;

        int i = int(phi / (2 * M_PI) * width);
        int j = int(theta / M_PI * height);

        int idx = 3 * i + 3 * width * j;

        return {hdr_image[idx], hdr_image[idx+1], hdr_image[idx+2]};
    }
};
#endif //RAYTRACING_SKY_H
