//
// Created by 徳備彩人 on 2020/03/05.
//

#include "image.h"
#include "camera.h"
#include "sphere.h"

int main() {
    Image img(512, 512);
    PinholeCamera cam(Vec3(0, 0, 0), Vec3(0, 0, -1), 1.0);
    Sphere sphere(Vec3(0, 0, -3), 1);

    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            double u = (2.0 * i - img.width) / img.width;
            double v = (2.0 * j - img.height) / img.height;

            Ray ray = cam.getRay(-u, -v);
            Hit res;
            if(sphere.intersect(ray, res)) {
                img.setPixel(i, j, (res.hitNormal + 1) / 2);
            } else {
                img.setPixel(i, j, Vec3(0, 0, 0));
            }
        }
    }

    img.ppm_output("single_sphere_tracing.ppm");

    return 0;
}