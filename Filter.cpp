#include "Filter.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Image.h"
#include "FilterGamma.h"
#include "FilterLinear.h"
#include "array2d.h"

using namespace std;
using namespace image;
using namespace math;

int main(int argc, char *argv[]) {
    Image *image = new Image(0,0);

    string filename = argv[argc - 1];
    if (filename.substr(filename.length() - 4) ==".ppm" || filename.substr(filename.length() - 4) == ".ppm") {
        cout<<argv[1]<<"dsds";
        if (strcmp(argv[1],"-f")== 0) {
            image->load(filename.c_str(), ".ppm");
        
        }
        else {
            cout << "No filter has been given!" << endl;
            system("PAUSE");
            exit(EXIT_FAILURE);
        }
//        Image *filtred_image=new Image(image->getWidth(),image->getHeight());

        for (int i = 1; i < argc - 1; i++) {
            if (strcmp(argv[i], "-f") == 0) {
                if (strcmp(argv[i + 1],"gamma")== 0) {
                    FilterGamma *gamma = new FilterGamma(atof(argv[i + 2]));
                    image=new Image(*gamma << *image);
                    cout<<"im here!!!!!!!!!";
                    delete gamma;
                }
                else if (strcmp(argv[i + 1],"linear")==0) {
                    Color *vec1 = new  Color(atof(argv[i + 2]),atof(argv[i + 3]),atof(argv[i + 4]));
                    Color *vec2 = new  Color(atof(argv[i + 5]),atof(argv[i + 6]),atof(argv[i + 7]));
                    FilterLinear *linear = new FilterLinear(*vec1,*vec2);
                    image=new Image(*linear << *image) ;
                    delete vec1, vec2, linear;
                }
            }
        }
        cout << "Image dimensions are:" << image->getWidth() << " x " << image->getHeight() << endl;
        image->save(filename.c_str(), ".ppm");
    }
    else {
        cout << "No image has been given!" << endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }
//    delete image;

    system("pause");
}
