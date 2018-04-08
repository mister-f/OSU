/**************************************
 * Name: Andrew Funk
 * Date: 7-15-17
 * Description: This function accepts time as an argument
 * 				and then returns the distance an object falls
 * 				in this amount of time using the formula 
 * 				d = 0.5gt^2 
 *************************************/

// Main function for testing purposes
/*************************************
#include <iostream>
using namespace std;

double fallDistance(double);	// Function prototype 

int main()
{
	double fallTime;

	// Get falling time input
	cout << "Enter a time in seconds an object is falling:" << endl;
	cin >> fallTime;

	// Output distance traveled using fallDistance function
	cout << "The objects travels " << fallDistance(fallTime) << " meters in ";
	cout << fallTime << " seconds." << endl;

	return 0;
}
***************************************/

/**************************************
 * Description: fallDistance takes a double representing time in seconds
 * 				and returns a double of the distance an object falls in that 
 * 				time in meters.
 *************************************/

double fallDistance(double time)
{
	const double GRAVITY = 9.8;		// Gravity acceleration constant
	double distance;

	// Calculate distance with formula d=0.5gt^2
	distance = 0.5 * GRAVITY * time * time;
	return distance;
}
