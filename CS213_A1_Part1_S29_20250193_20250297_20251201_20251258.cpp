#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Image_Class.h"
#include "Grayscale.h"
#include "BlackAndWhite.h"
#include "invert.h"
#include "AddFrame.h"
#include "FlipImage.h"
#include "Rotate.h"
#include "DarkenLighten.h"
#include "Resize.h"
#include "Crop.h"
#include "Merge.h"
#include "Sunlight.h"
#include "DetectEdges.h"
#include "OldTVImages.h"
#include "Skew.h"
#include "Purple.h"
#include "Blur.h"
#include "Infrared.h"
#include "OilPainting.h"

using namespace std;

void Starting_Menu () {
    cout << "==========================================\n";
    cout << "=================  Menu  =================\n";
    cout << "==========================================\n";
    cout << "1. Load new image\n";
    cout << "2. Grayscale\n";
    cout << "3. Black and White\n";
    cout << "4. Invert\n";
    cout << "5. Add frame\n";
    cout << "6. Flip\n";
    cout << "7. Rotate\n";
    cout << "8. Darken / Lighten\n";
    cout << "9. Resize\n";
    cout << "10. Merge\n";
    cout << "11. Edge Detection\n";
    cout << "12. Crop\n";
    cout << "13. Blur\n";
    cout << "14. Sunlight\n";
    cout << "15. Tv Images\n";
    cout << "16. Purple\n";
    cout << "17. Infrared\n";
    cout << "18. Skewing\n";
    cout << "19. Oil Painting\n";
    cout << "20. Save\n";
    cout << "21. Exit\n";
}

int main() {
    
    cout << "Welcome To Baby Photoshop!\n";
    cout << "Choose a number from the following menu:\n";
    bool running = true;
    string filename = "";
    bool Is_Image_Loaded = false;
    Image image;

    while (running) {

        Starting_Menu();
        int User_Choice;
        if (!(cin >> User_Choice)) {
            cout << "Invalid input!\n";
            cout << "Please enter a number\n";
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        }

        switch (User_Choice) {
            case 1: {
                cout << "Enter Image Filename:\n";
                getline(cin >> ws, filename);

                ifstream file(filename);
                if (!file) {
                cout << "File does not exist!\n";
                cout << "Try Again!\n";
                break;
                }
                file.close();

                bool Is_Ext_valid = false;
                size_t Dot_Ind = filename.find_last_of(".");
                if (Dot_Ind != string::npos) {
                    string ext = filename.substr(Dot_Ind);
                    if (ext == ".jpeg" || ext == ".jpg" || ext == ".png" || ext == ".bmp" || ext == ".tga") {
                        Is_Ext_valid = true;
                    }
                }

                if (Is_Ext_valid) {
                    image.loadNewImage(filename);
                    Is_Image_Loaded = true;
                    cout << "Image is loaded successfully!\n";
                } else {
                    cout << "Invalid file extension!\n";
                }
                break;
            }
            case 2:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    grayScale (image);
                }
                break;
            case 3:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    black_and_white (image);
                }
                break;
            case 4:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    invert (image);
                }
                break;
            case 5:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    Add_frame (image);
                }
                break;
            case 6:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    flipImage (image);
                }
                break;
            case 7:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    Rotate (image);
                }
                break;
            case 8:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    darken_lighten (image);
                }
                break;
            case 9:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    resize (image);
                }
                break;
            case 10:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    string filename2;
                    cout << "Enter second image filename:\n";
                    getline(cin >> ws,filename2);
                    Image image2(filename2);
                    Merge(image,image2);
                }
                break;
            case 11:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    detect_edges (image);
                }
                break;
            case 12:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    crop (image);
                }
                break;
            case 13:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    Blur (image);
                }
                break;
            case 14:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    Sunlight (image);
                }
                break;
            case 15:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    old_tv_image (image);
                }
                break;
            case 16:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    purple (image);
                }
                break;
            case 17:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    Infrared (image);
                }
                break;
            case 18:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    Skew (image);
                }
                break;
            case 19:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    oilPainting (image);
                }
                break;
            case 20: {
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    cout << "Please enter image name to store new image\n";
                    cout << "and with one of the following extensions: .jpg, .bmp, .png, .jpeg .tga\n";

                    cin >> filename;
                    image.saveImage(filename);
                    cout << "Your new image is saved successfully!\n";
                }
                break;
            }
            case 21:
                cout << "Exiting the program!\n";
                running = false;
                break;
            default:
                cout << "ERROR in the inputs!\n";
        }
    }
    
    return 0;
}