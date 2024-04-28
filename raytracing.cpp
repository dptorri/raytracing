#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

constexpr int IMAGE_WIDTH = 1024;
constexpr int IMAGE_HEIGHT = 768;
constexpr char IMAGE_PATH[] = "./out.ppm";

/**
 * @brief Generate the frame buffer with color values.
 *
 * This function generates a frame buffer with color values based on the given width and height.
 * Each element of the frame buffer is a Vec3f object representing the color of a pixel.
 *
 * @param[in,out] framebuffer The vector representing the frame buffer.
 * @param[in] width The width of the frame buffer.
 * @param[in] height The height of the frame buffer.
 */
void generateFrameBuffer(std::vector<Vec3f> &framebuffer, size_t width, size_t height) {
    for (size_t rowIndex = 0; rowIndex < height; rowIndex++) {
        for (size_t columnIndex = 0; columnIndex < width; columnIndex++) {
            framebuffer[columnIndex + rowIndex * width] = Vec3f(
                    static_cast<float>(rowIndex) / static_cast<float>(height),
                    static_cast<float>(columnIndex) / static_cast<float>(width),
                    0.0f
            );
        }
    }
}

/**
 * @brief Writes the color of a pixel to a file.
 *
 * This function takes an output file stream and the color of a pixel, and writes the color to the file.
 * The color is represented by a Vec3f object, which is a typedef for a vector of three floats.
 *
 * The function iterates over the three color components of the pixel color (red, green, and blue),
 * and writes each component as a character to the file. The value of each component is clamped to
 * the range [0, 1] and scaled to the range [0, 255] before being written to the file.
 *
 * @param ofs The output file stream to write to.
 * @param pixelColor The color of the pixel to be written.
 */
static inline void writePixelToFile(std::ofstream& ofs, const Vec3f& pixelColor) {
    for (size_t colorIndex = 0; colorIndex < 3; colorIndex++) {
        ofs << (char) (255 * std::max(0.f, std::min(1.f, pixelColor[colorIndex])));
    }
}

/**
 * @brief Writes a framebuffer to a file in PPM format.
 *
 * This function takes a framebuffer represented by a vector of Vec3f objects
 * and writes it to a file in PPM format at the specified image path. The width
 * and height of the framebuffer must also be provided. The pixel color values
 * are written as RGB values with a maximum value of 255.
 *
 * @param framebuffer The framebuffer to write.
 * @param width The width of the framebuffer.
 * @param height The height of the framebuffer.
 *
 * @note The output file is overwritten if it already exists.
 */
void writeFrameBuffer(const std::vector<Vec3f> &framebuffer, size_t width, size_t height) {
    std::ofstream ofs(IMAGE_PATH);
    ofs << "P6\n" << width << " " << height << "\n255\n";

    for (size_t pixelIndex = 0; pixelIndex < height * width; ++pixelIndex) {
        writePixelToFile(ofs, framebuffer[pixelIndex]);
    }
}

/**
 * @brief Render the frame buffer.
 *
 * This function renders the frame buffer by generating the color values for each pixel,
 * writing the frame buffer to a file using the P6 format, and saving it to the specified file path.
 * The width and height of the frame buffer is determined by the constants IMAGE_WIDTH and IMAGE_HEIGHT.
 * The generated color values for each pixel are based on the pixel's position in the frame buffer.
 * The frame buffer is represented as a vector of Vec3f objects, where each Vec3f object represents
 * the color of a pixel.
 */
void render() {
    std::vector<Vec3f> framebuffer(IMAGE_WIDTH * IMAGE_HEIGHT);
    generateFrameBuffer(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);
    writeFrameBuffer(framebuffer, IMAGE_WIDTH, IMAGE_HEIGHT);
}

int main() {
    render();
    system("open ./out.ppm");
    return 0;
}
