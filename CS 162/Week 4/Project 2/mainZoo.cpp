/**************************************
 * Program Name: mainZoo.cpp
 * Name: Andrew Funk
 * Date: 10-19-17
 * Description: mainZoo simply creates a game object and 
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

	playerGame.playGame();

	return 0;
}
