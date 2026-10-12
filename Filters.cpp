#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include "Filters.h"
#include "Image_Class.h"

using namespace std;

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

void fancyDetails(Image& image, int innerDistance)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            if (
                (((i == innerDistance + 1) ||
                  (i == innerDistance) ||
                  (i == innerDistance - 1)) &&
                 (j < innerDistance + 1))

                ||

                (((i == innerDistance + 1) ||
                  (i == innerDistance) ||
                  (i == innerDistance - 1)) &&
                 (j > image.height - (innerDistance + 1)))

                ||

                (((i == image.width - (innerDistance + 1)) ||
                  (i == image.width - innerDistance) ||
                  (i == image.width - (innerDistance - 1))) &&
                 (j < innerDistance + 1))

                ||

                (((i == image.width - (innerDistance + 1)) ||
                  (i == image.width - innerDistance) ||
                  (i == image.width - (innerDistance - 1))) &&
                 (j > image.height - (innerDistance + 1)))

                ||

                (((j == innerDistance + 1) ||
                  (j == innerDistance) ||
                  (j == innerDistance - 1)) &&
                 (i < innerDistance + 1))

                ||

                (((j == innerDistance + 1) ||
                  (j == innerDistance) ||
                  (j == innerDistance - 1)) &&
                 (i > image.width - (innerDistance + 1)))

                ||

                (((j == image.height - (innerDistance + 1)) ||
                  (j == image.height - innerDistance) ||
                  (j == image.height - (innerDistance - 1))) &&
                 (i < innerDistance + 1))

                ||

                (((j == image.height - (innerDistance + 1)) ||
                  (j == image.height - innerDistance) ||
                  (j == image.height - (innerDistance - 1))) &&
                 (i > image.width - (innerDistance + 1)))
                )
            {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }
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
        // Fancy details
        fancyDetails(image, frame1Size);

        fancyDetails(image, frame1Size * 3);

        fancyDetails(image, frame1Size * 4);

        frame1Size /= 2;
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

void Merge (Image &image1 , Image &image2) {
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

void detect_edges(Image& image){
    Image gray = image;

    std::streambuf* original = cout.rdbuf();
    std::ostringstream temp;
    cout.rdbuf(temp.rdbuf());

    grayScale(gray);

    cout.rdbuf(original);

    // 100 is a good starting value for unnormalized gradient magnitude.
    const int EDGE_THRESHOLD = 100;
    Image result = gray;
    int Gx[3][3] = {{-1, 0 ,1},{-2, 0, 2},{-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1},{0, 0, 0},{1, 2,  1}};
    for(int i = 1 ; i < gray.width - 1; i++){
        for(int j = 1; j < gray.height - 1; j++){
            int gx = 0;
            int gy = 0;
            for(int row = -1; row <= 1; row++){
                for(int column = -1; column <= 1; column++){
                    gx += gray(i + column, j + row, 0) * Gx[row + 1][column + 1];
                    gy += gray(i + column, j + row, 0) * Gy[row + 1][column + 1];
                }
            }
            int magnitude = sqrt(gx * gx + gy * gy);

            if (magnitude > EDGE_THRESHOLD){
                result(i, j, 0) = 0;
                result(i, j, 1) = 0;
                result(i, j, 2) = 0;}
            else{
                result(i, j, 0) = 255;
                result(i, j, 1) = 255;
                result(i, j, 2) = 255;}
        }
    }
    image = result;
    cout << "Image edges are detected successfully!\n";
}

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

void Blur (Image& image, int radius) {
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

void Sunlight(Image &image){
    for(int i=0 ; i < image.width ; i++)
    {
        for(int j=0 ; j < image.height ; j++)
        {
          image.getPixel(i,j,0) = min(255,image.getPixel(i,j,0) + 50);
          image.getPixel(i,j,1) = min(255,image.getPixel(i,j,1) + 50);
          image.getPixel(i,j,2) = max(0,image.getPixel(i,j,2) - 20); 
        }
    }
    cout <<"Sunlight effect applied successfully!\n";
}

void addNoise(Image& image, int noiseLevel){
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            for(int k = 0; k < image.channels; k++){

                int noise = (rand() % (2 * noiseLevel + 1)) - noiseLevel;
                int new_value = image(i, j, k) + noise;
                
                if(new_value < 0){
                    image.setPixel(i, j , k, 0);
                }
                else if(new_value > 255)
                    image.setPixel(i, j, k, 255);
                else{
                    image.setPixel(i, j, k, new_value);
                    
                    }
            }
        }
    }
}

void addScanlines(Image& image, int scanlineIntensity){
    for(int j = 0;j < image.height; j++){
        if(j % 2 == 0){
            for(int i = 0;i < image.width; i++){
                for(int k = 0;k < image.channels; k++){
                    if(image(i, j, k) > scanlineIntensity){
                        image.setPixel(i, j, k, image(i, j, k) - scanlineIntensity);
                    }
                    else{
                        image.setPixel(i, j, k, 0);
                    }
                }

            }
        }
    }

}

void applyColorDistortion(Image& image)
{
    int redshift = 30;
    int greenshift = 0;
    int blueshift = -20;

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int red = image(i, j, 0) + redshift;
            int green = image(i, j, 1) + greenshift;
            int blue = image(i, j, 2) + blueshift;

            if (red > 255)
                red = 255;
            if (red < 0)
                red = 0;

            if (green > 255)
                green = 255;
            if (green < 0)
                green = 0;

            if (blue > 255)
                blue = 255;
            if (blue < 0)
                blue = 0;

            image.setPixel(i, j, 0, red);
            image.setPixel(i, j, 1, green);
            image.setPixel(i, j, 2, blue);
        }
    }
}

void old_tv_image(Image& image){
    int noiseLevel;
    int scanlineIntensity;

    cout << "Enter noise level: \n";
    cin >> noiseLevel;

    if(noiseLevel < 0){
        cout << "Invalid input, please try again!\n";
        return;
    }

    cout << "Enter scanline intensity: \n";
    cin >> scanlineIntensity;

    if(scanlineIntensity < 0){
        cout << "Invalid input, please try again!\n";
        return;
    }

    addNoise(image, noiseLevel);
    addScanlines(image, scanlineIntensity);
    applyColorDistortion(image);
    cout << "Image is converted to old tv image successfully!\n";
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

void Skew(Image& image)
{
    double angle;

    cout << "Enter angle (-45 to 45): ";
    cin >> angle;

    if (angle < -45 || angle > 45)
    {
        cout << "Error in inputs, please try again!\n";
        return;
    }

    double radians = angle * 3.141592653589793 / 180;

    int shiftAmount = abs((int)(image.height * tan(radians)));

    int newWidth = image.width + shiftAmount;

    Image result(newWidth, image.height);

    
    for (int i = 0; i < result.width; i++)
    {
        for (int j = 0; j < result.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result.getPixel(i, j, k) = 0;
            }
        }
    }

    
    for (int j = 0; j < image.height; j++)
    {
        double shift = j * tan(radians);

        for (int i = 0; i < image.width; i++)
        {
            int newI;

            if (angle >= 0)
            {
                newI = i - (int)shift + shiftAmount;
            }
            else
            {
                newI = i - (int)shift;
            }

            if (newI >= 0 && newI < result.width)
            {
                for (int k = 0; k < 3; k++)
                {
                    result.getPixel(newI, j, k) =
                        image.getPixel(i, j, k);
                }
            }
        }
    }

    image = result;

    cout << "Image skewed successfully!\n";
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