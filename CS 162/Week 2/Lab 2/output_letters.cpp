/**************************************
 * Program Name: output_letters.cpp	
 * Name: Andrew Funk
 * Date: 10-07-17
 * Description: This function takes a an output file stream by reference
 * 				and a pointer to an array of integers as parameters. The 
 * 				function asks the user for the name of an output file and 
 * 				then writes the frequency of each letter of an analyzed 
 * 				paragraph as stored in the array. The array contents must 
 * 				be stored in English alphabetical order.
 *************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "output_letters.hpp"

void output_letters(std::ofstream &streamOut, int* letterArray)
{
	std::string outputFile;
	char letter = 'a';
	const int ALPHA_SIZE = 26;

	// Get output file name from user
	std::cout << "Enter a file name to save the count to: ";
	std::getline(std::cin, outputFile);

	streamOut.open(outputFile);

	// Loop through alphabet, printing frequency from array
	for (int i = 0; i < ALPHA_SIZE; i++)
	{
		streamOut << letter << ": " << letterArray[i] << "\n";
		// Increment to next letter
		letter++;
	}

	streamOut.close();
}

