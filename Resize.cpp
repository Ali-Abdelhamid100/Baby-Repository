#include <iostream>
#include "Resize.h"
#include "Image_Class.h"

using namespace std;

void resize (Image& image) {
    int new_width, new_height;
    cout << "Enter the new width and the new height respectively:\n";
    cin >> new_width >> new_height;
    Image resized_image(new_width, new_height);
    for (int i = 0 ; i < new_width ; i++) {
        for (int j = 0 ; j < new_height ; j++) {
            int old_w_ind = (i * image.width) / new_width;
            int old_h_ind = (j * image.height) / new_height;

            for (int k = 0 ; k < image.channels ; k++) {
                unsigned char img_pixel = image(old_w_ind,old_h_ind,k);
                resized_image.getPixel(i,j,k) = img_pixel;
            }
        }
    }
    image = resized_image;
    cout << "Image is resized successfully!\n";
}