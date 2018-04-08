/**************************************
 * Program Name: letterCount.cpp	
 * Name: Andrew Funk
 * Date: 10-07-17
 * Description: The letterCount program asks a user for an input file
 * 				and opens it. It reads in each paragraph (lines separated
 * 				by \n" and counts the frequency of letters in the 
 * 				paragraph. It then outputs these letter frequencies to 
 * 				files named by the user. Letter case does not matter, and 
 * 				frequencies are based on the standard English alphabet.
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "output_letters.hpp"
#include "count_letters.hpp"

int main()
{
	const int ALPHA_SIZE = 26;
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string fileName;
	int letterArray[ALPHA_SIZE];

	// Get input from user
	std::cout << "Enter a file name to read data from: ";
	std::getline(std::cin, fileName);

	inputFile.open(fileName);

	// Check for file open fail, abort program with warning upon fail
	if (!inputFile)
	{
		std::cout << "File open error." << std::endl;
		return 1;
	}
	
	// While loop continues until end of input file
	while (inputFile)
	{
		// Reset counting array to zeroes before each paragraph is counted
		for (int i = 0; i < ALPHA_SIZE; i++)
		{
			letterArray[i] = 0;
		}
		count_letters(inputFile, letterArray);
		output_letters(outputFile, letterArray);
		// Peek function is used to check for EOF after each \n
		inputFile.peek();
	}

	inputFile.close();

	return 0;
}

