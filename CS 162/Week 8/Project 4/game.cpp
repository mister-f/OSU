/**************************************
 * Program Name: game.cpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: game.cpp is the class implementation file for the
 * 				Game class. It includes all the functions necessary to 
 * 				run a fighting simulation among fantasy-type characters. 
 *************************************/

#include "game.hpp"

/*******************************************
 * Description: This is the default constructor for the Game class.
 ******************************************/
	
Game::Game()
{
	// Boolean value used to track if a character dies
	bothAlive = true;
}

/*******************************************
 * Description: playGame is a function that controls the overall flow of 
 * 				a game by calling the fightRound function if both 
 * 				fighters are still alive.
 ******************************************/

void Game::playGame(Character* fighterA, Character* fighterB)
{
	// Fight a new round as long as both characters are alive
	while (bothAlive)
	{
		fightRound(fighterA, fighterB);
	}
}

/*******************************************
 * Description: fightRound is a function that executes a single round of 
 * 				fighting. It randomly determines a character to attack 
 * 				first, and then calls the faceoff function to have the 
 * 				characters battle.
 ******************************************/

void Game::fightRound(Character* fighterA, Character* fighterB)
{
	int firstAttack;

	// Randomly determine the first attacker
	firstAttack = ((rand() % 2) + 1);

	// Attacker 1 goes first
	if (firstAttack == 1)
	{
		// First half of fight
		faceoff(fighterA, fighterB);
		// Fight second half of fight if character hasn't died
		if (bothAlive)
		{
			faceoff(fighterB, fighterA);
		}
	}
	// Attacker 2 goes first
	else 
	{
		// Fight first half of fight
		faceoff(fighterB, fighterA);
		// Fight second half of fight if character hasn't died
		if (bothAlive)
		{
			faceoff(fighterA, fighterB);
		}
	}	
}

/*******************************************
 * Description: faceoff is a function that simulates half a round of 
 * 				battle. It takes in two characters and has the first
 * 				attack the second.
 ******************************************/

void Game::faceoff(Character* first, Character* second)
{
	int attackAmount;
	
	// Get first player attack amount
	attackAmount = first->attack();
	// Get second player defense, check if they were killed
	if (!(second->defend(attackAmount)))
	{
		// Set flag to false if a character died
		bothAlive = false;
	}
}
