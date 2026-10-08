#include <iostream>
#include "Infrared.h"
#include "Image_Class.h"

using namespace std;

void Infrared (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                image(i,j,k) = 255 - image(i,j,k);
            }
        }
    }
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int G = image(i,j,1);
            unsigned int B = image(i,j,2);
            image.getPixel(i,j,0) = 255;
            image.getPixel(i,j,1) = G;
            image.getPixel(i,j,2) = B;
        }
    }
    cout << "Infrared is applied successfully!\n";
}