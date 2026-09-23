// A demo for converting image to gray scale

#include <iostream>
using namespace std;
#include "Image_Class.h"
/* void grayScale(Image& image){
    
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
}*/