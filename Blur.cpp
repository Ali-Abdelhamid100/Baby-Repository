#include <iostream>
#include "Blur.h"
#include "Image_Class.h"

using namespace std;

void Blur (Image& image, int radius = 15) {
    Image img = image;
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int R_avg = 0;
            unsigned int G_avg = 0;
            unsigned int B_avg = 0;
            int cnt = 0;
            for (int a = i - radius ; a <= i + radius  ; a++) {
                for (int b = j - radius ; b <= j + radius ; b++) {
                    if (a >= 0 && a < image.width && b >= 0 && b < image.height) {
                        R_avg += img(a,b,0);
                        G_avg += img(a,b,1);
                        B_avg += img(a,b,2);
                        cnt++;
                    }
                }
            }
            R_avg /= cnt;
            G_avg /= cnt;
            B_avg /= cnt;
            image.getPixel(i,j,0) = R_avg;
            image.getPixel(i,j,1) = G_avg;
            image.getPixel(i,j,2) = B_avg;
        }
    }
    cout << "Blur is applied successfully!\n";
}