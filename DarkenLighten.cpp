#include <iostream>
#include "DarkenLighten.h"
#include "Image_Class.h"

using namespace std;

void darken_lighten (Image& image) {
    cout << "Enter 1 to Darken the image or 2 to lighten the image:\n";

    int choice;
    float darken_Percentage;
    float lighten_Percentage;

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "invalid input, please enter a number!\n";
        return;
    }

    if (choice == 1) {
        cout << "Enter The Darkening Percentage You Want From 0 to 100:\n";

        if (!(cin >> darken_Percentage)) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "invalid input, please enter a number!\n";
            return;
        }

        if (0 <= darken_Percentage && darken_Percentage <= 100) {
            for (int i = 0 ; i < image.width ; i++) {
                for (int j = 0 ; j < image.height; j++) {
                    for (int k = 0 ; k < image.channels ; k++) {
                        image(i,j,k) =
                            image(i,j,k) * (1 - (darken_Percentage / 100.0));

                        if (image(i,j,k) > 255) {
                            image(i,j,k) = 255;

                        } else if (image(i,j,k) < 0) {
                            image(i,j,k) = 0;
                        }
                    }
                }
            }
            cout << "Darken filter is applied successfully!\n";
        }
        else
        {
            cout << "Error in the inputs, please try again!\n";
        }
    }
    else if (choice == 2) {
        cout << "Enter The lightening Percentage You Want From 0 to 100:\n";

        if (!(cin >> lighten_Percentage)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid input, please enter a number!\n";
            return;
        }

        if (0 <= lighten_Percentage && lighten_Percentage <= 100) {
            for (int i = 0 ; i < image.width ; i++) {
                for (int j = 0 ; j < image.height ; j++) {
                    for (int k = 0 ; k < image.channels ; k++) {
                        image(i,j,k) =
                            image(i,j,k) +
                            ((255 - image(i,j,k)) *
                            (lighten_Percentage / 100.0));

                        if (image(i,j,k) > 255) {
                            image(i,j,k) = 255;

                        } else if (image(i,j,k) < 0) {
                            image(i,j,k) = 0;
                        }
                    }
                }
            }

            cout << "Lighten filter is applied successfully!\n";
        } else {
            cout << "Error in the inputs, please try again!\n";
        }
    } else {
        cout << "Error in the inputs, please try again!\n";
    }
}