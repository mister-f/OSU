/**************************************
 * Name: Andrew Funk
 * Date: 7-15-17
 * Description: This function takes in a starting integer and
 * 				returns the number of steps in its hailstone
 * 				sequence to reach one.  A hailstone sequence 
 * 				divides even numbers by two and for odd numbers
 * 				multiplies by three and adds one.
 *************************************/


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
/*
int hailstone(int startNum)
{
	int stepCount = 0;

	while (startNum != 1)
	{
		if (startNum % 2 == 0)
		{
			startNum /= 2;
		}
		else
		{
			startNum = (startNum * 3) + 1;
		}
		cout << startNum << ", ";
		stepCount++;
	}
	cout << endl;
	return stepCount;
}
*/
