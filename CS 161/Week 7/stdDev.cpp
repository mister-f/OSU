/**************************************
 * Name: Andrew Funk
 * Date: 7-29-17
 * Description: stdDev is a function that takes an array of Person 
 * 				objects and its size and returns the population
 * 				standard deviation of the ages of the Person objects 
 * 				in the array. 
 *************************************/

#include <cmath>					// Needed for pow and sqrt functions
#include <vector>
#include "Person.hpp"
using std::vector;

double stdDev(Person arrayIn[], int arraySize)
{
	double total = 0;							// Total used to calculate means
	double mean;								// Used to store mean values

	vector<double> sqDiffVector(arraySize);		// Vector used to store the 
												// square of the differences

	// For loop to total all the ages stored in the Person array
	for (int count = 0; count < arraySize; count++)
	{
		total += arrayIn[count].getAge();
	}
	
	// Calculate mean of ages
	mean = total / arraySize;

	// For loop that determines the square of the mean subtracted from 
	// each age. Results are stored in a vector.
	for (int count = 0; count < arraySize; count++)
	{
		sqDiffVector[count] = pow((arrayIn[count].getAge() - mean), 2);
	}
 
	// Reset total variable
	total = 0;

	// For loop that totals the values stored in the previously
	// filled vector
	for (int count = 0; count < arraySize; count++)
	{
		total += sqDiffVector[count];
	}

	// Calculate the mean of the squared differences
	mean = total / arraySize;

	// Returns the square root of the squared difference mean
	// which is the standard deviation
	return sqrt(mean);
}
