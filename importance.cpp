//
// Created by 徳備彩人 on 2020/03/15.
//

#include <iostream>
#include <cmath>
#include <random>

double f(double x) {
    return (x + 1) * std::cos(x);
}

double p(double x) {
    return std::cos(x);
}

double Pinv(double x) {
    return std::asin(x);
}

int main() {
    const int N = 100;
    std::random_device rnd_dev;
    std::mt19937 mt(rnd_dev());
    std::uniform_real_distribution<> dist(0, 1);

    double sum = 0;
    for (int i = 0; i < N; i++) {
        double u = dist(mt);
        double x = Pinv(u);
        sum += f(x)/p(x);
    }
    sum /= N;
    std::cout << sum << std::endl;

    return 0;
}