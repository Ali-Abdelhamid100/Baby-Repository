#ifndef FILTERS_H
#define FILTERS_H

#include "Image_Class.h"

void grayScale (Image& image);

void black_and_white (Image& image);

void invert (Image& image);

void fancyDetails(Image& image, int innerDistance);
void Add_frame (Image& image);

void flipImage (Image& image);

void Rotate (Image& image);

void darken_lighten (Image& image);

void resize (Image& image);

void Merge (Image &image1 , Image &image2);

void detect_edges (Image& image);

void crop (Image& image);

void Blur (Image& image, int radius = 15);

void Sunlight (Image& image);

void addNoise (Image& image, int noiseLevel);
void addScanlines(Image& image, int scanlineIntensity);
void applyColorDistortion(Image& image);
void old_tv_image (Image& image);

void purple (Image& image);

void Infrared (Image& image);

void Skew (Image& image);

void oilPainting (Image& image);

#endif // FILTERS_H