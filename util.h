//
// Created by 徳備彩人 on 2020/03/04.
//

#ifndef RAYTRACING_UTIL_H
#define RAYTRACING_UTIL_H
template <typename T>

T clamp(T x, T xmin, T xmax) {
    if (x < xmin) return xmin;
    else if (x > xmax) return xmax;
    else return x;
}

#endif //RAYTRACING_UTIL_H
