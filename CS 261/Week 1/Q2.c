/* CS261- Assignment 1 - Q.2*/
/* Name: Andrew Funk
 * Date: 01-15-18
 * Solution description: This program declares three integer values
						 and passes them (in different manners) to a 
						 function foo. The function performs some operations
						 and returns a result. The results are printed.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;

    /*Set b to half its original value*/
	*b /= 2;

    /*Assign a+b to c*/
	c = *a + *b;

    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;
	int fooValue;

    /*Print the values of x, y and z*/
	printf("The values of x, y, and z are: %d, %d, and %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
	fooValue = foo(&x, &y, z);

    /*Print the value returned by foo*/
	printf("The value returned from the foo function is: %d\n", fooValue);

    /*Print the values of x, y and z again*/
	printf("The values of x, y, and z are: %d, %d, and %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
	/* The value returned by foo is different than the value of z. This is 
 	 * because the addresses of x and y are passed into foo, while only a 
 	 * copy of z is passed into foo. The pointers to x and y are 
 	 * dereferenced inside of foo and then the values these pointers are 
 	 * pointing to (at x and y) are changed. When these are added together 
 	 * and stored in c, only a copy of z is being overwritten; the original
 	 * value stored at z is unchanged. Since the original value of z is 
 	 * unchanged it remains different than the value returned from foo.*/
    return 0;
}
    
    
