#include <iostream>
#include <fstream>
#include <string>
#include "Image_Class.h"
#include "ImageProcessingDemo.cpp"
using namespace std;

<<<<<<< HEAD
void black_and_white(Image& image){
    int threshold = 128;
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            unsigned int avg = 0;
            for(int k = 0; k < image.channels; k++)
            {
                avg += image(i , j, k);
            }
            avg /= 3;
            if (avg <= threshold){
                image.setPixel(i, j, 0, 0);
                image.setPixel(i, j, 1, 0);
                image.setPixel(i, j, 2, 0);
            }
            else{
                image.setPixel(i, j, 0, 255);
                image.setPixel(i, j, 1, 255);
                image.setPixel(i, j, 2, 255);
            }
=======

void grayScale(Image& image){
    
    // Loop through all pixels in image

    for(int i=0 ; i< image.width ; i++)   
    {
        for (int j=0 ; j < image.height ; j++)     
          {
            unsigned int avg = 0 ;

           // Get RGB values
            for(int k=0 ; k < 3 ;k++)
            {
               avg += image(i,j,k);
            }
            avg /= 3;

            // Set all RGB to average value
            image.getPixel(i,j,0)= avg ;
            image.getPixel(i,j,1)= avg ;
            image.getPixel(i,j,2) = avg ;
>>>>>>> f25cd65798d2cea22e3b37e6cdacccb71b727c06
        }
    }
}

void Starting_Menu ()
{
    cout << "\n";
    cout << "============ Menu ============\n";
    cout << "1. Load new image\n";
    cout << "2. Grayscale\n";
    cout << "3. Black and White\n";
    cout << "4. Invert\n";
    cout << "5. Add frame\n";
    cout << "6. Flip\n";
    cout << "7. Rotate\n";
    cout << "8. Darken / Lighten\n";
    cout << "9. Resize\n";
    cout << "10. Save\n";
    cout << "11. Exit\n";
}
void invertfilter (Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k); // Invert pixel value
            }
        }
    }
}

int main()
{
    cout << "Welcome To Baby Photoshop\n";
    cout << "Choose a number from the following menu\n";
    bool running = true;
    string filename = "";
    bool Is_Image_Loaded = false;
    Image image;

    while (running)
    {
        Starting_Menu();
        int User_Choice;
        if (!(cin >> User_Choice)) {
            cout << "Invalid input!\n";
            cout << "Please enter a number\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (User_Choice) {
            case 1: {
                cout << "Enter Image Filename: ";
                cin >> filename;

                ifstream file(filename);
                if (!file.is_open()) {
                cout << "File does not exist!\n";
                cout << "Try Again!\n";
                break;
                }
                file.close();

                bool Is_Ext_valid = false;
                size_t Dot_Ind = filename.find_last_of(".");
                if (Dot_Ind != string::npos) {
                    string ext = filename.substr(Dot_Ind);
                    if (ext == ".jpeg" || ext == ".jpg" || ext == ".png" || ext == ".bmp") {
                        Is_Ext_valid = true;
                    }
                }

                if (Is_Ext_valid) {
                    image.loadNewImage(filename);
                    Is_Image_Loaded = true;
                    cout << "Image loaded successfully!\n";
                } else {
                    cout << "Invalid file extension!\n";
                }
                break;
            }
            case 2:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
        
                }
                else {
                    grayScale(image);  // calling grayScale function
                    cout << "GrayScale applied successfully!\n";
                }
                break;
            case 3:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }
                else{
                    black_and_white(image);
                    cout << "Black and White applied successfully!\n";
                }
                break;
            case 4:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    invertfilter(image);
                    cout << "Image inverted successfully!\n";
                }
                break;
            case 5:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }
                break;
            case 6:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }
                break;
            case 7:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }
                break;
            case 8:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }
                break;
            case 9:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }
                break;
            case 10:{
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    cout << "Please enter image name to store new image\n";
                    cout << "and with one of the following extensions: .jpg, .bmp, .png, .jpeg\n";

                    cin >> filename;
                    image.saveImage(filename);
                }
                break;
            }
            case 11:
                cout << "Exiting the program\n";
                running = false;
                break;
            default:
                cout << "ERROR in the inputs";
        }
    }
    
    return 0;
}