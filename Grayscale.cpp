#include <iostream>
#include "Grayscale.h"
#include "Image_Class.h"

using namespace std;

void grayScale (Image& image) {

    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int avg = 0;

            for (int k = 0 ; k < image.channels ; k++) {
               avg += image(i,j,k);
            }
            avg /= 3;

            image.getPixel(i,j,0) = avg;
            image.getPixel(i,j,1) = avg;
            image.getPixel(i,j,2) = avg;
        }
    }
    cout << "GrayScale is applied successfully!\n";
}