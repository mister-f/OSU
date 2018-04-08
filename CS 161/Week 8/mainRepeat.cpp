/**************************************
 * Name: Andrew Funk
 * Date: 8-4-17
 * Description: The repeatArray function takes a reference to a 
 * 				pointer to a dynamically allocated array of doubles
 * 				along with the size of the array. It replaces the array
 * 				with one twice as large and fills the new array with 
 * 				the repeated values of the original array. The function 
 * 				also prevents memory leaks. 
 *************************************/

#include <iostream>
using namespace std;

void repeatArray(double* &, int);

int main()
{
	int size = 10;

	double* myArray = new double[size];

	for (int i = 0; i < size; i++)
	{
		myArray[i] = (i + 1);
	}

	repeatArray(myArray, size);

	for (int i = 0; i < (size * 2); i++)
	{
		cout << myArray[i] << endl;
	}

	delete [] myArray;

	return 0;
}

/*****************************************
 * Description: The repeatArray function takes a reference to a 
 * 				pointer to a dynamically allocated array of doubles
 * 				along with the size of the array. It replaces the array
 * 				with one twice as large and fills the new array with 
 * 				repeated values. The function also prevents memry leaks.
 ****************************************/

/*
void repeatArray(double* &smallArray, int arraySize)
{
	double* tempArray = nullptr;		// Temporary array to double size
	double* tempPtr = nullptr;			// Pointer used for swapping
	
	// Define a new dynamically allocated array twice the size as
	// the original.
	tempArray = new double[arraySize * 2];

	// Fill the new array with repeated values, using modulus value
	// for the doubled spaces.
	for (int i = 0; i < (arraySize * 2); i++)
	{
		tempArray[i] = smallArray[i % (arraySize)];
	}

	// Swap the addresses of the pointers with the help of the
	// temporary pointer
	tempPtr = smallArray;
	smallArray = tempArray;
	tempArray = tempPtr;

	// Delete the original array from the heap that is now at the
	// address held in tempArray 
	delete [] tempArray;
}
*/
