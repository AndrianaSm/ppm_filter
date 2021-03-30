#include <iostream>
#include <fstream>
#include <string>
#include "ppm.h"
using namespace std;

 namespace image
 {   
	 //Reads a PPM image file and returns a pointer to a newly allocated float array containing the image data.
     //Values in the returned array are in the range[0, 1] and for each pixel,before these though it makes sure that the file has the necessairy characteristics.
	 float * ReadPPM(const char * filename, int * w, int * h) {

		 ifstream file(filename, std::ios::in | std::ios::binary);
		 if (file) {
             if (file.is_open()) {
				 string p6param;
				 file >> p6param;
				 if (p6param != "P6") {
					 cout << "Invalid image format,only P6!" << endl;
					 exit(1);
				 }
				 int maxValue = 0;
				 file >> *w >> *h >> maxValue;
				 if (maxValue > 255) {
					 cout << "Max value to store should be less than 255!"<<endl;
                     exit(1);
				 }
				 if (maxValue == 0 || *w == NULL || *h == NULL) {
					 cout << "Data characteristics are missing! It cannot be loaded!"<<endl;
					 system("pause");			
					 exit(EXIT_FAILURE);
				 }
				 int size = 3 * *w**h;
				 float* buffer = new float[size];
				 unsigned char value;
				 int i = 0;
				 while (!file.eof()) {
					 file.read(((char*)(&value)), 1);
					 buffer[i] = value / 255.0f;
					 i++;
				 }
				 file.close();
				 return buffer;

			 }
			 else {
				 cout << "File could not be opened!"<<endl;
				 system("pause");
				 exit(EXIT_FAILURE);
			 }

		 }
		 else {
			 cout << "File does not exist!"<<endl;
			 system("pause");
			 exit(EXIT_FAILURE);
		 }
	 }

	 //Writes an image buffer as a PPM file.
     bool WritePPM(const float * data, int w, int h, const char * filename) {
			 bool flag = false;
			 if (data == nullptr) {
				 return flag;
			 }
			 fstream file(filename, ios::out | ios::binary);
			 if (file.is_open()) {
				 file << "P6\n" << w << "\n" << h << "\n" << "255 " << "\n" << endl;
				 char* array = new char[3 * w*h];
				 for (int i = 0; i < 3 * w*h; i++) {
					 array[i] = data[i] * 255;
				 }
				 file.write(array, 3 * w*h);
				 delete[] array;
				 file.flush();
				 file.close();
				 flag = true;
				 return flag;
			 }
			 else {
				 cout << "File could not be opened!" << endl;
				 system("pause");
				 exit(EXIT_FAILURE);
			 }
      }
}

 




	





		 



