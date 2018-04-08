/* CS261- Assignment 1 - Q.1*/
/* Name: Andrew Funk
 * Date: 01-15-18
 * Solution description: This program generates an array of structs that 
 * 						 hold student data. It then fills that array with 
 * 						 random scores and IDs, prints the values, and then
 * 						 also prints the min, max and averages. It then 
 * 						 frees any allocated memory.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
    /*Allocate memory for ten students*/
	int size = 10;
	struct student* newArray = malloc(size * sizeof(struct student));

    /*return the pointer*/
	return newArray;
}

void generate(struct student* students){
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int i;
	int randomNumber;
	int temp;
	int size = 10;

	for (i = 0; i < size; i++)
	{
		students[i].id = i + 1;
	}

	/* Fisher-Yates Shuffle algorithm information sourced from:
		https://en.wikipedia.org/wiki/Fisher-Yates_shuffle */

	for (i = size - 1; i >= 1; i--)
	{
		randomNumber = (rand() % i) + 1;
		temp = students[randomNumber].id;
		students[randomNumber].id = students[i].id;
		students[i].id = temp;
	}

	for (i = 0; i < size; i++)
	{
		students[i].score = rand() % 101;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int i;
	int size = 10;

	for (i = 0; i < size; i++)
	{
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int i;
	int min;
	int max;
	double average = 0;
	int size = 10;

	min = students[0].score;
	max = students[0].score;

	for (i = 0; i < size; i++)
	{
		if (students[i].score < min)
		{
			min = students[i].score;
		}
		if (students[i].score > max)
		{
			max = students[i].score;
		}
		average += students[i].score;
	}

	average /= size;

	printf("\nThe minimum score is: %d\n", min);
	printf("The maximum score is: %d\n", max);
	printf("The average score is: %.1f\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();

    /*call generate*/
	generate(stud);

    /*call output*/
	output(stud);

    /*call summary*/
	summary(stud);

    /*call deallocate*/
	deallocate(stud);

    return 0;
}
