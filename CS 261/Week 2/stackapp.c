/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	assert(s != 0);

	/*Create variables for current character and allocate array for stack*/
	char temp;
	DynArr* balance;
	balance = newDynArr(8);

	/*Post test loop gets next character in string and pushes/pops brackets*/
	do
	{
		temp = nextChar(s);
		if (temp == '(')
		{
			pushDynArr(balance, ')');
		}
		else if (temp == '{')
		{
			pushDynArr(balance, '}');
		}
		else if (temp == '[')
		{
			pushDynArr(balance, ']');
		}
		/*If closing bracket is next and stack is empty, return unbalanced*/
		else if ((temp == ')' || temp == '}' || temp == ']') 
				&& isEmptyDynArr(balance))
		{
			deleteDynArr(balance);
			return 0;
		}
		/*If closing bracket is next and doesn't match top of stack, return unbalanced*/
		else if ((temp == ')' || temp == '}' || temp == ']')
			&& topDynArr(balance) != temp)
		{
			deleteDynArr(balance);
			return 0;
		}
		/*If closing bracket is next and matches top of stack, pop stack*/
		else if ((temp == ')' || temp == '}' || temp == ']')
				&& topDynArr(balance) == temp)
		{
			popDynArr(balance);
		}
	} while (temp != '\0');

	/*If stack is empty return balanced, else return unbalanced*/
	if (isEmptyDynArr(balance))
	{
		deleteDynArr(balance);
		return 1;
	}
	else
	{
		deleteDynArr(balance);
		return 0;
	}
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

