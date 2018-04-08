/*
* CS 261 Data Structures
* Assignment 5
* Name: Andrew Funk
* Date: 03-11-18
*/

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hashFunction1(const char* key);
int hashFunction2(const char* key);

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
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
	char *word;

	word = nextWord(file);

	/* Add words until there is no next word in file */
	while (word != NULL)
	{
		/* Add words as key with 0 as value */
		{
			hashMapPut(map, word, 0);
		}

		/* Free word and get next word from file */
		free(word);
		word = nextWord(file);
	}
}

/**********
* Computes minimum of three values
* @param x First value
* @param y Second value
* @param z Third value
* @return minimum of the three parameters
**********/
int minimum(int x, int y, int z)
{
	int min = x;

	if (y < min)
	{
		min = y;
	}
	if (z < min)
	{
		min = z;
	}

	return min;
}


/**********
 * Computes the edit distance between two words, alghorithic steps sourced from:
 * https://people.cs.pitt.edu/~kirk/cs1501/Pruhs/Spring2006/assignments/editdistance/Levenshtein%20Distance.htm
 * @param word1 First word to compare
 * @param word2 Second word to compare
 * @param m Word 2 length
 * @param n Word 1 length
 * @return edit distance between words as an int
 **********/

int levenshtein(char* word1, char* word2)
{
	int i;
	int j;
	int cost;
	int distance;
	char char1;
	char char2;

	/* Set n to be the length of word1. Set m to be the length of word2.
	 * If n = 0, return m and exit. If m = 0, return n and exit.
	 * Construct a matrix containing 0..m rows and 0..n columns. */
	int n = strlen(word1);
	int m = strlen(word2);

	if (m == 0)
	{
		return n;
	}
	if (n == 0)
	{
		return m;
	}

	int **matrix = (int **)malloc((n + 1) * sizeof(int *));
	for (i = 0; i <= n; i++)
	{
		matrix[i] = (int *)malloc((m + 1) * sizeof(int));
	}

	/* Initialize the first row to 0..n. Initialize the first column to 0..m. */
	for (i = 0; i <= n; i++)
	{
		matrix[i][0] = i;
	}
	for (j = 0; j <= m; j++)
	{
		matrix[0][j] = j;
	}

	/* Examine each character of word1(i from 1 to n). */
	for (i = 1; i <= n; i++)
	{
		char1 = word1[i - 1];

		/* Examine each character of word2(j from 1 to m). */
		for (j = 1; j <= m; j++)
		{
			char2 = word2[j - 1];

			/* If word1[i] equals word2[j], the cost is 0.
			 * If word1[i] doesn't equal word2[j], the cost is 1. */
			if (char1 == char2)
			{
				cost = 0;
			}
			else
			{
				cost = 1;
			}

			/* Set cell matrix[i, j] of the matrix equal to the minimum of :
			 * a.The cell immediately above plus 1 : matrix[i - 1, j] + 1.
			 * b.The cell immediately to the left plus 1 : matrix[i, j - 1] + 1.
			 * c.The cell diagonally above and to the left plus the cost : matrix[i - 1, j - 1] + cost. */
			matrix[i][j] = minimum((matrix[i - 1][j] + 1), (matrix[i][j - 1] + 1), (matrix[i - 1][j - 1] + cost));
		}
	}
	/* After the iteration steps(3, 4, 5, 6) are complete, the distance is found in cell matrix[n, m] */
	distance = matrix[n][m];

	for (i = 0; i <= n; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return distance;
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
	int i;
	int j;
	int index;
	int stringFound;
	HashLink *closest[5];
	HashLink *current;

    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("\nEnter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
		/* Convert to lowercase */
		for (i = 0; i < strlen(inputBuffer); i++)
		{
			if (inputBuffer[i] >= 'A' && inputBuffer[i] <= 'Z')
			{
				inputBuffer[i] = tolower(inputBuffer[i]);
			}
		}

		/* Reset variables */
		stringFound = 0;
		for (i = 0; i < 5; i++)
		{
			closest[i] = NULL;
		}

		/* Compute the Levenshtein distance for all words and save as value for each key */
		for (i = 0; i < map->capacity; i++)
		{
			current = map->table[i];
			while (current != NULL)
			{
				hashMapPut(map, current->key, levenshtein(inputBuffer, current->key));
				current = current->next;
			}
		}
        
		/* Calculate index that target word is saved at*/
		index = HASH_FUNCTION(inputBuffer) % map->capacity;
		if (index < 0)
		{
			index += map->capacity;
		}

		/* Check if word is a correctly spelled word */
		current = map->table[index];
		while (current != NULL)
		{
			if (strcmp(current->key, inputBuffer) == 0)
			{
				printf("The word '%s' is spelled correctly.\n", inputBuffer);
				stringFound = 1;
			}
			current = current->next;
		}

		/* If word not correctly spelled, find closest words*/
		if (!stringFound)
		{
			/* Search through dictionary */
			for (i = 0; i < map->capacity; i++)
			{
				current = map->table[i];
				while (current != NULL)
				{
					/* Check current value against current 5 smallest saved values */
					for (j = 0; j < 5; j++)
					{
						/* Save value if spot is empty */
						if (closest[j] == NULL)
						{
							closest[j] = current;
							break;
						}
						/* If value is smaller, save new value to array */
						else if (current->value < closest[j]->value)
						{
							closest[j] = current;
							break;
						}
					}
					current = current->next;
				}
			}

			/* Print out array of five closest keys */
			for (i = 0; i < 5; i++)
			{
				printf("Did you mean '%s'?\n", closest[i]->key);
			}
		}

        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
    }
    
    hashMapDelete(map);
    return 0;
}

