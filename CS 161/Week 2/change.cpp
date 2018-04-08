/**************************************
 * Name: Andrew Funk
 * Date: 7-4-17
 * Description: This program asks the user for a number in cents,
 * 				calculates the change in the fewest number of coins
 * 				and then outputs those coin numbers to the screen. 
 *************************************/

#include <iostream>
using namespace std;

int main ()
{
	// Declare variables
	int totalCents;
	int quarters, dimes, nickels, pennies;

	// Get and store number of cents from user
	cout << "Please enter an amount in cents less than a dollar.";
	cout << endl;
	cin >> totalCents;

	// Calculate change using mod and integer division
	quarters = totalCents / 25;
	dimes = (totalCents % 25) / 10;
	nickels = ((totalCents % 25) % 10) / 5;
	pennies = ((totalCents % 25) % 10) % 5;

	// Output change to user
	cout << "Your change will be:" << endl;
	cout << "Q: " << quarters << endl;
	cout << "D: " << dimes << endl;
	cout << "N: " << nickels << endl;
	cout << "P: " << pennies << endl;

	return 0;
}
