//
// Created by 徳備彩人 on 2020/03/15.
//

#ifndef RAYTRACING_RANDOM_H
#define RAYTRACING_RANDOM_H

#include <random>

std::random_device rnd_dev;
std::mt19937 mt(rnd_dev());
std::uniform_real_distribution<> dist(0, 1);

double rnd() {
    return dist(mt);
}

void sampleDisk(double& x, double& y) {
    double u1 = rnd();
    double u2 = rnd();

    x = std::sqrt(u1) * std::cos(2 * M_PI * u2);
    y = std::sqrt(u1) * std::cos(2 * M_PI * u2);
}


#endif //RAYTRACING_RANDOM_H
