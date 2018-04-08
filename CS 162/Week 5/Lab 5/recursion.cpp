/**************************************
 * Program Name: recursion.cpp
 * Name: Andrew Funk
 * Date: 10-26-17
 * Description: This is the implementation file for the lab 5 recursion
 * 				functions. Each function exhibits some sort of recursive
 * 				behavior
 *************************************/

#include <iostream>
#include "recursion.hpp"
using std::cout;
using std::endl;

/***************************************
 * Description: reverseString takes a string and the length of that
 * 				string and uses recursive calls to print the string
 * 				in reverse.
 **************************************/

void reverseString(string stringIn, int length)
{
	// Base case is an empty string
	if (length != 0)
	{
		cout << stringIn[length - 1];
		reverseString(stringIn, length - 1);
	}
}

/***************************************
 * Description: sumArray takes a pointer to an array of integers along
 * 				with the size of the array. It then recursively adds 
 * 				together the elements in the array and returns the result
 * 				as an integer.
 **************************************/

int sumArray(int* arrayIn, int size)
{
	// Base case is a single element array
	if (size == 1)
	{
		return arrayIn[size - 1];
	}
	else
	{
		return arrayIn[size - 1] + sumArray(arrayIn, size - 1);
	}
}

/**************************************
 * Description: triangularNumber takes in an integer and uses recursive
 * 				calls to find the triangular number of that integer. 
 * 				The triangular number is returned as an integer.
 *************************************/

int triangularNumber(int triangle)
{
	// Base case of 0
	if (triangle == 0)
	{
		return triangle;
	}
	else
	{
		return triangle + triangularNumber(triangle - 1);
	}
}
