#include "Image.hpp"

Image::Image () {
    for (size_t i(0); i < 512; ++i) {
        for (size_t j(0); j < 512; ++j) {
            m_pixels[i][j] = rand() % 256;
        }
    }
}

Image::Image (int pixels[512][512]) {
    for (size_t i(0); i < 512; ++i) {
        for (size_t j(0); j < 512; ++j) {
            m_pixels[i][j] = pixels[i][j];
        }
    }
}

Image::Image (const Image &otherimage) {
    for (size_t i(0); i < 512; ++i) {
        for (size_t j(0); j < 512; ++j) {
            m_pixels[i][j] = otherimage.m_pixels[i][j];
        }
    }
}

std::ostream& operator<< (std::ostream &out, Image& image) {
    for (size_t i(0); i < 512; ++i) {
        for (size_t j(0); j < 512; ++j) {
            out << image.m_pixels[i][j] << ' ';
        }
    }
    return out;
}

bool compare (Image &image1, Image &image2) {
    for (size_t i(0); i < 512; ++i) {
        for (size_t j(0); j < 512; ++j) {
            if (image1.m_pixels[i][j] != image2.m_pixels[i][j])
                return false;
        }
    }
    return true;
}