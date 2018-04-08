/**************************************
 * Name: Andrew Funk
 * Date: 7-4-17
 * Description: This program asks requests a user input of five
 * 				numbers, averages the numbers, and outputs the 
 * 				average to the screen.
 *************************************/

#include <iostream>
using namespace std;

int main ()
{
	// Declare variables
	double number1, number2, number3, number4, number5;
	double average;

	// Request and input five numbers from user
	cout << "Please enter five numbers." << endl;
	cin >> number1 >> number2 >> number3;
	cin >> number4 >> number5;

	// Calculate average
	average = (number1 + number2 + number3 + number4 + number5) / 5;

	// Output average to user
	cout << "The average of those numbers is:" << endl;
	cout << average << endl;

	return 0;
}
