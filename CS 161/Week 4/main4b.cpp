/**************************************
 * Name: Andrew Funk
 * Date: 7-15-17
 * Description: This set of functions takes three integers variables
 * 				by reference and sorts them in ascending order. 
 *************************************/

#include <iostream>
using namespace std;
/*
void swapPlaces(int &slotA, int &slotB)
{
	int tempSlot = slotA;
	slotA = slotB;
	slotB = tempSlot;
} 

void smallSort(int &numA, int &numB, int &numC)
{
	for (int i = 1; i <= 2; i++)
		{
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
*/

void smallSort(int &, int &, int &);

int main()
{
	int entryA, entryB, entryC;

	cout << "Enter three integers:" << endl;
	cin >> entryA >> entryB >> entryC;

	smallSort(entryA, entryB, entryC);

	cout << entryA << ", " << entryB << ", " << entryC << endl;

	return 0;
}
