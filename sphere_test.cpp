//
// Created by 徳備彩人 on 2020/03/05.
//

#include "sphere.h"

int main() {
    Sphere s(Vec3(0, 0, 0), 1);
    Ray ray(Vec3(0, 0, -3), Vec3(0, 0, 1));
    Hit res;

    if (s.intersect(ray, res)) {
        std::cout << res.hitPos << std::endl;
    } else {
        std::cout << "No intersect" << std::endl;
    }

    return 0;
}