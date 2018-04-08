/***********************************************************
* Author:				Andrew Funk
* Date Created:			01/11/18
* Filename:				triangle.c
*
* Overview:	
*	This program calculates the are of a triangle.
*
* Input:
*	Input consists of the length of three sides of the 
*	triangle. These lengths are entered on the command
*	line when executing the program.
*	Example input: triangle 3 4 5
*
* Output:
*	The output consists of the computed area of the 
*	triangle (if it can be computed), or an error stating 
*	that the given triangle is impossible.
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	double sideA, sideB, sideC;
	double area, halfPerimeter;
	
	// Check that exactly 3 sides have been entered
	while (argc != 4)
	{
		printf("Correct usage: triangle 'side 1' 'side 2' 'side 3'\n");
		return 1;
	}

	// Save command line arguments to variables as doubles
	sideA = atof(argv[1]);
	sideB = atof(argv[2]);
	sideC = atof(argv[3]);

	// Verify that the 3 sides form a valid triangle
	if ((sideA + sideB < sideC) || 
		(sideA + sideC < sideB) || 
		(sideC + sideB < sideA))
	{
		printf("Those sides do not form a valid triangle.\n");
		return 1;
	}
	// Use Heron's formula to calculate area
	else
	{
		halfPerimeter = (sideA + sideB + sideC) / 2;
		area = sqrt(halfPerimeter * 
				   (halfPerimeter - sideA) * 
				   (halfPerimeter - sideB) * 
				   (halfPerimeter - sideC));

		printf("The area of a triangle with sides of ");
		printf("%f, %f, and %f is %f.\n", sideA, sideB, sideC, area);
		return 0;
	}
}