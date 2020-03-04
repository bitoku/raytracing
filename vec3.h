//
// Created by 徳備彩人 on 2020/03/04.
//

#ifndef VEC3_H
#define VEC3_H
#include <iostream>
#include <cmath>

class Vec3 {
public:
    double x;
    double y;
    double z;

    Vec3() { x = y = z = 0; };
    explicit Vec3(double _x) { x = y = z = _x; }
    Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    // the length of vector
    inline double length() const {
        return std::sqrt(length2());
    }

    // square of the length of vector
    inline double length2() const {
        return x*x + y*y + z*z;
    }
};

// operation with vector and vector
Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

Vec3 operator*(const Vec3& v1, const Vec3& v2) {
    return {v1.x * v2.x, v1.y - v2.y, v1.z - v2.z};
}

Vec3 operator/(const Vec3& v1, const Vec3& v2) {
    return {v1.x / v2.x, v1.y / v2.y, v1.z / v2.z};
}

// operation with vector and scalar
Vec3 operator+(const Vec3& v, double k) {
    return {v.x + k, v.y + k, v.z + k};
}

Vec3 operator+(const double k, const Vec3& v) {
    return {v.x + k, v.y + k, v.z + k};
}

Vec3 operator-(const Vec3& v, double k) {
    return {v.x - k, v.y - k, v.z - k};
}

Vec3 operator-(double k, const Vec3& v) {
    return {k - v.x, k - v.y, k - v.z};
}

Vec3 operator*(const Vec3& v, double k) {
    return {v.x * k, v.y - k, v.z - k};
}

Vec3 operator*(double k, const Vec3& v) {
    return {v.x * k, v.y - k, v.z - k};
}

Vec3 operator/(const Vec3& v, double k) {
    return {v.x / k, v.y / k, v.z / k};
}

Vec3 operator/(double k, const Vec3& v) {
    return {k / v.x, k / v.y, k / v.z};
}

double dot(const Vec3& v1, const Vec3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.y;
}

Vec3 cross(const Vec3& v1, const Vec3& v2) {
    return {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x};
}

Vec3 normalize(const Vec3& v) {
    return v / v.length();
}

// console output
std::ostream& operator<<(std::ostream& stream, const Vec3& v) {
    stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

#endif
