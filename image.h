//
// Created by 徳備彩人 on 2020/03/04.
//

#ifndef RAYTRACING_IMAGE_H
#define RAYTRACING_IMAGE_H

#include <fstream>
#include "vec3.h"
#include "util.h"

class Image {
public:
    int width;
    int height;
    Vec3* data;

    Image(int _width, int _height) : width(_width), height(_height) {
        data = new Vec3[width*height];
    }
    ~Image() {
        delete[] data;
    }

    Vec3 getPixel(int i, int j) const {
        return data[i + width*j];
    }

    void setPixel(int i, int j, const Vec3& c) {
        data[i + width*j] = c;
    }

    void addPixel(int i, int j, const Vec3& c) {
        data[i + width*j] = data[i + width*j] + c;
    }

    void divide(double k) {
        for (int i = 0; i < width; i++) {
            for (int j = 0;j < height; j++) {
                this->setPixel(i, j, this->getPixel(i, j)/k);
            }
        }
    }

    void gamma_correction() {
        const double gamma = 1 / 2.2;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                Vec3 c = this->getPixel(i, j);
                this->setPixel(i, j, Vec3(std::pow(c.x, gamma), std::pow(c.y, gamma), std::pow(c.z, gamma)));
            }
        }
    }

    void ppm_output(const std::string& filename) const {
        int tone = 255;
        std::ofstream file(filename);
        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << tone << std::endl;
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                Vec3 c = this->getPixel(i, j);
                int r = clamp(int(255*c.x), 0, tone);
                int g = clamp(int(255*c.y), 0, tone);
                int b = clamp(int(255*c.z), 0, tone);
                file << r << " " << g << " " << b << std::endl;
            }
        }
        file.close();
    }
};

#endif //RAYTRACING_IMAGE_H
