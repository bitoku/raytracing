//
// Created by 徳備彩人 on 2020/03/04.
//

#include <fstream>

int main() {
    std::ofstream file("ppm_test.ppm");

    int width = 512;
    int height = 512;
    int tone = 255;
    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << tone << std::endl;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int r = (int)(i / (double)height * tone);
            int g = (int)(j / (double)width * tone);
            int b = tone;
            file << r << " " << g << " " << b << std::endl;
        }
    }

    file.close();
    return 0;
}
