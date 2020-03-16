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
    explicit Vec3(double _x) : x(_x), y(_x), z(_x) {}
    Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    // the length of vector
    inline double length() const {
        return std::sqrt(length2());
    }

    // square of the length of vector
    inline double length2() const {
        return x*x + y*y + z*z;
    }

    Vec3 operator-() const {
        return {-x, -y, -z};
    }

    Vec3& operator+=(const Vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vec3& operator*=(const Vec3& v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vec3& operator/=(const Vec3& v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }

    Vec3& operator/=(double k) {
        x /= k;
        y /= k;
        z /= k;
        return *this;
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
    return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
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
    return {v.x * k, v.y * k, v.z * k};
}

Vec3 operator*(double k, const Vec3& v) {
    return {v.x * k, v.y * k, v.z * k};
}

Vec3 operator/(const Vec3& v, double k) {
    return {v.x / k, v.y / k, v.z / k};
}

Vec3 operator/(double k, const Vec3& v) {
    return {k / v.x, k / v.y, k / v.z};
}

double dot(const Vec3& v1, const Vec3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
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

void orthonormalBasis(const Vec3& v1, Vec3& v2, Vec3& v3) {
    if (v1.x != 0) v2 = Vec3(0, 1, 0);
    else v2 = Vec3(1, 0, 0);
    v2 = normalize(v2 - dot(v1, v2) * v1);
    v3 = cross(v1, v2);
}

Vec3 worldToLocal(const Vec3& v, const Vec3& s, const Vec3& t, const Vec3& n) {
    return {dot(v, s), dot(v, t), dot(v, n)};
}

Vec3 localToWorld(const Vec3& v, const Vec3& s, const Vec3& t, const Vec3& n) {
    Vec3 a = Vec3(s.x, t.x, n.x);
    Vec3 b = Vec3(s.y, t.y, n.y);
    Vec3 c = Vec3(s.z, t.z, n.z);
    return {dot(v, a), dot(v, b), dot(v, c)};
}

#endif
