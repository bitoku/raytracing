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


#endif //RAYTRACING_RANDOM_H
