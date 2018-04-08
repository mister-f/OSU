/* CS261- Assignment 1 - Q. 0*/
/* Name: Andrew Funk
 * Date: 01-15-18
 * Solution description: This program declares a variable x, and then 
						 prints values and memory addresses of both x
						 and a pointer to x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value pointed to by iptr*/
	printf("The value pointed to by iptr is: %d\n", *iptr);

    /*Print the address pointed to by iptr*/
	printf("The memory address pointed to by iptr is: %p\n", iptr);
     
    /*Print the address of iptr itself*/
	printf("The memory address of iptr is: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 10;

    /*print the address of x*/
	printf("The address of variable x is: %p\n", &x);

    /*Call fooA() with the address of x*/
	fooA(&x);

	/*print the value of x*/
	printf("The value stored in variable x is: %d\n", x);

    return 0;
}
