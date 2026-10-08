#ifndef BLUR_H
#define BLUR_H

// لو كلاس الصورة بتاعكم اسمه Image، اعمل له include هنا
#include "Image_Class.h"

// تعريف فانكشن فلتر الـ Blur وتستقبل كائن الصورة بالمرجع (Reference)
void Blur (Image& image, int radius = 15);

#endif // BLUR_H