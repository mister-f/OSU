/**************************************
 * Program Name: determinant.cpp
 * Name: Andrew Funk
 * Date: 9-25-17
 * Description: This function takes two arguments, a pointer to 
 * 				a 2D array and the size of the array. The array 
 * 				being passed to the determinant function must
 * 				be either 2x2 or 3x3. The function calculates the
 * 				determinant of the matrix and then returns this 
 * 				value as an integer.
 *************************************/

#include "determinant.hpp"

int determinant(int** matrixIn, int sizeIn)
{
	// Calculate and return determinant for 2x2 matrix
	if (sizeIn == 2)
	{
		return ((matrixIn[0][0] * matrixIn[1][1]) - 
				(matrixIn[0][1] * matrixIn[1][0]));
	}
	// Calculate and return determinant for 3x3 matrix
	else
	{
		return ((matrixIn[0][0] * ((matrixIn[1][1] * matrixIn[2][2]) - 
				(matrixIn[1][2] * matrixIn[2][1]))) - 
				(matrixIn[0][1] * ((matrixIn[1][0] * matrixIn[2][2]) - 
				(matrixIn[1][2] * matrixIn[2][0]))) +
				(matrixIn[0][2] * ((matrixIn[1][0] * matrixIn[2][1]) - 
				(matrixIn[1][1] * matrixIn[2][0]))));
	}
}

