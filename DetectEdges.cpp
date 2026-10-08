#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Grayscale.h"
#include "DetectEdges.h"
#include "Image_Class.h"

using namespace std;

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