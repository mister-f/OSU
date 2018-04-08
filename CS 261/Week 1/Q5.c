/* CS261- Assignment 1 - Q.5*/
/* Name: Andrew Funk
 * Date: 01-18-18
 * Solution description: This program takes a word as input from a 
						 user and then passes it to a sticky function
						 which converts the word to alternating upper
						 and lower case letters, starting with upper
						 case. It then prints the new sticky-fied word.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int position = 0;

	while (word[position] != '\0')
	{
		if (position % 2 == 0)
		{
			if (word[position] > 'Z')
			{
				word[position] = toUpperCase(word[position]);
			}
		}
		else
		{
			if (word[position] <= 'Z')
			{
				word[position] = toLowerCase(word[position]);
			}
		}
		position++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char userEntry[50];
	
	printf("Please enter a word: ");
	scanf("%s", userEntry);

    /*Call sticky*/
	sticky(userEntry);

    /*Print the new word*/
	printf("Your sticky word is: %s\n", userEntry);

    return 0;
}
