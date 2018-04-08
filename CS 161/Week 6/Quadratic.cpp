/**************************************
 * Name: Andrew Funk
 * Date: 7-23-17
 * Description: Quadratic.cpp is the Quadratic class function implementation
 * 				file. The Quadratic class takes three doubles, has two constructors,
 * 				get and set functions for each member variable, and two functions 
 * 				that return the value of the quadratic and its number of roots,
 * 				respectively. 
 *************************************/

#include "Quadratic.hpp"

/*************************************
 * Description: This is the default constructor member function. It
 * 				sets a, b, and c to one using member set fucntions.
 ************************************/

Quadratic::Quadratic()
{
	setA(1.0);
	setB(1.0);
	setC(1.0);
}

/************************************
 * Description: This is a constructor member function that uses member
 * 				set fucntions to assign values to a, b, and c.
 ***********************************/

Quadratic::Quadratic(double aIn, double bIn, double cIn)
{
	setA(aIn);
	setB(bIn);
	setC(cIn);
}
	
double Quadratic::getA()		//Get function
{
	return a;
}

double Quadratic::getB()		//Get function
{
	return b;
}

double Quadratic::getC()		//Get function
{
	return c;
}

void Quadratic::setA(double aIn)	//Set function
{
	a = aIn;
}

void Quadratic::setB(double bIn)	//Set function
{
	b = bIn;
}

void Quadratic::setC(double cIn)	//Set function
{
	c = cIn;
}

/**************************************
 * Description: This function takes in a value for x and returns
 * 				the value of the quadratic as a double.
 *************************************/

double Quadratic::valueFor(double xIn)
{
	return ((a * xIn * xIn) + (b * xIn) + c);
}

/************************************
 * Description: This member fucntion evaluates the discriminant of
 * 				the quadratic and returns the number of real roots
 * 				for the equation as an integer depending on whather 
 * 				the disciminant is positive, negative, or zero.
 ***********************************/

int Quadratic::numRealRoots()
{
	double discriminant;

	//Set the value of the discriminant
	discriminant = ((b * b) - (4 * a * c));

	//Check if discriminant is positive(two roots) using a cutoff
	//of 0.00001 since we are comparing floating point numbers
	if (discriminant > 0.00001)
	{
		return 2;
	}
	//Check if discriminant is negative (no roots)
	else if (discriminant < -0.00001)
	{
		return 0;
	}
	//Discriminant must be zero if not positive or 
	//negative (one root)
	else
	{
		return 1;
	}
}

