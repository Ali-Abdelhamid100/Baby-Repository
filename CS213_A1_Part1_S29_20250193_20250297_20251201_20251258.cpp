#include <iostream>
#include <fstream>
#include <utility>
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

void grayScale (Image& image) {

    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int avg = 0;

            for (int k = 0 ; k < image.channels ; k++) {
               avg += image(i,j,k);
            }
            avg /= 3;

            image.getPixel(i,j,0) = avg;
            image.getPixel(i,j,1) = avg;
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
                if ((i < frame1Size + 1) && (j < frame1Size + 1)
                ||  (i < frame1Size + 1) && (j > image.height - (frame1Size + 1))
                ||  (i > image.width - (frame1Size + 1)) && (j < frame1Size + 1)
                ||  (i > image.width - (frame1Size + 1)) && (j > image.height - (frame1Size + 1))) {
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



void purple (Image& image) {
    float red_factor = 0.08;
    float green_factor = 0.15;
    float blue_factor = 0.18;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            float red = image(i, j, 0) + ((255-image(i, j, 0)) * red_factor);
            float green = image(i, j, 1) * (1 - green_factor);
            float blue = image(i, j, 2) + ((255-image(i, j, 2)) * blue_factor);
            if (red > 255) red = 255;
            if (red < 0) red = 0;
            if (green > 255) green = 255;
            if (green < 0) green = 0;
            if (blue > 255) blue = 255;
            if (blue < 0) blue = 0;
            image(i, j, 0) = static_cast<unsigned char> (red);
            image(i, j, 1) = static_cast<unsigned char> (green);
            image(i, j, 2) = static_cast<unsigned char> (blue);
        }
    }
    cout << "Purple filter is applied successfully!\n";
}

void Blur (Image& image, int radius = 15) {
    Image img = image;
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int R_avg = 0;
            unsigned int G_avg = 0;
            unsigned int B_avg = 0;
            int cnt = 0;
            for (int a = i - radius ; a <= i + radius  ; a++) {
                for (int b = j - radius ; b <= j + radius ; b++) {
                    if (a >= 0 && a < image.width && b >= 0 && b < image.height) {
                        R_avg += img(a,b,0);
                        G_avg += img(a,b,1);
                        B_avg += img(a,b,2);
                        cnt++;
                    }
                }
            }
            R_avg /= cnt;
            G_avg /= cnt;
            B_avg /= cnt;
            image.getPixel(i,j,0) = R_avg;
            image.getPixel(i,j,1) = G_avg;
            image.getPixel(i,j,2) = B_avg;
        }
    }
    cout << "Blur is applied successfully!\n";
}

void Infrared (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                image(i,j,k) = 255 - image(i,j,k);
            }
        }
    }
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            unsigned int G = image(i,j,1);
            unsigned int B = image(i,j,2);
            image.getPixel(i,j,0) = 255;
            image.getPixel(i,j,1) = G;
            image.getPixel(i,j,2) = B;
        }
    }
    cout << "Infrared is applied successfully!\n";
}


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
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    
                }
                break;
            case 11:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    
                }
                break;
            case 12:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    
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
                    
                }
                break;
            case 15:
                if (!Is_Image_Loaded) {
                    cout << "Please load an image at first!\n";
                } else {
                    
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