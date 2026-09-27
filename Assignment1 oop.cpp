#include <iostream>
#include <fstream>
#include <string>
#include "Image_Class.h"
using namespace std;

void Starting_Menu ()
{
    cout << "==============================\n";
    cout << "===========  Menu  ===========\n";
    cout << "==============================\n";
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
        }
    }
}

void black_and_white(Image& image) {
    int threshold = 128;
    for(int i = 0; i < image.width; i++) {
        for(int j = 0; j < image.height; j++) {
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
        }
    }
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

void Add_frame (Image& image)
{
    int frame_type;
    cout << "Enter the Frame type : 1 for Single frame   2 for Double frame\n";
    cin >> frame_type;
    int R, G, B;
    int R1, G1, B1;
    int R2, G2, B2;
    int frame_size;
    int frame1Size, frame2Size;

    if (frame_type == 1) {
        cout << "Enter the size of the frame\n";
        cin >> frame_size;
        cout << "Enter the values of R G B respectively :\n";
        cin >> R >> G >> B;
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++){
                if (i < frame_size || i >= image.width - frame_size || j < frame_size || j >= image.height - frame_size) {
                    image(i,j,0) = R;
                    image(i,j,1) = G;
                    image(i,j,2) = B;
                }
            }
        }
    } else if (frame_type == 2) {
        cout << "Enter the size of the outer frame then the size of the inner frame\n";
        cin >> frame1Size >> frame2Size ;
        cout << "Enter the values of R G B respectively of the outer frame:\n";
        cin >> R1 >> G1 >> B1;
        cout << "Enter the values of R G B respectively of the inner frame:\n";
        cin >> R2 >> G2 >> B2;
        
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if (i < frame1Size || i >= image.width - frame1Size || j < frame1Size || j >= image.height - frame1Size) {
                    image(i,j,0) = R1;
                    image(i,j,1) = G1;
                    image(i,j,2) = B1;
                }
            }
        }
        for (int i = frame1Size ; i < image.width - frame1Size ; i++) {
            for (int j = frame1Size ; j < image.height - frame1Size ; j++) {
                if ((i < frame1Size + frame2Size && i >= frame1Size) || (i >= image.width - (frame1Size + frame2Size) && i < image.width - frame1Size)
                 || (j < frame1Size + frame2Size && j >= frame1Size) || (j >= image.height - (frame1Size + frame2Size) && j < image.height - frame1Size)) {
                    image(i,j,0) = R2;
                    image(i,j,1) = G2;
                    image(i,j,2) = B2;
                }
            }
        }
    } else {
        cout << "Error in the inputs, please try again!\n";
    }
}

bool Rotate(Image& image){
    int choice;
    cout << "Enter the angle of rotation\n"; 
    cout << "Choice 1: 90 Choice 2: 180 Choice 3: 270\n";
    cin >> choice;
    Image rotated_image;

    if (choice == 1){
        rotated_image = Image(image.height, image.width);

        for(int i = 0; i < image.width; i++){
            for(int j = 0; j < image.height; j++){
                int i_new = image.height - 1 - j;
                int j_new = i;

                for(int k = 0; k < image.channels; k++){
                    rotated_image(i_new, j_new, k) = image(i, j, k);
                }
            }
        }
        image = rotated_image;
        return true;
    }
    else if(choice == 2){
        rotated_image = Image(image.width, image.height);

        for(int i = 0; i < image.width; i++){
            for(int j = 0; j < image.height; j++){
                int i_new = image.width - 1 - i;
                int j_new = image.height - 1 - j;

                for(int k = 0; k < image.channels; k++){
                    rotated_image(i_new, j_new, k) = image(i, j, k);
                }
            }
        }
        image = rotated_image;
        return true;
    }
    else if(choice == 3){
        rotated_image = Image(image.height, image.width);

        for(int i = 0; i < image.width; i++){
            for(int j = 0; j < image.height; j++){
                int i_new = j;
                int j_new = image.height - 1 - i;

                for(int k = 0; k < image.channels; k++){
                    rotated_image(i_new, j_new, k) = image(i, j, k);
                }
            }
        }
        image = rotated_image;
        return true;
    }
    return false;
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
                getline(cin >> ws, filename);

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
                } else {
                    grayScale(image);  // calling grayScale function
                    cout << "GrayScale applied successfully!\n";
                }
                break;
            case 3:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else{
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
                } else {
                    Add_frame (image);
                    cout << "Frame added successfully\n";
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
                else if(Rotate(image)){
                    cout << "Image is rotated successfully!\n";
                }
                else{
                    cout << "Invalid choice,please try again!\n";
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
                    cout << "Your new image saved successfully\n";
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