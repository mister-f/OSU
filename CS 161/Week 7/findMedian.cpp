/**************************************
 * Name: Andrew Funk
 * Date: 7-29-17
 * Description: This function takes in an array and the size of
 * 				the array. The function then sorts the array and 
 * 				returns the median of the array as a double. A 
 * 				median is returned whether there is an even or 
 * 				odd amount of values in the array. 
 *************************************/

#include <algorithm>			//Header file for use of sort
using std::sort;

double findMedian(int arrayIn[], int sizeIn)
{
	// Sort the array in ascending order
	sort(arrayIn, arrayIn + sizeIn);

	// If array contains an even number of values, return the 
	// mean of the middle two values.
	if (sizeIn % 2 == 0)
	{
		return ((arrayIn[(sizeIn / 2) - 1] + arrayIn[sizeIn / 2]) / 2.0);
	}
	
	// Otherwise array has an odd number of values, return the
	// middle value of the sorted array. 
	else
	{
		return arrayIn[(sizeIn - 1) / 2];
	}
}
