/*
====================================================================================================
* Course Code: CS213 - Object-Oriented Programming
* Assignment: Assignment 1 (First Submission)
* Submission Date: 1 October 2026
* Submitted To: Dr Mohammad El-Ramly
* Section: S29, S30
* TA: Mennat Allah Mamdouh
* Institution: Faculty of Computing and Artificial Intelligence, Cairo University
-------------------------------------------------
# Students informations:
 1. Habiba Nader Hussein Ali          20250193 
 2. Sama Mounir Mohamed Mohamed       20250297
 3. Seif El-Deen Ismail Mostafa       20251201
 4. Ali Abdelhamid Ali Abdelhamid     20251258
-------------------------------------------------
# File Desciption:
 This cpp File includes: The 8 required core Filters for the first submission of Assignment 1
 ,and Main Menu that supports image loading, Processing, and Exiting the program.
 * Menu Options & Filters:
 1. Load New Image
 2. Grayscale
 3. Black & White
 4. Invert Colors
 5. Add Frame
 6. Flip Image
 7. Rotate Image
 8. Darken / Light
 9. Resize Image
 10. Save Image
 11. Exit
-------------------------------------------------
# Filters Distribution:
 1,5 --> Habiba Nader Hussein Ali
 2,6 --> Sama Mounir Mohamed Mohamed
 3,7 --> Seif El-Deen Ismail Mostafa
 4,8 --> Ali Abdelhamid Ali Abdelhamid
-------------------------------------------------
# Addtional Tasks:
 Main Menu --> All the members
 GitHub Repository Commits --> All the members
====================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Image_Class.h"
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
    cout << "20. Save\n";
    cout << "21. Exit\n";
}

void grayScale (Image& image) {

    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int avg = 0 ;

            for (int k=0 ; k < image.channels ; k++) {
               avg += image(i,j,k);
            }
            avg /= 3;

            image.getPixel(i,j,0)= avg;
            image.getPixel(i,j,1)= avg;
            image.getPixel(i,j,2) = avg;
        }
    }
    cout << "GrayScale is applied successfully!\n";
}

void black_and_white (Image& image) {
    int threshold = 128;
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int avg = 0;
            for(int k = 0 ; k < image.channels ; k++) {
                avg += image(i,j,k);
            }
            avg /= 3;
            if (avg <= threshold) {
                image.setPixel(i,j,0,0);
                image.setPixel(i,j,1,0);
                image.setPixel(i,j,2,0);
            } else {
                image.setPixel(i,j,0,255);
                image.setPixel(i,j,1,255);
                image.setPixel(i,j,2,255);
            }
        }
    }
    cout << "Black and White is applied successfully!\n";
}

void invert (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                image(i,j,k) = 255 - image(i,j,k);
            }
        }
    }
    cout << "Image is inverted successfully!\n";
}

void Add_frame (Image& image) {
    int frame_type;
    cout << "Enter the Frame type : 1 for Simple frame or 2 for Fancy frame\n";
    cin >> frame_type;
    int R, G, B;
    int R1, G1, B1;
    int R2, G2, B2;
    int frame_size;
    int frame1Size, frame2Size;
    int gap;

    if (frame_type == 1) {
        cout << "Enter the size of the frame:\n";
        cin >> frame_size;
        cout << "Enter the values of R G B respectively from 0 to 255:\n";
        cin >> R >> G >> B;
        if ((R < 0 || R > 255) || (B < 0 || B > 255) || (G < 0 || G > 255))
        {
            cout << "Error in the inputs, please try again!\n";
            return;
        }
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if (i < frame_size || i >= image.width - frame_size || j < frame_size || j >= image.height - frame_size) {
                    image(i,j,0) = R;
                    image(i,j,1) = G;
                    image(i,j,2) = B;
                }
            }
        }
        cout << "Simple frame is added successfully!\n";
    } else if (frame_type == 2) {
        cout << "Enter the size of the outer frame then the size of the inner frame:\n";
        cin >> frame1Size >> frame2Size ;
        cout << "Enter the gap between the two frames:\n";
        cin >> gap;
        cout << "Enter the values of R G B respectively of the outer frame from 0 to 255:\n";
        cin >> R1 >> G1 >> B1;
        if ((R1 < 0 || R1 > 255) || (B1 < 0 || B1 > 255) || (G1 < 0 || G1 > 255))
        {
            cout << "Error in the inputs, please try again!\n";
            return;
        }
        cout << "Enter the values of R G B respectively of the inner frame from 0 to 255:\n";
        cin >> R2 >> G2 >> B2;
        if ((R2 < 0 || R2 > 255) || (B2 < 0 || B2 > 255) || (G2 < 0 || G2 > 255))
        {
            cout << "Error in the inputs, please try again!\n";
            return;
        }
        
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if (i < frame1Size || i >= image.width - frame1Size || j < frame1Size || j >= image.height - frame1Size) {
                    image(i,j,0) = R1;
                    image(i,j,1) = G1;
                    image(i,j,2) = B1;
                }
            }
        }
        for (int i = frame1Size + gap ; i < image.width - frame1Size - gap ; i++) {
            for (int j = frame1Size + gap ; j < image.height - frame1Size - gap ; j++) {
                if ((i < frame1Size + gap + frame2Size && i >= frame1Size + gap) || (i >= image.width - (frame1Size + gap + frame2Size) && i < image.width - frame1Size - gap)
                 || (j < frame1Size + gap + frame2Size && j >= frame1Size + gap) || (j >= image.height - (frame1Size + gap + frame2Size) && j < image.height - frame1Size - gap)) {
                    image(i,j,0) = R2;
                    image(i,j,1) = G2;
                    image(i,j,2) = B2;
                }
            }
        }
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if (((i == frame1Size + 1) || (i == frame1Size) || (i == frame1Size - 1)) && (j < frame1Size + 1)
                ||  ((i == frame1Size + 1) || (i == frame1Size) || (i == frame1Size - 1)) && (j > image.height - (frame1Size + 1))
                ||  ((i == image.width - (frame1Size + 1)) || (i == image.width - frame1Size) || (i == image.width - (frame1Size - 1))) && (j < frame1Size + 1)
                ||  ((i == image.width - (frame1Size + 1)) || (i == image.width - frame1Size) || (i == image.width - (frame1Size - 1))) && (j > image.height - (frame1Size + 1))
                ||  ((j == frame1Size + 1) || (j == frame1Size) || (j == frame1Size - 1)) && (i < frame1Size + 1)
                ||  ((j == frame1Size + 1) || (j == frame1Size) || (j == frame1Size - 1)) && (i > image.width - (frame1Size + 1))
                ||  ((j == image.height - (frame1Size + 1)) || (j == image.height - frame1Size) || (j == image.height - (frame1Size - 1))) && (i < frame1Size + 1)
                ||  ((j == image.height - (frame1Size + 1)) || (j == image.height - frame1Size) || (j == image.height - (frame1Size - 1))) && (i > image.width - (frame1Size + 1))) {
                    image.getPixel(i,j,0) = 255;
                    image.getPixel(i,j,1) = 255;
                    image.getPixel(i,j,2) = 255;
                }
            }
        }
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if (((i == frame1Size*4 + 1) || (i == frame1Size*4) || (i == frame1Size*4 - 1)) && (j < frame1Size + 1)
                ||  ((i == frame1Size*4 + 1) || (i == frame1Size*4) || (i == frame1Size*4 - 1)) && (j > image.height - (frame1Size + 1))
                ||  ((i == image.width - (frame1Size*4 + 1)) || (i == image.width - frame1Size*4) || (i == image.width - (frame1Size*4 - 1))) && (j < frame1Size + 1)
                ||  ((i == image.width - (frame1Size*4 + 1)) || (i == image.width - frame1Size*4) || (i == image.width - (frame1Size*4 - 1))) && (j > image.height - (frame1Size + 1))
                ||  ((j == frame1Size*4 + 1) || (j == frame1Size*4) || (j == frame1Size*4 - 1)) && (i < frame1Size + 1)
                ||  ((j == frame1Size*4 + 1) || (j == frame1Size*4) || (j == frame1Size*4 - 1)) && (i > image.width - (frame1Size + 1))
                ||  ((j == image.height - (frame1Size*4 + 1)) || (j == image.height - frame1Size*4) || (j == image.height - (frame1Size*4 - 1))) && (i < frame1Size + 1)
                ||  ((j == image.height - (frame1Size*4 + 1)) || (j == image.height - frame1Size*4) || (j == image.height - (frame1Size*4 - 1))) && (i > image.width - (frame1Size + 1))) {
                    image.getPixel(i,j,0) = 255;
                    image.getPixel(i,j,1) = 255;
                    image.getPixel(i,j,2) = 255;
                }
            }
        }
        frame1Size *= 3;
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if (((i == frame1Size + 1) || (i == frame1Size) || (i == frame1Size - 1)) && (j < frame1Size + 1)
                ||  ((i == frame1Size + 1) || (i == frame1Size) || (i == frame1Size - 1)) && (j > image.height - (frame1Size + 1))
                ||  ((i == image.width - (frame1Size + 1)) || (i == image.width - frame1Size) || (i == image.width - (frame1Size - 1))) && (j < frame1Size + 1)
                ||  ((i == image.width - (frame1Size + 1)) || (i == image.width - frame1Size) || (i == image.width - (frame1Size - 1))) && (j > image.height - (frame1Size + 1))
                ||  ((j == frame1Size + 1) || (j == frame1Size) || (j == frame1Size - 1)) && (i < frame1Size + 1)
                ||  ((j == frame1Size + 1) || (j == frame1Size) || (j == frame1Size - 1)) && (i > image.width - (frame1Size + 1))
                ||  ((j == image.height - (frame1Size + 1)) || (j == image.height - frame1Size) || (j == image.height - (frame1Size - 1))) && (i < frame1Size + 1)
                ||  ((j == image.height - (frame1Size + 1)) || (j == image.height - frame1Size) || (j == image.height - (frame1Size - 1))) && (i > image.width - (frame1Size + 1))) {
                    image.getPixel(i,j,0) = 255;
                    image.getPixel(i,j,1) = 255;
                    image.getPixel(i,j,2) = 255;
                }
            }
        }
        frame1Size /= 6;
        for (int i = 0 ; i < image.width ; i++) {
            for (int j = 0 ; j < image.height ; j++) {
                if ((i <= frame1Size + 1) && (j < frame1Size + 1)
                ||  (i <= frame1Size + 1) && (j > image.height - (frame1Size + 1))
                ||  (i >= image.width - (frame1Size + 1)) && (j < frame1Size + 1)
                ||  (i >= image.width - (frame1Size + 1)) && (j > image.height - (frame1Size + 1))
                ||  (j <= frame1Size + 1) && (i < frame1Size + 1)
                ||  (j <= frame1Size + 1) && (i > image.width - (frame1Size + 1))
                ||  (j >= image.height - (frame1Size + 1)) && (i < frame1Size + 1)
                ||  (j >= image.height - (frame1Size + 1)) && (i > image.width - (frame1Size + 1))) {
                    image.getPixel(i,j,0) = 255;
                    image.getPixel(i,j,1) = 255;
                    image.getPixel(i,j,2) = 255;
                }
            }
        }
        cout << "Fancy frame is added successfully!\n";
    } else {
        cout << "Error in the inputs, please try again!\n";
    }
}

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
void Merge(Image &image1 , Image &image2){
    if(image1.width == image2.width && image1.height == image2.height){
        Image res(image1.width,image1.height);
        for(int i=0 ; i< image1.width ; i++){
            for (int j = 0; j < image1.height; j++)
            {
              for (int k =0 ; k<3 ; k++)
              {
                   res.getPixel(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2 ;
              }
               
            }
            
        } 
        image1 = res;
        cout<< "Two images have same sizes\n";
        cout<< "Image merged successfully!\n" ;
    }
    else{
        int choice ;
        cout<< "Two images have different sizes\n";
        cout<< "Enter 1 for resize both to biggest dimensions or 2 for common area:\n";
        cin>> choice ;
        if (choice == 1)
        {
            
            int new_width = max(image1.width , image2.width);
            int new_height = max(image1.height , image2.height);
            Image resized1(new_width , new_height);
            Image resized2(new_width , new_height);
            for(int i=0 ; i < new_width ; i++)
            {
                for(int j=0 ; j < new_height ; j++)
                {
                    int old_w = (i * image1.width) / new_width ;
                    int old_h = (j * image1.height) / new_height ;
                    for(int k=0 ; k < image1.channels ; k++ )
                    {
                        resized1.getPixel(i,j,k) = image1(old_w,old_h,k);
                    }
                }
            }
            for(int i=0 ; i < new_width ;i++)
            {
                for(int j=0 ; j < new_height ; j++ )
                {
                    int old_w = (i * image2.width) / new_width ;
                    int old_h = (j * image2.height) / new_height ;
                    for (int k = 0; k < image2.channels; k++)
                    {
                        resized2.getPixel(i,j,k) = image2(old_w,old_h,k);
                    }
                    
                }
            }
            Image res(new_width , new_height);
            for(int i=0 ; i < new_width ;i++ )
            {
                for(int j=0 ; j < new_height ;j++)
                {
                    for(int k=0 ; k < 3 ;k++)
                    {
                        res.getPixel(i,j,k) = (resized1(i,j,k) + resized2(i,j,k)) / 2;
                    }
                }
            }
            image1 = res;
            cout << "Image resized and merged successfully!\n";
        }
        else if (choice == 2)
        {
           int new_width = min(image1.width,image2.width);
           int new_height = min(image1.height,image2.height);
           Image res(new_width,new_height);
           for(int i=0 ; i < new_width ; i++ )
           {
            for(int j=0 ; j < new_height ; j++)
            {
                for(int k=0 ; k < 3 ; k++)
                {
                    res.getPixel(i,j,k) = (image1(i,j,k) + image2(i,j,k)) / 2 ;
                }
            }
           }
           image1 = res;
           cout << "Common area merged successfully!\n";
        }
        else 
        {
            cout << "Error in inputs , please try again!\n";
        }
        
    }
}
int main()
{
    cout << "Welcome To Baby Photoshop!\n";
    cout << "Choose a number from the following menu:\n";
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
                if(!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                }  else{
                    string filename2 ;
                    cout << "Enter second image filename:\n";
                    getline(cin >> ws,filename2);
                    Image image2(filename2);
                    Merge(image,image2);
                }  
                break;
            case 20:{
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