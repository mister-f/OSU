/**************************************
 * Program Name: getValidInt.cpp
 * Name: Andrew Funk
 * Date: 09-25-17
 * Description: This function takes in a string as an argument
 * 				and checks to see if it has the form of a valid integer.
 * 				If the string is not an integer, it propmts the user
 * 				to re-enter the value until a valid entry is obtained. The
 * 				function returns the value in the integer data type.
 *************************************/

#include <iostream>
#include <string>
#include "getValidInt.hpp"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stoi;

int getValidInt(string strIn)
{
	bool goodString = false;

	// While loop executes until valid input is received
	while (goodString == false)
	{
		goodString = true;
		
		for (unsigned int i = 0; i < strIn.length(); i++)
		{
			// Ensure first character is a digit or minus sign
			// (but not just a single minus sign)
			if ((i == 0) && (!(isdigit(strIn[i]) || 
				((strIn[i] == '-') && (strIn.length() != 1)))))
			{
				goodString = false;
			}
			// Ensure remaining characters are digits
			else if ((i != 0) && !isdigit(strIn[i]))
			{
				goodString = false;
			}
		}
		
		// Get another entry if previous entry is bad
		if (goodString == false)
		{
			cout << "Please re-enter:" << endl;
			getline(cin, strIn);
		}
	}
	
	// Convert and return value as an integer
	return stoi(strIn);
}
