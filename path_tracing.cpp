//
// Created by 徳備彩人 on 2020/03/15.
//

#include <memory>
#include <omp.h>
#include "image.h"
#include "camera.h"
#include "material.h"
#include "light.h"
#include "aggregate.h"
#include "radiance.h"

int main() {
    const int N = 100;

    Image img(512, 512);
    PinholeCamera cam(Vec3(0, 0, -0.5), Vec3(0, 0, -1), 1);

    auto mat1 = std::make_shared<Mirror>();
    auto mat2 = std::make_shared<Diffuse>(Vec3(0.2, 0.2, 0.8));

    auto light1 = std::make_shared<Light>(Vec3(0));
    auto light2 = std::make_shared<Light>(Vec3(0.2, 0.2, 0.8));

    Aggregate aggregate;
    aggregate.add(std::make_shared<Sphere>(Vec3(0, -10001, 0), 10000, mat1, light1));
    aggregate.add(std::make_shared<Sphere>(Vec3(0, 0, -3), 1, mat2, light2));

    #pragma omp parallel for default(none) shared(img, aggregate, cam, std::cout) schedule(dynamic, 1)
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            for (int k = 0; k < N; k++) {
                double u = (2.0 * (i + rnd()) - img.width) / img.width;
                double v = (2.0 * (j + rnd()) - img.height) / img.height;

                Ray ray = cam.getRay(-u, -v);

                Vec3 col = radiance(ray, aggregate);

                img.addPixel(i, j, col);
            }

            if (omp_get_thread_num() == 0) {
                std::cout << double(j + i * img.height) / (img.width * img.height) * 100 << "\r" << std::flush;
            }
        }
    }

    img.divide(N);
    img.gamma_correction();
    img.ppm_output("path_tracing.ppm");
    return 0;
}