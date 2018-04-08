/**************************************
 * Program Name: langtonMain.cpp
 * Name: Andrew Funk
 * Date: 10-05-17
 * Description: This program runs a simulation of Langton's Ant. The 
 * 				user can choose the starting board size, ant starting 
 * 				position, and number of iterations to run. This program 
 * 				uses objects of the Ant and Menu classes to complete the
 * 				simulation. The program can be run by compiling with the 
 * 				associated makefile and running the 'langtonAnt' file.
 *************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ant.hpp"
#include "menu.hpp"
#include "getValidInt.hpp"
using std::cout;
using std::endl;
using std::cin;

int main ()
{
	vector<string> menuList;
	string userEntry;
	int menuChoice;
	int boardRows;
	int boardColumns;
	int startXPos;
	int startYPos;
	int iterations;
	unsigned seed;
	// Constants to serve as bound for simulation
	const int MIN_ARRAY = 2;
	const int MAX_ARRAY = 80;
	const int MIN_ITERATIONS = 1;
	const int MAX_ITERATIONS = 50000;

	
	// Populate a vector with menu items
	menuList.push_back("Start Langton's Ant simulation");
	menuList.push_back("Quit");

	// Create a menu object and get a menu choice from user
	Menu mainMenu("Main Menu", menuList);
	mainMenu.displayMenu();
	menuChoice = mainMenu.getChoice();
			
	// Run simulation if user chooses
	if (menuChoice == 1)
	{
		// Outer do-while loop so simulation can be run multiple times
		do
		{
			// Get and validate number rows
			do
			{
				cout << "How many rows would you like? (2-80) ";
				getline(cin, userEntry);
				boardRows = getValidInt(userEntry);
			} while (!(boardRows >= MIN_ARRAY && boardRows <= MAX_ARRAY));
			// Get and validate number columns
			do
			{
				cout << "How many columns would you like? (2-80) ";
				getline(cin, userEntry);
				boardColumns = getValidInt(userEntry);
			} while (!(boardColumns >= MIN_ARRAY 
						&& boardColumns <= MAX_ARRAY));
			// Get and validate iterations to run
			do
			{
				cout << "How many iterations ";
				cout << "should the simulation run? (1-50000) ";
				getline(cin, userEntry);
				iterations = getValidInt(userEntry);
			} while (!(iterations >= MIN_ITERATIONS && 
						iterations <= MAX_ITERATIONS));
			// Check if user wants a random start location
			do
			{
				cout << "Would you like a random start location? (Y/N) ";
				getline(cin, userEntry);
			} while (!((userEntry == "Y") || (userEntry == "N")
						|| (userEntry == "y") || (userEntry == "n")));
			// If user wants to choose, get starting position input
			if ((userEntry == "N") || (userEntry == "n"))
			{
				// Get a starting Y position for ant and validate	
				do
				{
					cout << "What starting row for ant? ";
					cout << "(1-" << boardRows << ") "; 
					getline(cin, userEntry);
					startYPos = getValidInt(userEntry);
				} while (!(startYPos >= 1 && startYPos <= boardRows));
				// Get a starting X position for ant and validate
				do
				{
					cout << "What starting column for ant? ";
					cout << "(1-" << boardColumns << ") ";
					getline(cin, userEntry);
					startXPos = getValidInt(userEntry);
				} while (!(startXPos >= 1 && startXPos <= boardColumns));
			}
			// Random start position selected
			else
			{
				//Seed random number generator
				seed = time(0);
				srand(seed);
				
				// Set start positions within board boundaries
				startYPos = (rand() % boardRows) + 1;
				startXPos = (rand() % boardColumns) + 1;
			}
			
			// Create an Ant object based on user entries
			Ant simulation(boardColumns, boardRows, 
							startXPos - 1, startYPos - 1);

			// Display starting position
			simulation.displayBoard();

			// Loop for the entered number of iterations, moving ant
			// and printing new board layout
			for (int i = 0; i < iterations; i++)
			{
				simulation.moveAnt();
				simulation.displayBoard();
			}

			// At end of simulation clear old menu list and re-prompt user
			// as whether to run again or quit.
			menuList.clear();
			menuList.push_back("Run Langton's Ant simulation again");
			menuList.push_back("Quit");

			Menu endMenu("Simulation complete!", menuList);
			endMenu.displayMenu();
			menuChoice = endMenu.getChoice();
		} while (menuChoice == 1);
	}
	// Quit program if user chooses
	else if (menuChoice == 2)
	{
		return 0;
	}
}
