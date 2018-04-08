/**************************************
 * Name: Andrew Funk
 * Date: 7-15-17
 * Description: This set of functions takes three integer variables
 * 				by reference and sorts them in ascending order. 
 *************************************/

// Header file and namespace used for testing in main
// #include <iostream>
// using namespace std;

/************************************
 * Description: This function takes two integers by reference and
 * 				swaps their values.
 ***********************************/

void swapPlaces(int &slotA, int &slotB)
{
	// tempSlot variable is used so data is not overwritten
	int tempSlot = slotA;
	slotA = slotB;
	slotB = tempSlot;
} 

/***********************************
 * Description: This function takes three integers by reference. It
 * 				then loops twice, comparing each value sequentially. If
 * 				values are out of order it calls a function to swap
 * 				their places.
 **********************************/

void smallSort(int &numA, int &numB, int &numC)
{
	// Loop through the values twice, comparing each value sequentially
	// Two passes are needed to ensure sorting is complete
	for (int i = 1; i <= 2; i++)
		{
			// If a number is higher than the following number, they are swapped
			if (numA > numB)
			{
				swapPlaces(numA, numB);
			}
			if (numB > numC)
			{
				swapPlaces(numB, numC);
			}
		}
}

// Main function for testing purposes
/***********************************************
int main()
{
	int entryA, entryB, entryC;

	cout << "Enter three integers:" << endl;
	cin >> entryA >> entryB >> entryC;

	smallSort(entryA, entryB, entryC);

	cout << entryA << ", " << entryB << ", " << entryC << endl;

	return 0;
}
***********************************************/
