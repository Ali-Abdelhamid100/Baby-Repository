#include <iostream>
#include "Rotate.h"
#include "Image_Class.h"

using namespace std;

void Rotate (Image& image) {
    int choice;
    cout << "Enter the angle of rotation : 1 for 90  or  2 for 180  or  3 for 270\n";
    cin >> choice;
    Image rotated_image;

    if (choice == 1) {
        rotated_image = Image(image.height, image.width);

        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                int i_new = image.height - 1 - j;
                int j_new = i;
                for(int k = 0 ; k < image.channels ; k++) {
                    rotated_image(i_new, j_new, k) = image(i, j, k);
                }
            }
        }
        image = rotated_image;
        cout << "Image is rotated successfully by angle 90!\n";
    } else if (choice == 2) {
        rotated_image = Image(image.width, image.height);

        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                int i_new = image.width - 1 - i;
                int j_new = image.height - 1 - j;
                for (int k = 0; k < image.channels; k++) {
                    rotated_image(i_new, j_new, k) = image(i, j, k);
                }
            }
        }
        image = rotated_image;
        cout << "Image is rotated successfully by angle 180!\n";
    } else if (choice == 3) {
        rotated_image = Image(image.height, image.width);

        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                int i_new = j;
                int j_new = image.width - 1 - i;
                for (int k = 0; k < image.channels; k++) {
                    rotated_image(i_new,j_new,k) = image(i,j,k);
                }
            }
        }
        image = rotated_image;
        cout << "Image is rotated successfully by angle 270!\n";
    } else {
        cout << "Error in the inputs, please try again!\n";
    }
}