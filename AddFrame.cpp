#include <iostream>
#include "AddFrame.h"
#include "Image_Class.h"

using namespace std;

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