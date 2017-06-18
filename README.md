# PicToCSV
Converts image files of almost any type to .csv files.
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
