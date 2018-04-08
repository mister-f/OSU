/**************************************
 * Name: Andrew Funk
 * Date: 7-9-17
 * Description: This program prompts the user for an input file 
 * 				of integers, opens the file, adds the integers together,
 * 				and outputs the total called 'sum.txt'  
 *************************************/

#include <iostream>
#include <fstream>		// To input and output to files
#include <string>		// To enter file name as a string
using namespace std;

int main ()
{
	ifstream inputFile;			// File to read data from
	string fileName;
	ofstream outputFile;		// File to write to
	int currentValue;			// Value read from file
	int total = 0;				// Running total

	// Get file containing input from user
	cout << "Enter a file name for integer input:" << endl;
	cin >> fileName;
	
	// Open input file
	inputFile.open(fileName);

	// Check if file is accessed correctly
	if (inputFile)
	{
		// Open an output file
		outputFile.open("sum.txt");
		// Loop through each value in file until end-of-file
		while (inputFile >> currentValue)
		{
			total += currentValue;
		}
		// Write total of integers to output file
		outputFile << total << endl;
		// Close output file
		outputFile.close();
	}
	// Output if file couldn't be accessed
	else
	{
		cout << "Could not access file." << endl;
	}
	
	// Close input file
	inputFile.close();

	return 0;
}
