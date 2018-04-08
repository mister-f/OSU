/**************************************
 * Name: Andrew Funk
 * Date: 7-29-17
 * Description: This function takes in an array and the size of
 * 				the array. The function then returns the median of 
 * 				the array as a double. A median is returned whether 
 * 				there is an even or odd amount of values in the array. 
 *************************************/

#include <iostream>
// #include <algorithm>
using namespace std;

double findMedian(int [], int);

int main ()
{
	const int SIZE = 5;
	int testArray[SIZE] = {20, 30, 2, 7, 0};	
	
	cout << findMedian(testArray, SIZE) << endl;

	return 0;
}
/*
double findMedian(int arrayIn[], int sizeIn)
{
	sort(arrayIn, arrayIn + sizeIn);
	if (sizeIn % 2 == 0)
	{
		return ((arrayIn[(sizeIn/2) - 1] + arrayIn[sizeIn/2]) / 2.0);
	}
	else
	{
		return arrayIn[(sizeIn - 1) / 2];
	}
}
*/

