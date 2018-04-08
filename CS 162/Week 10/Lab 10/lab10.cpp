/**************************************
 * Program Name: lab10.cpp
 * Name: Andrew Funk
 * Date: 12-01-17
 * Description: lab10 compares the run time for two types of algorithms 
 * 				that calculate the Fibonacci sequence. The functions used
 * 				to calculate the numbers are from https://www.codeproject.
 * 				com/tips/109443/fibonacci-recursive-and-non-recursive-c
 *				Code for timing the algorithms was informed by https://
 *				stackoverflow.com/questions/22387586/measuring-execution-
 *				time-of-a-function-in-c
 *************************************/

#include <iostream>
#include <chrono>
#include "FibonacciNR.h"
#include "FibonacciR.h"
#include "getValidInput.hpp"

using namespace std::chrono;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	string userEntry;
	int sequenceLength;
	
	// Get Fibonacci sequence number to compute
	cout << "Please enter a number in the Fibonacci sequence to ";
	cout << "calculate: ";
	do
	{
		getline(cin, userEntry);
		sequenceLength = getValidInt(userEntry);
		if (sequenceLength < 1)
		{
			cout << "Please enter a positive number: ";
		}
	} while (sequenceLength < 1);

	cout << endl;
	// Start recursive timing
	high_resolution_clock::time_point start = high_resolution_clock::now();
	FibonacciR recursive(sequenceLength);
	recursive.PrintFibonacci();
	// End recursive timing
	high_resolution_clock::time_point end = high_resolution_clock::now();
	// Calculate time difference
	auto timeDiff = duration_cast<microseconds>(end - start).count();
	cout << "The recursive algorithm took " << timeDiff;
	cout << " microseconds to compute." << endl;

	// Start iterative timing
	high_resolution_clock::time_point start2 = high_resolution_clock::now();
	FibonacciNR iterative(sequenceLength);
	iterative.PrintFibonacci();
	// End iterative timing
	high_resolution_clock::time_point end2 = high_resolution_clock::now();
	// Calculate time difference
	auto timeDiff2 = duration_cast<microseconds>(end2 - start2).count();
	cout << "The iterative algorithm took " << timeDiff2;
	cout << " microseconds to compute." << endl << endl;
	
	return 0;
}
