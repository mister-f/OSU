/**************************************
 * Program Name: matrixCalc.cpp
 * Name: Andrew Funk
 * Date: 9-25-17
 * Description: This program generates either a 2x2 or 3x3 array
 * 				that is dynamically allocated in memory. A user can 
 * 				fill the array in with values, after which the program
 * 				will print the array along with the calculated 
 * 				determinant value. The program then de-allocates any 
 * 				memory. The program can be run by compiling with the 
 * 				associated makefile and running the 'matrixCalc' 
 * 				file.
 *************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "readMatrix.hpp"
#include "determinant.hpp"
#include "getValidInt.hpp"
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::setw;

int main()
{
	// Initialize variables
	int matrixSize;
	int** mainArray;
	string sizeEntry;

	// Get array size from user
	do
	{
		cout << "Please enter either 2 or 3 for a 2 x 2 or 3 x 3 matrix.";
		cout << endl;
		getline(cin, sizeEntry);
		matrixSize = getValidInt(sizeEntry);
	} while (!(matrixSize == 2 || matrixSize == 3));

	// Dynamically allocate a 2D array
	mainArray = new int*[matrixSize];
	for (int i = 0; i < matrixSize; i++)
	{
		mainArray[i] = new int[matrixSize];
	}

	// Get values using readMatrix function
	readMatrix(mainArray, matrixSize);	
	
	// Print matrix to user
	cout << endl<< "Here is your matrix:" << endl << endl;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << setw(4) << mainArray[i][j] << " ";
		}
		cout << endl;
	}
	
	// Print determinant using the determinant function to calculate
	cout << endl << "The determinant of the matrix is: ";
	cout << determinant(mainArray, matrixSize) << endl << endl;

	// Delete dynamically allocated memory
	for (int i = 0; i < matrixSize; i++)
	{
		delete[] mainArray[i];
	}
	delete[] mainArray;

	return 0;
}

