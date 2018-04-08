/**************************************
 * Program Name: count_letters.cpp	
 * Name: Andrew Funk
 * Date: 10-07-17
 * Description: This function takes as inputs an input file stream
 * 				by reference and a pointer to an array of integers. 
 * 				The function gets a line from the stream and then 
 * 				loops througheach character in the line. A counter 
 * 				is then incremented in the array corresponding to what 
 * 				character is encountered. Letter case does not matter. 
 *************************************/

#include <string>
#include <cctype>
#include "count_letters.hpp"

void count_letters(std::ifstream &streamIn, int* letterArray)
{
	char currentLetter;
	std::string currentString;

	// Get a line from the stream and store as a string
	getline(streamIn, currentString);

	// Loop through the line based on its length
	for (unsigned int i = 0; i < currentString.length(); i++)
	{
		// Convert any upper case letters to lower case
		currentLetter = tolower(currentString[i]);

		// Check if ASCII value of character is a lowercase letter
		if ((currentLetter >= 97) && (currentLetter <= 122))
		{
			// Increment corresponding element in counting array
			letterArray[currentLetter - 97]++;
		}
	}
}
