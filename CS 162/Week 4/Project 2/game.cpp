/**************************************
 * Program Name: game.cpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: game.cpp is the class implementation file for the
 * 				Game class.	It contains functions to play a game, 
 * 				to simulate one day, and to print messages. 
 *************************************/

#include <iostream>
#include "game.hpp"
using std::cout;
using std::endl;
using std::cin;

/***********************************
 * Description: This is the constructor for a game object. It 
 * 				initializes a game with a budget of $100000.
 **********************************/

Game::Game()
{
	budget = 100000;
	dailyProfit = 0;
	dayCounter = 0;
}

/***********************************
 * Description: The playGame function starts a new game of the Zoo
 * 				Simulator. It prompts the user for initial animal
 * 				purchases and then continues executing game 'days'
 * 				until the user chooses to quit or runs out of money.
 **********************************/

void Game::playGame()
{
	cout << "Welcome to the Zoo Simulator!" << endl << endl;
	cout << "Your new zoo is starting with a budget of $100000" << endl;
	
	// Initial user tiger purchase
	do
	{
		cout << "Would you like to buy one or two tigers for";
		cout << " $10000 each?: ";
		getline(cin, userEntry);
	 	userChoice = getValidInt(userEntry);
	} while (!(userChoice == 1) && !(userChoice == 2));
	
	// Add tigers to zoo, subtract cost
	if (userChoice == 1)
	{
		playerZoo.addTiger(1);
		budget -= 10000;
	}
	else
	{
		playerZoo.addTiger(1);
		playerZoo.addTiger(1);
		budget -= 20000;
	}
	
	// Initial user penguin purchase
	do
	{
		cout << "Would you like to buy one or two penguins for";
		cout << " $1000 each?: ";
		getline(cin, userEntry);
	 	userChoice = getValidInt(userEntry);
	} while (!(userChoice == 1) && !(userChoice == 2));
	
	// Add penguins to zoo, subtract cost
	if (userChoice == 1)
	{
		playerZoo.addPenguin(1);
		budget -= 1000;
	}
	else
	{
		playerZoo.addPenguin(1);
		playerZoo.addPenguin(1);
		budget -= 2000;
	}		

	// Initial user turtle purchase
	do
	{
		cout << "Would you like to buy one or two turtles for";
		cout << " $100 each?: ";
		getline(cin, userEntry);
	 	userChoice = getValidInt(userEntry);
	} while (!(userChoice == 1) && !(userChoice == 2));
	
	// Add turtles to zoo, subtract cost
	if (userChoice == 1)
	{
		playerZoo.addTurtle(1);
		budget -= 100;
	}
	else
	{
		playerZoo.addTurtle(1);
		playerZoo.addTurtle(1);
		budget -= 200;
	}
	
	// Execute game days until user chooses to quit or has no money
	do
	{
		playDay();
		menuItems.clear();
		menuItems.push_back("Keep Playing");
		menuItems.push_back("Quit Game");
		Menu endMenu("--End of Day--", menuItems);
		endMenu.displayMenu();
		menuChoice = endMenu.getChoice();
	} while (menuChoice != 2 && budget > 0); 
		
	// Out of money message
	if (budget <= 0)
	{
		cout << endl << "You're out of money! Thanks for playing!";
		cout << endl;
	}
}

/*************************************
 * Description: playDay is a function that executes all of the 
 * 				daily events that happen in the zoo. This includes
 * 				adding profit, subtracting costs, random events, 
 * 				and animal purchases.
 ************************************/

void Game::playDay()
{
	// Reset profit and increment day counter
	dailyProfit = 0;
	dayCounter++;
	cout << endl << "--Day " << dayCounter << "--" << endl << endl;
	
	// Increase animal ages by one day
	playerZoo.ageAnimals();

	// Calculate and subtract feeding expenses
	dailyFeedCost = playerZoo.getFeedingCost();
	budget -= dailyFeedCost;

	// Execute a random event
	cout << "Event: ";
	playerZoo.randomEvent();

	// Calculate profit made
	dailyProfit = playerZoo.getBonusProfit() + playerZoo.getDailyProfit();
	budget += dailyProfit;

	// Create a menu to see if user would like to purchase new animal
	menuItems.clear();
	menuItems.push_back("Purchase Adult Animal");
	menuItems.push_back("Do Not Purchase Animal");
	Menu purchaseMenu("Would You Like To Buy A New Animal?", menuItems);
	purchaseMenu.displayMenu();
	menuChoice = purchaseMenu.getChoice();
	if (menuChoice == 1)
	{
		// Another menu to select an animal for purchase
		menuItems.clear();
		menuItems.push_back("Tiger ($10000)");
		menuItems.push_back("Penguin ($1000)");
		menuItems.push_back("Turtle ($100)");
		Menu buyAnimalMenu("What Animal Would You Like?", menuItems);
		buyAnimalMenu.displayMenu();
		menuChoice = buyAnimalMenu.getChoice();
	 	
		// Add an animal and subtract cost depending on choice
		if (menuChoice == 1)
		{
			playerZoo.addTiger(3);
			budget -= 10000;
			cout << "Tiger Purchased!" << endl;
		}
		else if (menuChoice == 2)
		{
			playerZoo.addPenguin(3);
			budget -= 1000;
			cout << "Penguin Purchased!" << endl;
		}
		else if (menuChoice == 3)
		{
			playerZoo.addTurtle(3);
			budget -= 100;
			cout << "Turtle Purchased!" << endl;
		}
	}

	// Print the daily summary
	printSummary();
}

/***********************************
 * Description: printSummary is a function that prints out number of 
 * 				animals in the zoo as well as costs and revenue for the
 * 				day.
 **********************************/	

void Game::printSummary()
{
	cout << endl << "--Daily Summary--" << endl << endl;
	cout << "Number of Tigers: " << playerZoo.getNumberTigers() << endl;
	cout << "Number of Penguins: " << playerZoo.getNumberPenguins() << endl;
	cout << "Number of Turtles: " << playerZoo.getNumberTurtles() << endl;
 	cout << endl <<"Daily Food Cost: $" << dailyFeedCost << endl;
	cout << "Daily Profit: $" << dailyProfit << endl;
	cout << "Current Budget: $" << budget << endl;
}
	
