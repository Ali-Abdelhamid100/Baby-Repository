#include <iostream>
#include "Merge.h"
#include "Image_Class.h"

using namespace std;

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