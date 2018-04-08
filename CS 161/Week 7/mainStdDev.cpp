/**************************************
 * Name: Andrew Funk
 * Date: 7-29-17
 * Description: stdDev.cpp is a function that takes an array of 
 * 				Person objects and its size and returns the population
 * 				standard deviation of the ages of the Person objects in
 * 				the array. 
 *************************************/

#include <iostream>
//#include <cmath>
//#include <vector>
#include "Person.hpp"
using namespace std;

double stdDev(Person [], int);

int main ()
{
	const int SIZE = 4;
	Person testArray[SIZE] = {  Person("John", 22.5),
								Person("Andy", 1.6),
								Person("Susie", 102),
								Person("Mitsy", 49) };

	cout << stdDev(testArray, SIZE) << endl;	

	return 0;
}

/*
double stdDev(Person arrayIn[], int arraySize)
{
	double total = 0;
	double mean;
	vector<double> sqDiffVector(arraySize);

	for (int count = 0; count < arraySize; count++)
	{
		total += arrayIn[count].getAge();
	}
	
	mean = total / arraySize;

	for (int count = 0; count < arraySize; count++)
	{
		sqDiffVector[count] = pow((arrayIn[count].getAge() - mean), 2);
	}
 
	total = 0;

	for (int count = 0; count < arraySize; count++)
	{
		total += sqDiffVector[count];
	}

	mean = total / arraySize;

	return sqrt(mean);
}
*/
