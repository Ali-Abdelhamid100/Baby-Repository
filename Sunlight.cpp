#include <iostream>
#include "Sunlight.h"
#include "Image_Class.h"

using namespace std;

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