#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

constexpr int IMAGE_WIDTH = 1024;
constexpr int IMAGE_HEIGHT = 768;
constexpr char IMAGE_PATH[] = "./out.ppm";

void generateFrameBuffer(std::vector<Vec3f>& framebuffer, int width, int height) {
    for (size_t rowIndex = 0; rowIndex<height; rowIndex++) {
        for (size_t columnIndex = 0; columnIndex<width; columnIndex++) {
            framebuffer[columnIndex+rowIndex*width] = Vec3f(rowIndex/float(height),columnIndex/float(width), 0);
        }
    }
}

void writeFrameBuffer(const std::vector<Vec3f>& framebuffer, int width, int height) {
    std::ofstream ofs(IMAGE_PATH);
    ofs << "P6\n" << width << " " << height << "\n255\n";

    for (size_t pixelIndex = 0; pixelIndex < height*width; ++pixelIndex) {
        for (size_t colorIndex = 0; colorIndex<3; colorIndex++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[pixelIndex][colorIndex])));
        }
    }
}

void render() {
    std::vector<Vec3f> framebuffer(IMAGE_WIDTH*IMAGE_HEIGHT);
    generateFrameBuffer(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);
    writeFrameBuffer(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);
}

int main() {
    render();
    system("open ./out.ppm");
    return 0;
}
