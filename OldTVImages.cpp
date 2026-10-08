#include <iostream>
#include "OldTVImages.h"
#include "Image_Class.h"

using namespace std;

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