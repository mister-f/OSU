/**************************************
 * Name: Andrew Funk
 * Date: 7-20-17
 * Description: Box.cpp is the Box class function implementation
 * 				file. The Box class takes three doubles and includes
 * 				three set functions. Functions to calculate surface 
 * 				area and volume are also present. 
 *************************************/

#include "Box.hpp"

/*************************************
 * Description: This is the default constructor member function. It
 * 				sets height, width, and length to one by default using
 * 				class member functions.
 ************************************/

Box::Box()
{
	setHeight(1.0);
	setWidth(1.0);
	setLength(1.0);
}

/*************************************
 * Description: This is a constructor member function that uses set
 * 				member functions to assign values when a new class
 * 				object is created.
 ************************************/

Box::Box(double heightIn, double widthIn, double lengthIn)
{
	setHeight(heightIn);
	setWidth(widthIn);
	setLength(lengthIn);
}

void Box::setHeight(double heightIn)
{
	height = heightIn;		//Setter function for height
}

void Box::setWidth(double widthIn)
{
	width = widthIn;		//Setter function for width
}

void Box::setLength(double lengthIn)
{
	length = lengthIn;		//Setter function for length
}

/*************************************
 * Description: This function calculates the volume of a class
 * 				object by multiplying its length, width, and 
 * 				height and returns the value as a double.
 ************************************/

double Box::calcVolume()
{
	return (height * width * length);
}

/*************************************
 * Description: This function calculates the surface area of 
 * 				a class object by summing the area of each unique
 * 				side times two (for opposite sides). The result is
 * 				returned as a double.
 ************************************/

double Box::calcSurfaceArea()
{
	return (2 * length * width) + (2 * length * height) + (2 * width * height);
}

