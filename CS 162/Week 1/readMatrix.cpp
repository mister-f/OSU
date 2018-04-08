/**************************************
 * Program Name: readMatrix.cpp
 * Name: Andrew Funk
 * Date: 9-25-17
 * Description: This function takes two arguments, a pointer to a 
 * 				2D matrix, and the size of that matrix. The matrix
 * 				will have an equal number of rows and columns. The 
 * 				function gets user input for each cell in the matrix
 * 				and stores it.
 *************************************/

#include "readMatrix.hpp"
#include "getValidInt.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;

void readMatrix(int** matrixIn, int sizeIn)
{
	string numberEntry;

	//Loop through each row and column
	for (int i = 0; i < sizeIn; i++)
	{
		for (int j = 0; j < sizeIn; j++)
		{
			cout << "Enter an integer value for [" << i;
			cout << "][" << j << "]" << endl;
			// Enter value as a string and use getValidInt to validate
			getline(cin, numberEntry);
			matrixIn[i][j] = getValidInt(numberEntry);
		}
	}
}

