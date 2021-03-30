#include <string>
#include <iostream>
#include <math.h>
#include "Filter.h"

using namespace math;
using namespace image;

class FilterGamma :public Filter {

private:
	   float c;
public:

   FilterGamma(float c) {
		this->c = c;
	}
	
	FilterGamma(const FilterGamma &src) {
		this->c = src.c;
	}
	
	Image operator << (const  Image & image) {
        Image *gamma = new Image(image.getWidth(),image.getHeight());

            if (c >= 0.5 && c <= 2.0) {
                for (int i = 0; i < image.getHeight(); i++) {
                    for (int j = 0; j < image.getWidth(); j++) {
                        gamma->setPoint(j,i,getPow(image.getPoint(j,i),c));
                        }
                    }
                
                }
        return  *gamma;
    }

private:
    math::Vec3<float> getPow(math::Vec3<float> a, double p) {
        a[0] = pow(a[0], p);
        a[1] = pow(a[1], p);
        a[2] = pow(a[2], p);
        return a;
    }
};
