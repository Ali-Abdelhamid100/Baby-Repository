#include <iostream>
#include "FlipImage.h"
#include "Image_Class.h"

using namespace std;

void flipImage (Image& image) {
    int choice;
    cout << "Enter your choice: 1 for Horizontal flip or 2 for Vertical flip:\n";
    cin >> choice;

    if (choice == 1) {
      for (int i = 0 ; i< image.width/2 ; i++) {
         for (int j = 0 ; j < image.height ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
               swap(image(i,j,k),image(image.width-1-i,j,k)) ;
            }
         }
      }
      cout << "Horizontal flip applied successfully!\n" ;
    } else if (choice == 2) {
       for (int i = 0 ; i < image.width ; i++) {
          for (int j = 0 ; j < image.height/2 ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                swap(image(i,j,k) , image(i,image.height-1-j,k));
            }
          }
        }
        cout << "Vertical flip is applied successfully!\n" ;
    } else {
        cout << "Error in inputs, please try again!\n";
    }
}