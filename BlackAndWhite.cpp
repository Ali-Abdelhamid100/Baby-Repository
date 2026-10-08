#include <iostream>
#include "BlackAndWhite.h"
#include "Image_Class.h"

using namespace std;

void black_and_white (Image& image) {
    int threshold = 128;
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int avg = 0;
            for(int k = 0 ; k < image.channels ; k++) {
                avg += image(i,j,k);
            }
            avg /= 3;
            if (avg <= threshold) {
                image.setPixel(i,j,0,0);
                image.setPixel(i,j,1,0);
                image.setPixel(i,j,2,0);
            } else {
                image.setPixel(i,j,0,255);
                image.setPixel(i,j,1,255);
                image.setPixel(i,j,2,255);
            }
        }
    }
    cout << "Black and White is applied successfully!\n";
}
