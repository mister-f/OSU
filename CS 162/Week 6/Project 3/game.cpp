/**************************************
 * Program Name: game.cpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: game.cpp is the class implementation file for the
 * 				Game class. It includes all the functions necessary to 
 * 				run a fighting simulation among fantasy-type characters. 
 *************************************/

#include <iostream>
#include "game.hpp"

using std::cout;
using std::endl;		

/*******************************************
 * Description: This is the default constructor for the Game class.
 ******************************************/
	
Game::Game()
{
	playerOne = NULL;
	playerTwo = NULL;
	roundNumber = 1;
	// Boolean value used to track whether to quit game
	playOn = true;
	// Boolean value used to track if a character dies
	bothAlive = true;
}

/*******************************************
 * Description: playGame is a function that controls the overall flow of 
 * 				a game by calling the other member functions.
 ******************************************/

void Game::playGame()
{
	// Loop game if user hasn't chosen to quit
	while (playOn)
	{
		chooseCharacters();

		// Fight a new round as long as both characters are alive
		while (bothAlive)
		{
			fightRound();
		}
	
		deleteCharacters();	
	
		playAgain();
	}
}

/*******************************************
 * Description: chooseCharacters is a function that displays a menu of
 * 				characters to a user and allows them to pick fighters 
 * 				for a battle.
 ******************************************/

void Game::chooseCharacters()
{
	//Create a vector to hold menu items
	menuItems.clear();
	menuItems.push_back("Vampire");
	menuItems.push_back("Barbarian");
	menuItems.push_back("Blue Men");
	menuItems.push_back("Medusa");
	menuItems.push_back("Harry Potter");
	//Create a menu, display and get player choice
	Menu startMenu1("-- Choose Fighter 1 --", menuItems);
	startMenu1.displayMenu();
	menuChoice1 = startMenu1.getChoice();

	// Depending on player choice, dynamically allocate a new fighter
	if (menuChoice1 == 1)
	{
		playerOne = new Vampire();
	}
	else if (menuChoice1 == 2)
	{
		playerOne = new Barbarian();
	}
	else if (menuChoice1 == 3)
	{
		playerOne = new BlueMen();
	}
	else if (menuChoice1 == 4)
	{
		playerOne = new Medusa();
	}
	else if (menuChoice1 == 5)
	{
		playerOne = new HarryPotter();
	}

	// Display menu and get input for second fighter
	Menu startMenu2("-- Choose Fighter 2 --", menuItems);
	startMenu2.displayMenu();
	menuChoice2 = startMenu2.getChoice();	

	// Dynamically allocate second fighter based on user choice
	if (menuChoice2 == 1)
	{
		playerTwo = new Vampire();
	}
	else if (menuChoice2 == 2)
	{
		playerTwo = new Barbarian();
	}
	else if (menuChoice2 == 3)
	{
		playerTwo = new BlueMen();
	}
	else if (menuChoice2 == 4)
	{
		playerTwo = new Medusa();
	}
	else if (menuChoice2 == 5)
	{
		playerTwo = new HarryPotter();
	}

	// Check if two of the same character are selected
	// If characters are the same, change names to include a '1' or
	// '2' suffix
	if (menuChoice1 == menuChoice2)
	{
		string tempName;

		tempName = playerOne->getName();

		playerOne->setName(tempName + " 1");
		playerTwo->setName(tempName + " 2");
	}
}

/*******************************************
 * Description: fightRound is a function that executes a single round of 
 * 				fighting. It randomly determines a character to attack 
 * 				first, and then calls the faceoff function to have the 
 * 				characters battle.
 ******************************************/

void Game::fightRound()
{
	int firstAttack;

	// Randomly determine the first attacker
	firstAttack = ((rand() % 2) + 1);

	// Print round number
	cout << endl << "-- Round " << roundNumber << " --" << endl;
	// Attacker 1 goes first
	if (firstAttack == 1)
	{
		// First half of fight
		faceoff(playerOne, playerTwo);
		// Fight second half of fight if character hasn't died
		if (bothAlive)
		{
			faceoff(playerTwo, playerOne);
		}
	}
	// Attacker 2 goes first
	else 
	{
		// Fight first half of fight
		faceoff(playerTwo, playerOne);
		// Fight second half of fight if character hasn't died
		if (bothAlive)
		{
			faceoff(playerOne, playerTwo);
		}
	}	
	
	// Increment round number
	roundNumber++;
}

/*******************************************
 * Description: faceoff is a function that simulates half a round of 
 * 				battle. It takes in two characters and has the first
 * 				attack the second. It also prints the pre-battle
 * 				character stats.
 ******************************************/

void Game::faceoff(Character* first, Character* second)
{
	int attackAmount;
	
	// Print who is attacking and defending and defense stats
	cout << endl << "The attacker is " << first->getName();
	cout << "." << endl;
	cout << "The defender is " << second->getName();
	cout << " and has " << second->getArmor();
	cout << " armor and " << second->getHP() << " strength." << endl;
	
	// Get first player attack amount
	attackAmount = first->attack();
	// Get second player defense, check if they were killed
	if (!(second->defend(attackAmount)))
	{
		// Set flag to false if a character died
		bothAlive = false;
	}
}

/*******************************************
 * Description: The deleteCharacters function is just used to free
 * 				any dynamically allocated memory after a fight has
 * 				ended and set the player pointers to NULL.
 ******************************************/

void Game::deleteCharacters()
{
	delete playerOne;
	playerOne = NULL;
	delete playerTwo;
	playerTwo = NULL;
}

/*******************************************
 * Description: playAgain is used to display a menu to determine whether 
 * 				a user wishes to start a new battle or quit the game.
 ******************************************/

void Game::playAgain()
{
	//Reset round number and alive flag after a fight is done
	roundNumber = 1;
	bothAlive = true;

	//Create exit menu, display and get user choice
	menuItems.clear();
	menuItems.push_back("Play again");
	menuItems.push_back("Exit");
	Menu endMenu("-- Continue? --", menuItems);
	endMenu.displayMenu();
	menuChoice1 = endMenu.getChoice();

	//Set flag if user wants to quit
	if (menuChoice1 == 2)
	{
		playOn = false;
	}
}
