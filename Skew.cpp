#include <iostream>
#include "Skew.h"
#include "Image_Class.h"

using namespace std;

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