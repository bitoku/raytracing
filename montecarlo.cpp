//
// Created by 徳備彩人 on 2020/03/15.
//

#include <iostream>
#include <cmath>
#include <random>

double f(double x, double y) {
    return x*x + y*y;
}

int main() {
    int N = 100;
    std::random_device rnd_dev;
    std::mt19937 mt(rnd_dev());
    std::uniform_real_distribution<> dist(0, 1);
    double mont = 0;
    for (int i = 0; i < N; i++) {
        double x = dist(mt);
        double y = dist(mt);
        mont += f(x, y) / N;
    }
    std::cout << mont << std::endl;
    return 0;
}