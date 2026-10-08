#ifndef OLDTVIMAGES_H
#define OLDTVIMAGES_H

// لو كلاس الصورة بتاعكم اسمه Image، اعمل له include هنا
#include "Image_Class.h"

// تعريف فانكشن فلتر الـ addNoise وتستقبل كائن الصورة بالمرجع (Reference)
void addNoise (Image& image, int noiseLevel);

// تعريف فانكشن فلتر الـ addScanlines وتستقبل كائن الصورة بالمرجع (Reference)
void addScanlines(Image& image, int scanlineIntensity);

// تعريف فانكشن فلتر الـ applyColorDistortion وتستقبل كائن الصورة بالمرجع (Reference)
void applyColorDistortion(Image& image);

// تعريف فانكشن فلتر الـ old_tv_image وتستقبل كائن الصورة بالمرجع (Reference)
void old_tv_image (Image& image);

#endif // OLDTVIMAGES_H