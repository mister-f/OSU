/**************************************
 * Name: Andrew Funk
 * Date: 7-4-17
 * Description: This program requests a temperature in Celsius
 * 				from the user, calculates the temperature in 
 * 				Fahrenheit, and then outouts the Fahrenheit 
 * 				temperature. 
 *************************************/

#include <iostream>
using namespace std;

int main ()
{
	// Declare variables
	double celsiusTemp;
	double fahrenheitTemp;

	// Ask for and store temperature from user
	cout << "Please enter a Celsius temperature." << endl;
	cin >> celsiusTemp;

	// Calculate temperature in Fahrenheit
	fahrenheitTemp = (9.0 / 5) * celsiusTemp + 32;

	// Output Fahrenheit temperature
	cout << "The equivalent Fahrenheit temperature is:" << endl;
	cout << fahrenheitTemp << endl;

	return 0;
}
