/* CS261- Assignment 1 - Q.4*/
/* Name: Andrew Funk
 * Date: 01-18-18
 * Solution description: This program generates an array of student
						 structures. It fills that array with random
						 unique IDs and random scores. Then the array is
						 sorted based upon the scores. The pre-sorted and
						 sorted arrays are printed to the screen.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
    /*Sort the n students based on their score*/
	int swap, temp, i;

	do
	{
		swap = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (students[i - 1].score > students[i].score)
			{
				temp = students[i].score;
				students[i].score = students[i - 1].score;
				students[i - 1].score = temp;
				temp = students[i].id;
				students[i].id = students[i - 1].id;
				students[i - 1].id = temp;
				swap = 1;
			}
		}
		n = n - 1;
	} while (swap == 1);
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int i, temp, randomNumber;
	int n = 10;
    
    /*Allocate memory for n students using malloc.*/
	struct student* studentArray = malloc(n * sizeof(struct student));

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	for (i = 0; i < n; i++)
	{
		studentArray[i].id = i + 1;
	}

	/* Fisher-Yates Shuffle algorithm information sourced from:
	https://en.wikipedia.org/wiki/Fisher-Yates_shuffle */

	for (i = n - 1; i >= 1; i--)
	{
		randomNumber = (rand() % i) + 1;
		temp = studentArray[randomNumber].id;
		studentArray[randomNumber].id = studentArray[i].id;
		studentArray[i].id = temp;
	}

	for (i = 0; i < n; i++)
	{
		studentArray[i].score = rand() % 101;
	}

    /*Print the contents of the array of n students.*/
	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", studentArray[i].id, studentArray[i].score);
	}
	printf("\n");

    /*Pass this array along with n to the sort() function*/
	sort(studentArray, n);

    /*Print the contents of the array of n students.*/
	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", studentArray[i].id, studentArray[i].score);
	}

	free(studentArray);

    return 0;
}
