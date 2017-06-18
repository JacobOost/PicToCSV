/*
 PicToCSV.cpp
 Created on 6/17/2017
 By: Jacob Oost (Jacob_Oost@baylor.edu or jacobobaggins@gmail.com)
 Requires: -the CImg library (included entirely in the CImg.h header file)
	   -X11 libraries (if using Linux)
	   -pthread libraries (if using Linux)
	   -ImageMagick (if using Linux)
	   -Check CImg web site (or compiler error messages) for any extra
	   Windows/Mac requirements, but I don't think there are any)
 Build command:    g++ -std=c++11 -lpthread -lX11 -o PicToCSV PicToCSV.cpp
 
 This program takes an image file IN THE SAME DIRECTORY AS THE PROGRAM and
 turns it into a .csv file where each entry corresponds to the red, green,
 and blue values in each pixel.  It uses the following format:
 R0,G0,B0,WIDTH,HEIGHT
 R1,G1,B1
 R2,G2,B2
 ...
 
 And so on, where WIDTH and HEIGHT are the pixel dimensions of the image file.
 IMPORTANT: As of 6/17/2017 this program only supports 24-bit/32-bit color images, i.e.
 one byte for each channel.
 */

#include "CImg.h"
#include <iostream>
#include <string>
#include <fstream>

#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2

using namespace cimg_library;

using uc=unsigned char;

int main()
{
  int width(0),height(0); // stores image height and width
  std::string filename;
  std::ofstream outFile;
  
  /* Next we get the filename, open the file, then read its height and width. */
  std::cout<<"Hi there!  Please enter the name of the picture file (must be included in current directory): ";
  std::cin>>filename;
  
  CImg<uc> image(filename.c_str());
  
  width=image.width();
  height=image.height();
 
  /* Prompt user for .csv file name */
  
  std::cout<<"What would you like the .csv file name to be? "<<std::endl;
  std::cin>>filename;
  outFile.open(filename);
  
  /* Do first line of file with width and height. */
  
  outFile<<width<<','<<height<<'\n';
  
  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      outFile<<(int)image(j,i,RED_CHANNEL)<<','<<(int)image(j,i,GREEN_CHANNEL)
             <<','<<(int)image(j,i,BLUE_CHANNEL)<<'\n';
    }
  }
  
  outFile.close();
  
  std::cout<<"Bye!"<<std::endl;
  
  return 0;
}