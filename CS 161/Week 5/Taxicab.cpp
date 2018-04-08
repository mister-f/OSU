/**************************************
 * Name: Andrew Funk
 * Date: 7-20-17
 * Description: Taxicab.cpp is the Taxicab class function implementation
 * 				file. The Taxicab class takes three integers and has two 
 * 				constructors, three get member functions, and two functions
 * 				that tell how far a class object moves in the X or Y direction.
 *************************************/

#include "Taxicab.hpp"
#include <cmath>				//Include library for absolute value function
using std::abs;					//Standard namespace for absolute value

/*************************************
 * Description: This is the default constructor member function. It
 * 				sets the coordinates and distance to zero by default.
 ************************************/

Taxicab::Taxicab()
{
	currentX = 0;
	currentY = 0;
	totalDistance = 0;
}

/*************************************
 * Description: This is a constructor member function that directly assigns
 * 				the coordinate values when a new class object is created.
 ************************************/

Taxicab::Taxicab(int xIn, int yIn)
{
	currentX = xIn;
	currentY = yIn;
	totalDistance = 0;
}

int Taxicab::getXCoord()
{
	return currentX;		//Get function for X-coordinate
}

int Taxicab::getYCoord()
{
	return currentY;		//Get function for Y-coordinate
}

int Taxicab::getDistanceTraveled()
{
	return totalDistance;	//Get function for total distance traveled
}

/*************************************
 * Description: This function takes a given movement on the X coordiante
 * 				plane, stores a new current position for the Taxicab object
 * 				and updates the total distance traveled.
 ************************************/

void Taxicab::moveX(int xMove)
{
	currentX += xMove;				//Update X coordinate
	xMove = abs(xMove);				//Absolute value for distance
	totalDistance += xMove;			//Update distance
}

/*************************************
 * Description: This function takes a given movement on the Y coordiante
 * 				plane, stores a new current position for the Taxicab object
 * 				and updates the total distance traveled.
 ************************************/

void Taxicab::moveY(int yMove)
{
	currentY += yMove;				//Update Y coordinate
	yMove = abs(yMove);				//Absolute value for distance
	totalDistance += yMove;			//Update distance
}
