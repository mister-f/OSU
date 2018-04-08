/**************************************
 * Name: Andrew Funk
 * Date: 7-15-17
 * Description: This function accepts time as an argument
 * 				and then returns the distance an object falls
 * 				in this amount of time using the formula 
 * 				d = 0.5gt^2 
 *************************************/

#include <iostream>
using namespace std;

double fallDistance(double);

int main()
{
	double fallTime;

	cout << "Enter a time in seconds an object is falling:" << endl;
	cin >> fallTime;

	cout << "The objects travels " << fallDistance(fallTime) << " meters in ";
	cout << fallTime << " seconds." << endl;

	return 0;
}
/*
double fallDistance(double time)
{
	const double GRAVITY = 9.8;
	double distance;

	distance = 0.5 * GRAVITY * time * time;
	return distance;
}
*/

