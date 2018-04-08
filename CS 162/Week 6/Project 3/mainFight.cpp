/**************************************
 * Program Name: mainFight.cpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: mainFight simply creates a game object and 
 * 				executes the playGame member function. The random
 * 				number generator used in generating die rolls is also 
 * 				seeded in the main function.
 *************************************/

#include <ctime>
#include <cstdlib>
#include "game.hpp"

int main()
{
	Game playerGame;
	unsigned seed;

	// Seed random number generator
	seed = time(0);
	srand(seed);

	// Execute playGame function on the created Game object
	playerGame.playGame();

	return 0;
}
