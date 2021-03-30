#include <string>
#include <iostream>
#include "Filter.h"
#include "Vec3.h"

using namespace math;
using namespace image;

class FilterLinear :public Filter {

private:
	Vec3<float> a, c;

public:
 
	FilterLinear(Color &a,Color &c){
		this->a = a;
		this->c = c;

	}

	FilterLinear(const FilterLinear &src) {
		this->a = src.a;
		this->c = src.c;
	}

	Image operator << (const Image & image) {
      
        image::Image result(image.getWidth(), image.getHeight());
        for (int i = 0; i < image.getHeight(); i++) { // i = row
            for (int j = 0; j < image.getWidth(); j++) {// j = column
                math::Vec3<float> temp((a * image.getPoint(j, i)) + c);
                temp = temp.clampToLowerBound(0.0f);
                temp = temp.clampToUpperBound(1.0f);
                result.setPoint(j, i, temp);
            }
        }
        return result;
    }
};

