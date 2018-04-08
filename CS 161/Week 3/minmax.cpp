/**************************************
 * Name: Andrew Funk
 * Date: 7-9-17
 * Description: This program prompts the user to enter a 
 * 				number of integers, then prompts for those integers
 * 				and outputs the minimum and maximum values entered.   
 *************************************/

#include <iostream>
using namespace std;

int main ()
{
	int entryNumber,	//number of integers to test
		userEntry,		//user entered integer
		minimum,
		maximum;

	//Prompt user for number of integers and integers themselves
	cout << "How many integers would you like to enter?" << endl;
	cin >> entryNumber;
	cout << "Please enter " << entryNumber << " integers." << endl;

	//Loop set to run for the total number of integers entered
	for (int counter = 1; counter <= entryNumber; counter++)
	{
		//Input number from user
		cin >> userEntry;
		
		//For first loop execution, initialize min and max to entry
		if (counter == 1)
		{
			minimum = userEntry;
			maximum = userEntry;
		}
		//Test entry against stored min and max
		else
		{
			if (userEntry < minimum)
			{
				//Overwrite minimum if entry is lower
				minimum = userEntry;
			}
			if (userEntry > maximum)
			{
				//Overwrite maximum if entry is higher
				maximum = userEntry;
			}
		}
	}

	//Output min and max values to screen
	cout << "min: " << minimum << endl;
	cout << "max: " << maximum << endl;
	return 0;
}
