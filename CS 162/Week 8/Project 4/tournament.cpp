/**************************************
 * Program Name: tournament.cpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: tournament.cpp is the class implementation file for the
 * 				Tournament class. It includes all the functions necessary 
 * 				to run a fighting simulation among fantasy-type characters. 
 *************************************/

#include <iostream>
#include "tournament.hpp"
#include "diceRoll.hpp"

using std::cin;
using std::cout;
using std::endl;		

/*******************************************
 * Description: This is the default constructor for the Tournament class.
 ******************************************/
	
Tournament::Tournament()
{
	teamAWins = 0;
	teamBWins = 0;
	battleNumber = 1;
	// Boolean value used to track whether to quit tournament
	playOn = true;
	// Boolean value used to track if teams still have fighters
	bothAlive = true;
}

/*******************************************
 * Description: playTournament is a function that controls the overall 
 * 				flow of a tournament by calling the other member functions.
 ******************************************/

void Tournament::playTournament()
{
	playAgain();

	// Loop game if user hasn't chosen to quit
	while (playOn)
	{
		chooseCharacters();

		// Fight a tournament until one team is out of characters
		while (bothAlive)
		{
			fightTourney();
		}
	
		displayResults();
		
		deleteCharacters();	
	
		playAgain();
	}
}

/*******************************************
 * Description: chooseCharacters is a function that displays a menu of
 * 				characters to a user and allows them to pick fighters 
 * 				for each team.
 ******************************************/

void Tournament::chooseCharacters()
{
	// Get Team A size
	cout << "How many fighters are on Team A? ";
	do 
	{
		getline(cin, userEntry);
		teamASize = getValidInt(userEntry);
		if (teamASize <= 0)
		{
			cout << "Please enter a positive number: ";
		}
	} while (teamASize <= 0);
	// Get Team B size
	cout << "How many fighters are on Team B? ";
	do
	{
		getline(cin, userEntry);
		teamBSize = getValidInt(userEntry);
		if (teamBSize <= 0)
		{
			cout << "Please enter a positive number: ";
		}
	} while (teamBSize <= 0);

	//Create a vector to hold menu items
	menuItems.clear();
	menuItems.push_back("Vampire");
	menuItems.push_back("Barbarian");
	menuItems.push_back("Blue Men");
	menuItems.push_back("Medusa");
	menuItems.push_back("Harry Potter");
	
	// Choose and name a character for each Team A member
	for (int i = 0; i < teamASize; i++)
	{
		Menu startMenu("-- Choose a Fighter for Team A --", menuItems);
		startMenu.displayMenu();
		menuChoice = startMenu.getChoice();

		// Depending on player choice, dynamically allocate a new fighter
		if (menuChoice == 1)
		{
			playerChoice = new Vampire();
		}
		else if (menuChoice == 2)
		{
			playerChoice = new Barbarian();
		}
		else if (menuChoice == 3)
		{
			playerChoice = new BlueMen();
		}
		else if (menuChoice == 4)
		{
			playerChoice = new Medusa();
		}
		else if (menuChoice == 5)
		{
			playerChoice = new HarryPotter();
		}
		
		// Get and set a new name for the fighter
		cout << "Enter a name for " << playerChoice->getName() << ": ";
		getline(cin, userEntry);
		playerChoice->setProperName(userEntry);

		// Add fighter to team A linked list
		teamA.addTail(playerChoice);
	}
	// Choose and name characters for Team B
	for (int j = 0; j < teamBSize; j++)
	{
		Menu startMenu("-- Choose a Fighter for Team B --", menuItems);
		startMenu.displayMenu();
		menuChoice = startMenu.getChoice();

		// Depending on player choice, dynamically allocate a new fighter
		if (menuChoice == 1)
		{
			playerChoice = new Vampire();
		}
		else if (menuChoice == 2)
		{
			playerChoice = new Barbarian();
		}
		else if (menuChoice == 3)
		{
			playerChoice = new BlueMen();
		}
		else if (menuChoice == 4)
		{
			playerChoice = new Medusa();
		}
		else if (menuChoice == 5)
		{
			playerChoice = new HarryPotter();
		}
		
		// Get and set unique name for fighter
		cout << "Enter a name for " << playerChoice->getName() << ": ";
		getline(cin, userEntry);
		playerChoice->setProperName(userEntry);

		// Add fighter to team B linked list
		teamB.addTail(playerChoice);
	}
}

/*******************************************
 * Description: fightTourney is a function that executes a complete 
 * 				fighting tournament. It pits the first character in each
 * 				team against each other progressively, moving losers into 
 * 				a separate queue, until one team has no more fighters
 * 				remaining. 
 ******************************************/

