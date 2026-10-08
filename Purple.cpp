#include <iostream>
#include "Purple.h"
#include "Image_Class.h"

using namespace std;

void purple (Image& image) {
    float red_factor = 0.08;
    float green_factor = 0.15;
    float blue_factor = 0.18;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            float red = image(i, j, 0) + ((255-image(i, j, 0)) * red_factor);
            float green = image(i, j, 1) * (1 - green_factor);
            float blue = image(i, j, 2) + ((255-image(i, j, 2)) * blue_factor);
            if (red > 255) red = 255;
            if (red < 0) red = 0;
            if (green > 255) green = 255;
            if (green < 0) green = 0;
            if (blue > 255) blue = 255;
            if (blue < 0) blue = 0;
            image(i, j, 0) = static_cast<unsigned char> (red);
            image(i, j, 1) = static_cast<unsigned char> (green);
            image(i, j, 2) = static_cast<unsigned char> (blue);
        }
    }
    cout << "Purple filter is applied successfully!\n";
}