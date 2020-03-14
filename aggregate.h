//
// Created by 徳備彩人 on 2020/03/05.
//

#ifndef RAYTRACING_AGGREGATE_H
#define RAYTRACING_AGGREGATE_H

#include <utility>
#include <vector>
#include <memory>
#include "sphere.h"

class Aggregate {
public:
    std::vector<std::shared_ptr<Sphere>> spheres;

    Aggregate() = default;
    explicit Aggregate(std::vector<std::shared_ptr<Sphere>> _spheres) : spheres(std::move(_spheres)) {}

    void add(const std::shared_ptr<Sphere>& s) {
        spheres.push_back(s);
    }

    bool intersect(const Ray& ray, Hit& res) const {
        bool hit = false;
        for(const auto& s : spheres) {
            Hit res_temp;
            if (s->intersect(ray, res_temp)) {
                if (res_temp.t < res.t) {
                    hit = true;
                    res = res_temp;
                }
            }
        }
        return hit;
    }
};
#endif //RAYTRACING_AGGREGATE_H
