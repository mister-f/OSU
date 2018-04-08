/**************************************
 * Name: Andrew Funk
 * Date: 7-15-17
 * Description: This function takes in a starting integer and
 * 				returns the number of steps in its hailstone
 * 				sequence to reach one.  A hailstone sequence 
 * 				divides even numbers by two and for odd numbers
 * 				multiplies by three and adds one.
 *************************************/

// Main function for testing purposes
/*************************************
#include <iostream>
using namespace std;

int hailstone(int); 

int main()
{
	int userEntry;
	
	cout << "Enter a starting integer:" << endl;
	cin >> userEntry;

	cout << "The number of hailstone steps to reach one is ";
	cout << hailstone(userEntry) << endl;

	return 0;
}
****************************************/

/***************************************
 * Description: This function accepts an ineteger as a starting value
 * 				and then returns the number of steps in its hailstone
 * 				sequence to reach one. It returns the number of steps 
 * 				as an integer.
 **************************************/

int hailstone(int startNum)
{
	int stepCount = 0;		// Accumulator for the number of steps

	// The while loop executes until the sequence reaches one
	while (startNum != 1)
	{
		// Tests if current number is even and divides by two if it is
		if (startNum % 2 == 0)
		{
			startNum /= 2;
		}
		// Otherwise number is odd and is multiplied by three and added to one
		else
		{
			startNum = (startNum * 3) + 1;
		}
		// Counter is increased by one on each loop pass
		stepCount++;
	}
	
	return stepCount;
}