void Tournament::fightTourney()
{
	cout << endl;
	// Execute loop to do battle as long as each team has living members
	while (!(teamA.getHead() == NULL) && !(teamB.getHead() == NULL))
	{
		Game battle;

		// Have head of each team to battle
		battle.playGame(teamA.getHeadVal(), teamB.getHeadVal());
		
		// If Team B wins battle
		if (teamA.getHeadVal()->isDead())
		{
			// Display battle result
			cout << "Round " << battleNumber << ": Team A ";
			cout << teamA.getHeadVal()->getProperName();
			cout << " vs. Team B " << teamB.getHeadVal()->getProperName();
			cout << ", " << teamB.getHeadVal()->getProperName();
			cout << " won!" << endl;
			// Add loser to loser list, remove from team
			loserPile.addTail(teamA.getHeadVal());
			teamA.deleteHead();
			// Winning fighter has recovery
			recovery(teamB.getHeadVal());
			// Move winning fighter to back of team
			teamB.addTail(teamB.getHeadVal());
			teamB.deleteHead();
			// Incement team wins and battle counter
			teamBWins++;
			battleNumber++;
		}
		// If Team A wins battle
		else if (teamB.getHeadVal()->isDead())
		{
			// Display battle result
			cout << "Round " << battleNumber << ": Team A ";
			cout << teamA.getHeadVal()->getProperName();
			cout << " vs. Team B " << teamB.getHeadVal()->getProperName();
			cout << ", " << teamA.getHeadVal()->getProperName();
			cout << " won!" << endl;
			// Add loser to loser list, remove from team
			loserPile.addTail(teamB.getHeadVal());
			teamB.deleteHead();
			// Winning fighter recovers
			recovery(teamA.getHeadVal());
			// Move winning fighter to back of team
			teamA.addTail(teamA.getHeadVal());
			teamA.deleteHead();
			// Increment team wins and battle counter
			teamAWins++;
			battleNumber++;
		}
	}
	// Set flag to false if one team is out of fighters
	bothAlive = false;
}

/******************************************
 * Description: The recovery function allows a winning fighter to 
 * 				recover part or all of their strength depending on 
 * 				random determination.
 *****************************************/

void Tournament::recovery(Character* fighter)
{
	int recoveryAmount;
	int strengthDifference;

	// Determine number of possible strength fighter can recover
	strengthDifference = (fighter->getMaxHP() - fighter->getHP());
	
	// Make sure fighter wasn't undamaged to start with
	if (strengthDifference > 0)
	{
		// Determine a random amount of strength to recover, from
		// one up to max strength
		recoveryAmount = diceRoll(1, strengthDifference);
		// Set new strength
		fighter->setHP(fighter->getHP() + recoveryAmount);
	}
}

/******************************************
 * Description: displayResults prints out the results of a tournament
 * 				and also asks the user if they want to see the loser pile.
 *****************************************/

void Tournament::displayResults()
{
	// Display score
	cout << endl << "-- Final Score --" << endl;
	cout << "Team A: " << teamAWins << endl;
	cout << "Team B: " << teamBWins << endl;
	
	// Display which team won
	if (teamAWins > teamBWins)
	{
		cout << endl << "Team A is the winner!" << endl;
	}
	else if (teamAWins < teamBWins)
	{
		cout << endl << "Team B is the winner!" << endl;
	}
	else
	{
		cout << endl << "It's a tie!" << endl;
	}
	
	// Create and display menu to show loser pile
	menuItems.clear();
	menuItems.push_back("Display losers group");
	menuItems.push_back("Continue");
	Menu loserMenu("-- Display Losers? --", menuItems);
	loserMenu.displayMenu();
	menuChoice = loserMenu.getChoice();

	// Print loser pile if user chooses
	if (menuChoice == 1)
	{
		loserPile.printReverse();
	}
}

/*******************************************
 * Description: The deleteCharacters function is just used to free
 * 				any dynamically allocated memory after a tournament.
 ******************************************/

void Tournament::deleteCharacters()
{
	// For team A, delete any characters and then any nodes
	while (teamA.getHead() != NULL)
	{
		delete teamA.getHeadVal();
		teamA.deleteHead();	
	}
	// For team B, delete any characters and nodes
	while (teamB.getHead() != NULL)
	{
		delete teamB.getHeadVal();
		teamB.deleteHead();
	}
	// Delete any characters and nodes from loser pile
	while (loserPile.getHead() != NULL)
	{
		delete loserPile.getHeadVal();
		loserPile.deleteHead();
	}
}

/*******************************************
 * Description: playAgain is used to display a menu to determine whether 
 * 				a user wishes to start a tournament or quit the game.
 ******************************************/

void Tournament::playAgain()
{
	// Reset counters and flags
	battleNumber = 1;
	teamAWins = 0;
	teamBWins = 0;
	bothAlive = true;

	//Create menu, display and get user choice
	menuItems.clear();
	menuItems.push_back("Play tournament");
	menuItems.push_back("Exit");
	Menu endMenu("-- Mega Super Battle Touranment --", menuItems);
	endMenu.displayMenu();
	menuChoice = endMenu.getChoice();

	//Set flag if user wants to quit
	if (menuChoice == 2)
	{
		playOn = false;
	}
}

// Destructor
Tournament::~Tournament(){}
