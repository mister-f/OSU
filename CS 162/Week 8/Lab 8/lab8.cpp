/**************************************
 * Program Name: lab8.cpp
 * Name: Andrew Funk
 * Date: 11-18-17
 * Description: lab8.cpp contains the main function to execute several 
 * 				searches and sorts, along with inputting and outputting 
 * 				the associated data.
 *************************************/

#include <iostream>
#include <string>
#include "getValidInput.hpp"
#include "searchSort.hpp"

using std::cin;
using std::cout;
using std::endl;

const int ARRAY_SIZE = 10;

int main ()
{
	string inFileA;
	string inFileB;
	string inFileC;
	string inFileD;
	string outFileA;
	string outFileB;
	string outFileC;
	string outFileD;
	string userEntry;
	int arrayA[ARRAY_SIZE];
	int arrayB[ARRAY_SIZE];
	int arrayC[ARRAY_SIZE];
	int arrayD[ARRAY_SIZE];
	int target;

	// Get four file names for input
	cout << endl << "Enter first input file: ";
	getline(cin, inFileA);
	cout << "Enter second input file: ";
	getline(cin, inFileB);
	cout << "Enter third input file: ";
	getline(cin, inFileC);
	cout << "Enter fourth input file: ";
	getline(cin, inFileD);
	
	// Read numbers from files into arrays
	fileInput(arrayA, ARRAY_SIZE, inFileA);
	fileInput(arrayB, ARRAY_SIZE, inFileB);
	fileInput(arrayC, ARRAY_SIZE, inFileC);
	fileInput(arrayD, ARRAY_SIZE, inFileD);

	// Get a search value
	cout << endl << "Please enter a search target: ";
	getline(cin, userEntry);
	target = getValidInt(userEntry);
	cout << endl;

	// Perform a linear search of the value on each array
	linearSearch(arrayA, ARRAY_SIZE, target, inFileA);	
	linearSearch(arrayB, ARRAY_SIZE, target, inFileB);	
	linearSearch(arrayC, ARRAY_SIZE, target, inFileC);	
	linearSearch(arrayD, ARRAY_SIZE, target, inFileD);	

	// Get output file names for sorted numbers
	cout << endl << "Enter first output file: ";
	getline(cin, outFileA);
	cout << "Enter second output file: ";
	getline(cin, outFileB);
	cout << "Enter third output file: ";
	getline(cin, outFileC);
	cout << "Enter fourth output file: ";
	getline(cin, outFileD);
	cout << endl;	

	// Sort numbers and output to files
	sortAndOutput(arrayA, ARRAY_SIZE, inFileA, outFileA);
	sortAndOutput(arrayB, ARRAY_SIZE, inFileB, outFileB);
	sortAndOutput(arrayC, ARRAY_SIZE, inFileC, outFileC);
	sortAndOutput(arrayD, ARRAY_SIZE, inFileD, outFileD);

	// Get another search value
	cout << endl << "Please enter a search target: ";
	getline(cin, userEntry);
	target = getValidInt(userEntry);
	cout << endl;
	
	// Perform binary search for value on sorted arrays
	binarySearch(arrayA, ARRAY_SIZE, target, inFileA);	
	binarySearch(arrayB, ARRAY_SIZE, target, inFileB);	
	binarySearch(arrayC, ARRAY_SIZE, target, inFileC);	
	binarySearch(arrayD, ARRAY_SIZE, target, inFileD);	

	return 0;
}
