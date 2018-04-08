/**************************************
 * Program Name: diceRoll.cpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: diceRoll.cpp is an implementation file for a helper 
 * 				function that rolls dice. It takes in two ints, a number 
 * 				of dice, and the number of sides on those dice, 
 * 				and returns a roll value. NOTE: rand() function must be 
 * 				seeded in a main function associated with its use.
 *************************************/

#include <cstdlib>

int diceRoll(int numberDice, int sides)
{
	int diceSum = 0;

	// Do a random die roll for the given number of dice
	// and add all the values
	for(int i = 0; i < numberDice; i++)
	{ 
		diceSum += ((rand() % sides) + 1);
	}

	return diceSum;
}
