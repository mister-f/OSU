/*
* CS 261 Data Structures
* Assignment 5
* Name: Andrew Funk
* Date: 03-11-18
*/

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
//Fix me: Do the necessary change to make the implementation //case-insensitive  
   while (1) 
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')  
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            // .............
			/* Lowercase conversion */
			if (c >= 'A' && c <= 'Z')
			{
				c = tolower(c);
			}
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    
    clock_t timer = clock();
    
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.
	FILE *filePointer;
	char * word;
	int instance;
	int i;
	HashLink *current;
	
	/* Open input file */
	filePointer = fopen(fileName, "r");
	if (filePointer == NULL) {
		printf("Error opening file\n");
		exit(EXIT_FAILURE);
	}

	word = nextWord(filePointer);

	/* Add words until there is no next word in file */
	while (word != NULL)
	{
		/* Increment word count if qord exists in hash table */
		if (hashMapContainsKey(map, word))
		{
			instance = *(hashMapGet(map, word));
			instance++;
			hashMapPut(map, word, instance);
		}
		/* Add word to table with a count of one if not found in table */
		else
		{
			hashMapPut(map, word, 1);
		}

		/* Free word and get next word from file */
		free(word);
		word = nextWord(filePointer);
	}

	fclose(filePointer);

	/* Print words and count */
	for (i = 0; i < map->capacity; i++)
	{
		current = map->table[i];
		while (current != NULL)
		{
			printf("%s: %d\n", current->key, current->value);
			current = current->next;
		}
	}

    // --- Concordance code ends here ---
    
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}