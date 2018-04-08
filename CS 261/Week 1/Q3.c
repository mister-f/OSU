/* CS261- Assignment 1 - Q.3*/
/* Name: Andrew Funk
 * Date: 01-18-18
 * Solution description: This program creates an array and fills it
						 with random integers. It prints the array,
						 calls a sort function, and then prints the 
						 sorted array. The sort performed is a bubble
						 sort.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/  
	int swap, temp, i;

	do
	{
		swap = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (number[i - 1] > number[i])
			{
				temp = number[i];
				number[i] = number[i - 1];
				number[i - 1] = temp;
				swap = 1;
			}
		}
		n = n - 1;
	} while (swap == 1);
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
	int* intArray = malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
	int i;

	for (i = 0; i < n; i++)
	{
		intArray[i] = rand() % 101;
	}

    /*Print the contents of the array.*/
	for (i = 0; i < n; i++)
	{
		printf("%d ", intArray[i]);
	}
	printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
	sort(intArray, n);

    /*Print the contents of the array.*/    
	for (i = 0; i < n; i++)
	{
		printf("%d ", intArray[i]);
	}
	printf("\n");

	free(intArray);

    return 0;
}
