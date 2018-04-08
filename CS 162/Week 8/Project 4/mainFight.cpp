/**************************************
 * Program Name: mainFight.cpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: mainFight simply creates a tournament object and 
 * 				executes the playTournament member function. The random
 * 				number generator used in generating die rolls is also 
 * 				seeded in the main function.
 *************************************/

#include <ctime>
#include <cstdlib>
#include "tournament.hpp"

int main()
{
	Tournament playerTourney;
	unsigned seed;

	// Seed random number generator
	seed = time(0);
	srand(seed);

	// Execute playTournament function on the created Tournament object
	playerTourney.playTournament();

	return 0;
}
