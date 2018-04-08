/**************************************
 * Program Name: mainDice.cpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: mainDice just contains the main function for a 'war'
 * 				style dice game. It simply creates a game object and 
 * 				executes the playGame member function. The random
 * 				number generator used in generating die rolls is also 
 * 				seeded in the main function.
 *************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "diceGame.hpp"

int main ()
{
	DiceGame game;
	unsigned seed;

	// Seed random number generator
	seed = time(0);
	srand(seed);

	game.playGame();

	return 0;
}
