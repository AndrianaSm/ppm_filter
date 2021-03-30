#ifndef Filter_hpp
#define Filter_hpp

#include <stdio.h>
#include "Image.h"

using namespace image;

namespace math {

    class Filter {
        virtual  Image operator << (const Image & image) = 0;
    };

}
#endif
