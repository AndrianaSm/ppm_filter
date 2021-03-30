#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>
#include <iostream>

#include "imageio.h"
#include "array2d.h"
#include "vec3.h"
#include "ppm.h"

using namespace std;
using namespace math;
typedef Vec3<float> Color;

namespace image{
	
class Image:public ImageIO,public math::Array2D<Color>
    {
    public:

		Image(unsigned int width, unsigned int height):Array2D(width, height){
		}
        Image(const Image &image2) {
            width=image2.getWidth();
            height=image2.getHeight();
            buffer=image2.buffer;
        }

        bool load(const std::string &filename, const std::string &format) override{
            if (filename.length() < 5) {
                cout << "This is not a type of image!" << endl;
                system("pause");
                exit(EXIT_FAILURE);
            }
            string f = filename.substr(filename.length() - 4);
            if (f == format || f == ".PPM") {
                int width = 0;
                int height = 0;
                float * array = image::ReadPPM(filename.c_str(), &width, &height);
                this->width = width;
                this->height = height;
                buffer = vector<Color>(width*height);
                int j = 0;
                for (unsigned int i = 0;i < width*height; i++) {
                    buffer[i][0] = array[j];
                    buffer[i][1] = array[j + 1];
                    buffer[i][2] = array[j + 2];
                    j += 3;
                }
                return true;
            }
            else {
                cerr << "Only ppm format is valid!" << endl;
                return false;
            }
        }
        
        bool save(const std::string &filename, const std::string &format) override{
            string f = filename.substr(filename.length() - 4);
                    if (f == format || f == ".PPM") {
                        string  file  =  "filtered_" + filename;
                        float * array = new float[sizeof(Vec3<Image>)*width*height];
                        int j = 0;
                        for (unsigned int i = 0; i < width*height; i++) {
                            array[j] = buffer[i][0];
                            array[j + 1] = buffer[i][1];
                            array[j + 2] = buffer[i][2];
                            j += 3;
                        }
                        image::WritePPM(array, width, height, file.c_str());
                        delete[] array;
                        return true;
                    }
                    else {
                        cerr << "Not suitable format!Only ppm!" << endl;
                        system("pause");
                        return false;
                    }
        }
       //Return The color of the(x, y) pixel as a Color object.Returns a black(0, 0, 0) color in case of an out - of - bounds x, y pair.
        Color getPoint(unsigned int x, unsigned int y) const {
        // if its out of border return null.
        if ((x > width) || (y > height) || (x < 0) || (y < 0)) {
            std::cerr << "Error: getElement() ask for element out of border.\n";
            system("pause");
            exit(1);
        }

        return buffer[y*width + x];
        
                }
        
                //Sets the RGB values for an(x, y) pixel.
                void setPoint(unsigned int x, unsigned int y,const Color & value) {
                   if ((x > width) || (y > height) || (x < 0) || (y < 0)) {
                       cout<<"x=width= "<<x<<"y=height"<<y;
                        cerr << "Error: x or/and y are out of border." << endl;
                       
                        system("pause");
                        exit(1);
                    }
                    buffer[y*width + x] = value;
                }
        
    };

}
#endif
