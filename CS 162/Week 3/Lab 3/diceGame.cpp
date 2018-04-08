/**************************************
 * Program Name: diceGame.cpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: diceGame.cpp is the class implementation file for the
 * 				DiceGame class. It has functions to play a war style dice
 * 				game, for printing a game round, for completing a single
 * 				game round, and a default constructor.
 *************************************/

#include <iostream>
#include "diceGame.hpp"
using std::cout;
using std::cin;
using std::endl;

/******************************
 * Description: This is the default constructor for a diceGame object.
 * 				It initializes the object with the score set to 0, a 
 * 				default die size of 6, unloaded die as the default, and
 * 				a 10 round game.
 *****************************/

DiceGame::DiceGame()
{
	player1Score = 0;
	player2Score = 0;
	player1Size = 6;
	player2Size = 6;
	player1DieType = UNLOADED;
	player2DieType = UNLOADED;
	roundNumber = 10;
}

/***********************************
 * Description: playGame is a member function that takes no input. 
 * 				The function runs an entire 'war' dice game, using 
 * 				the menu class and other propmts to the user to get the
 * 				starting requirements for the game. It then dynamically 
 * 				allocates two Die or LoadedDie objects based on this input
 * 				and runs an entire game. At the end it prints out a game
 * 				summary.
 ***********************************/

void DiceGame::playGame()
{
	// Main menu creation and display
	menuItems.push_back("Play Game");
	menuItems.push_back("Quit Game");

	Menu mainMenu("Main Menu", menuItems);
	mainMenu.displayMenu();
	menuChoice = mainMenu.getChoice();

	// Uer chooses to run game
	if (menuChoice == 1)
	{
		// Get number of rounds from user
		do
		{
			cout << "How many rounds would you like to play? ";
			getline(cin, userEntry);
			roundNumber = getValidInt(userEntry);
		} while (roundNumber < 1);

		// Create a menu to choose the die type
		menuItems.clear();
		menuItems.push_back("Loaded");
		menuItems.push_back("Unloaded");
		
		// Player one die type choice
		Menu dieType1("What type of die for player 1?", menuItems);
		dieType1.displayMenu();
		menuChoice = dieType1.getChoice();
		if (menuChoice == 1)
		{
			player1DieType = LOADED;
		}

		// Player two die type choice
		Menu dieType2("What type of die for player 2?", menuItems);
		dieType2.displayMenu();
		menuChoice = dieType2.getChoice();
		if (menuChoice == 1)
		{
			player2DieType = LOADED;
		}

		// Get number of sides for player one
		do
		{
			cout << endl << "How many sided die for player 1? (2-20) ";
			getline(cin, userEntry);
			player1Size = getValidInt(userEntry);
		} while (!(player1Size >= MIN_SIDES && player1Size <= MAX_SIDES));

		// Get number of sides for player two
		do
		{
			cout << "How many sided die for player 2? (2-20) ";
			getline(cin, userEntry);
			player2Size = getValidInt(userEntry);
		} while (!(player2Size >= MIN_SIDES && player2Size <= MAX_SIDES));

		// Create loaded or unloaded Die object for player one
		if (player1DieType == LOADED)
		{
			diePtr1 = new LoadedDie(player1Size);
		}
		else if (player1DieType == UNLOADED)
		{
			diePtr1 = new Die(player1Size);
		}

		// Create loaded or unloaded Die object for player two
		if (player2DieType == LOADED)
		{
			diePtr2 = new LoadedDie(player2Size);
		}
		else if (player2DieType == UNLOADED)
		{
			diePtr2 = new Die(player2Size);
		}

		// Loop playing a round for the selected choice
		for (int i = 0; i < roundNumber; i++)
		{
			playRound(diePtr1, diePtr2);
		}
		
		// Display final score
		cout << "The final score is:" << endl;
		cout << "Player 1 - " << player1Score << endl;
		cout << "Player 2 - " << player2Score << endl << endl;

		// Display final winner
		if (player1Score > player2Score)
		{
			cout << "Player 1 wins!" << endl << endl;
		}
		else if (player2Score > player1Score)
		{
			cout << "Player 2 wins!" << endl << endl;
		}
		else
		{
			cout << "It's a draw!" << endl << endl;
		}
		
		// Delete dynamically allocated memory
		delete diePtr1;
		delete diePtr2;
	}
}

/*********************************
 * Description: printRound is a member function that takes in two 
 * 				player scores as well as a round result and prints
 * 				a detailed summary of the round.
 *********************************/

void DiceGame::printRound(int score1In, int score2In, RoundResult resultIn)
{
	// Print player one details and score
	cout << "Player 1 (" << player1Size << "-sided ";
	if (player1DieType == LOADED)
	{
		cout << "loaded) - ";
	}
	else
	{
		cout << "unloaded) - ";
	}
	cout << score1In << endl;
		
	// Print player two details and score
	cout << "Player 2 (" << player2Size << "-sided ";
	if (player2DieType == LOADED)
	{
		cout << "loaded) - ";
	}
	else
	{
		cout << "unloaded) - ";
	}
	cout << score2In << endl;

	// Use round result variable to display correct round winner
	if (resultIn == PLAYER1)
	{
		cout << "Player 1 wins a point!" << endl << endl;
	}
	else if (resultIn == PLAYER2)
	{
		cout << "Player 2 wins a point!" << endl << endl;
	}
	else if (resultIn == DRAW)
	{
		cout << "It's a draw!" << endl << endl;
	}
}

/**********************************
 * Description: playRound is a member function that executes a single
 * 				war game round. It takes in two pointers to Die objects.
 * 				The function rolls each die, increments the score of the 
 * 				winner, and updates roundStatus depending on the round 
 * 				result. It then calls the printRound function to print
 * 				the detailed round results.
 **********************************/

void DiceGame::playRound(Die* die1, Die* die2)
{
	// Call Die member functions to roll dice
	roll1 = die1->rollDie();
	roll2 = die2->rollDie();

	// Determine winner and increment score
	if (roll1 > roll2)
	{
		player1Score++;
		roundStatus = PLAYER1;
	}
	else if (roll2 > roll1)
	{
		player2Score++;
		roundStatus = PLAYER2;
	}
	else
	{
		roundStatus = DRAW;
	}

	// Call printRound function to print detailed summary
	printRound(roll1, roll2, roundStatus);
}

