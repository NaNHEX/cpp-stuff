#pragma once
#include <random>
#include <iostream>
#include <cmath>

class Image {
public:
    int m_pixels[512][512];

    Image ();

    Image (int pixels[512][512]);

    Image (const Image &otherimage);

    friend std::ostream& operator<< (std::ostream &out, Image& image);

    friend bool compare (Image &image1, Image &image2);
};