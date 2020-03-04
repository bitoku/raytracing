//
// Created by 徳備彩人 on 2020/03/04.
//

#include <iostream>
#include "ray.h"

int main() {
    Ray r(Vec3(0, 0, 0), Vec3(0, 0, 1));
    std::cout << r << std::endl;
    std::cout << r(10) << std::endl;

    return 0;
}
