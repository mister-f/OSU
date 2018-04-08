/**************************************
 * Program Name: ratatosk.cpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: ratatosk simply creates a Game object and 
 * 				executes the playGame member function. You then get to 
 * 				play a fun Norse-squirrel themeed game.
 *************************************/

#include <ctime>
#include <cstdlib>
#include "game.hpp"

int main()
{
	Game newGame;
	unsigned seed;

	// Seed random number generator
	seed = time(0);
	srand(seed);

	// Execute playGame function on the created Game object
	newGame.playGame();

	return 0;
}
