/**************************************
 * Program Name: searchSort.cpp
 * Name: Andrew Funk
 * Date: 11-18-17
 * Description: searchSort.cpp is the specification file for several
 * 				functions that search and sort small ararys.
 *************************************/

#include "searchSort.hpp"

using std::string;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

/**************************************
 * Description: The fileInput function takes an array of integers, an
 * 				array size, and an input file name as paramenters. It 
 * 				opens the input file and imports integers to fill an array
 * 				of the given size. The function also validates the input
 * 				file and gets a new file name if the given name fails to
 * 				open.
 *************************************/

void fileInput(int array[], int size, string &file)
{
	ifstream inputFile;
	int currentNumber;

	inputFile.open(file);

	// Check if file is valid
	if (!inputFile)
	{
		// Loop to get valid file name
		do
		{
			inputFile.close();
			cout << endl << "Error opening " << file << "." << endl;
			cout << "Please enter a valid input file: "; 
			getline(cin, file);
			inputFile.open(file);
		} while (!inputFile);
	}
	
	// Input values from file into array
	for (int i = 0; i < size; i++)
	{
		inputFile >> currentNumber;
		array[i] = currentNumber;
	}
	
	inputFile.close();
}

/**************************************
 * Description: linearSearch is a search function that takes an array of
 * 				integers, an array size, a search value, and a file name as
 * 				parameters. The function uses a linear search to determine
 * 				if the search value is in the array and outputs whether 
 * 				the value was found in the corresponding input file. The
 * 				linear search algorithm was adapted from C++ Early Objects,
 * 				9th Edition by Gaddis et al. Chapter 9, pg. 604.
 *************************************/

void linearSearch(int array[], int size, int value, string file)
{
	int index = 0;
	bool found = false;

	// Linear search loop
	while (index < size && !found)
	{
		if (array[index] == value)
		{
			found = true;
		}
		index++;
	}

	// Output whether search value was found
	cout << file << ": ";
	if (found)
	{
		cout << "target value found" << endl;
	}
	else
	{
		cout << "target value not found" << endl;
	}
}

/**************************************
 * Description: sortAndOutput is a function that takes an array of integers,
 * 				an array size, and input and output file names as 
 * 				parameters. The function first sorts the array in 
 * 				ascending order using a bubble sort and then outputs the 
 * 				numbers to both the given output file as well as to the 
 * 				console. The bubble sort algorithm was adapted from C++
 * 				Early Objects, 9th Edition by Gaddis et al. Chapter 9, 
 * 				pg. 615.
 *************************************/

void sortAndOutput(int array[], int size, string fileIn, string fileOut)
{
	int temp;
	bool madeSwap;
	ofstream outputFile;	

	// Bubble sort loop
	do
	{
		madeSwap = false;
		for (int count = 0; count < (size - 1); count ++)
		{
			// Swap elements if out of order
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				madeSwap = true;
			}
		}
	} while (madeSwap);		//Continue sorting until no swaps are made

	outputFile.open(fileOut);
	
	cout << fileIn << " sorted: "; 

	// Loop through array, print sorted integers to file and screen
	for (int i = 0; i < size; i++)
	{
		outputFile << array[i] << " ";
		cout << array[i] << " ";
	}

	cout << endl;
	outputFile.close();
}

/**************************************
 * Description: binarySearch is a search function that takes a sorted
 * 				array of integers, an array size, a search value, and a 
 * 				file name as parameters. The function uses a binary 
 * 				search to determine if the search value is in the sorted 
 * 				array and outputs whether the value was found in the 
 * 				corresponding input file. The binary search algorithm was 
 * 				adapted from C++ Early Objects, 9th Edition by Gaddis 
 * 				et al. Chapter 9, pg. 607.
 *************************************/

void binarySearch(int array[], int size, int value, string file)
{
	int first = 0;
	int last = size - 1;
	int middle;
	bool found = false;

	// While loop to execute binary search
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		// If value matches found equals true
		if (array[middle] == value)
		{
			found = true;
		}
		// Remove high values from search
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		// Remove low values from search
		else
		{
			first = middle + 1;
		}
	}

	// Output whether search target was found
	cout << file << ": ";
	if (found)
	{
		cout << "target value found" << endl;
	}
	else
	{
		cout << "target value not found" << endl;
	}
}	
