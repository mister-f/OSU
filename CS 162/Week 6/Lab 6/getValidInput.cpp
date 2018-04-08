/**************************************
 * Program Name: getValidInuput.cpp
 * Name: Andrew Funk
 * Date: 09-25-17
 * Description: These functions takes in a string as an argument
 * 				and check to see if it has the form of a valid integer or
 * 				character. If the string is not an integer or character,
 * 				it propmts the user to re-enter the value until a valid 
 * 				entry is obtained. The function returns the value in 
 * 				either the integer or character data type.
 *************************************/

#include <iostream>
#include <string>
#include "getValidInput.hpp"
using std::string;
using std::cout;
using std::cin;
using std::endl;
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
	
		if (strIn.length() == 0)
		{
			goodString = false;
		}
	
		// Get another entry if previous entry is bad
		if (goodString == false)
		{
			cout << "Invalid entry, please re-enter: ";
			getline(cin, strIn);
		}
	}
	
	// Convert and return value as an integer
	return stoi(strIn);
}

int getValidChar(string strIn)
{
	bool goodString = false;

	// While loop executes until valid input is received
	while (goodString == false)
	{
		goodString = true;
		
		for (unsigned int i = 0; i < strIn.length(); i++)
		{
			// Ensure first character is an alphabetic character
			if ((i == 0) && (!(isalpha(strIn[i]))))
			{
				goodString = false;
			}
			// Ensure there are no remaining characters
			else if ((i != 0))
			{
				goodString = false;
			}
		}
	
		if (strIn.length() == 0)
		{
			goodString = false;
		}
	
		// Get another entry if previous entry is bad
		if (goodString == false)
		{
			cout << "Invalid entry, please re-enter: ";
			getline(cin, strIn);
		}
	}
	
	// Return the character
	return strIn[0];
}
