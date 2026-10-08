#include <iostream>
#include "OilPainting.h"
#include "Image_Class.h"

using namespace std;

void oilPainting (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            int cnt[10] = {};
            int levels = 10;
            for (int a = i - 2 ; a <= i + 2 ; a++) {
                for (int b = j - 2 ; b <= j + 2 ; b++)
                {
                    if (a >= 0 && a < image.width && b >= 0 && b < image.height) {
                        unsigned int R = image(a,b,0);
                        unsigned int G = image(a,b,1);
                        unsigned int B = image(a,b,2);
                        int intensity = (R + G + B) / 3;
                        int level = intensity * levels / 256;
                        cnt[level]++;
                    }
                }
            }
            int mostLevel = 0;
            for (int x = 1 ; x < 10 ; x++) {
                if (cnt[x] > cnt[mostLevel]) {
                    mostLevel = x;
                }
            }
            unsigned int avg_R = 0;
            unsigned int avg_G = 0;
            unsigned int avg_B = 0;
            int counter = 0;
            for (int a = i - 2 ; a <= i + 2 ; a++) {
                for (int b = j - 2 ; b <= j + 2 ; b++)
                {
                    if (a >= 0 && a < image.width && b >= 0 && b < image.height) {
                        unsigned int R = image(a,b,0);
                        unsigned int G = image(a,b,1);
                        unsigned int B = image(a,b,2);
                        int intensity = (R + G + B) / 3;
                        int level = intensity * levels / 256;
                        if (level == mostLevel) {
                            avg_R += image(a,b,0);
                            avg_G += image(a,b,1);
                            avg_B += image(a,b,2);
                            counter++;
                        }
                    }
                }
            }
            avg_R /= counter;
            avg_G /= counter;
            avg_B /= counter;
            image.getPixel(i,j,0) = avg_R;
            image.getPixel(i,j,1) = avg_G;
            image.getPixel(i,j,2) = avg_B;
        }
    }
    cout << "Oil Painting is applied successfully!\n";
}