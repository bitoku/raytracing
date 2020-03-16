//
// Created by 徳備彩人 on 2020/03/15.
//

#ifndef RAYTRACING_RADIANCE_H
#define RAYTRACING_RADIANCE_H

#include "ray.h"
#include "aggregate.h"

const int MAX_DEPTH = 500;  // the maximum number of reflection
const double ROULETTE = 0.9;  // the probability of russian roulette

Vec3 radiance(const Ray& init_ray, const Aggregate& aggregate) {
    // init_ray: initial ray
    // aggregate: the group of objects
    Vec3 col;
    Vec3 throughput(1);
    Ray ray = init_ray;

    for (int depth = 0; depth < MAX_DEPTH; depth++) {
        Hit res;
        if (aggregate.intersect(ray, res)) {
            Vec3 n = res.hitNormal;
            Vec3 s, t;
            orthonormalBasis(n, s, t);
            Vec3 wo_local = worldToLocal(-ray.direction, s, n, t);

            auto hitMaterial = res.hitSphere->material;
            auto hitLight = res.hitSphere->light;

            col += throughput*hitLight->Le();

            Vec3 brdf;
            Vec3 wi_local;
            double pdf;
            brdf = hitMaterial->sample(wo_local, wi_local, pdf);
            double cos = cosTheta(wi_local);

            Vec3 wi = localToWorld(wi_local, s, n, t);

            throughput *= brdf * cos / pdf;

            ray = Ray(res.hitPos + 0.001*res.hitNormal, wi);
        } else {
            col += throughput * Vec3(0);
            break;
        }

        if (rnd() >= ROULETTE) break;
        else throughput /= ROULETTE;
    }

    return col;
}

#endif //RAYTRACING_RADIANCE_H
