#include <iostream>
#include "invert.h"
#include "Image_Class.h"

using namespace std;

void invert (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                image(i,j,k) = 255 - image(i,j,k);
            }
        }
    }
    cout << "Image is inverted successfully!\n";
}