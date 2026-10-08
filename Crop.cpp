#include <iostream>
#include "Crop.h"
#include "Image_Class.h"

using namespace std;

void crop (Image& image) {
    int new_width, new_height, x, y;
    cout << "Enter the x and y coordinates of the top-left corner:\n";
    cin >> x >> y;
    cout << "Enter the new width and height respectively:\n";
    cin >> new_width >> new_height;
    Image cropped_image(new_width, new_height);
    if (x >= 0 && y >= 0 && x + new_width <= image.width && y + new_height <= image.height) {
        for (int i = 0; i < new_width; i++) {
            for (int j = 0; j < new_height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    cropped_image(i, j, k) = image(x + i, y + j, k);
                }
            }
        }
        image = cropped_image;
        cout << "Image is cropped successfully!\n";
    } else {
        cout << "Error in the inputs, please try again!\n";
    }
}