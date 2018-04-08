/**************************************
 * Program Name: lab9.cpp
 * Name: Andrew Funk
 * Date: 11-25-17
 * Description: lab9 calls two functions that make use of the STL. 
 * 				It calls plaindrome and buffering functions. The random
 * 				number generator used in getting numbers for the buffer
 * 				sim is also seeded in the main function.
 *************************************/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "menu.hpp"
#include "getValidInput.hpp"
#include "stlFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	unsigned seed;
	string userEntry;
	vector<string> menuItems;
	int menuChoice;
	int numberRounds;
	int addPercentage;
	int removePercentage;

	// Seed random number generator
	seed = time(0);
	srand(seed);

	// Create the main menu
	menuItems.push_back("Test the Buffer Simulation;");
	menuItems.push_back("Run the Palindrome-A-Nator;");
	menuItems.push_back("Exit;");
	Menu mainMenu("-- STL Functions --", menuItems);

	// Repeat the menu until user exits
	do
	{
		mainMenu.displayMenu();
		menuChoice = mainMenu.getChoice();

		// Run the buffer sim
		if (menuChoice == 1)
		{
			// Get rounds and validate
			cout << endl << "Please enter a number of rounds to simulate: ";
			do
			{
				getline(cin, userEntry);
				numberRounds = getValidInt(userEntry);
				if (numberRounds <= 0)
				{
					cout << "Please enter a positive number: ";
				}
			} while (numberRounds <= 0);
			
			// Get add percentage and validate
			cout << "Please enter the percentage to add a number: ";
			do
			{
				getline(cin, userEntry);
				addPercentage = getValidInt(userEntry);
				if (addPercentage < 1 || addPercentage > 100)
				{
					cout << "Please enter a percentage from 1 to 100: ";
				}
			} while (addPercentage < 1 || addPercentage > 100);
			
			// Get remove percentage and validate
			cout << "Please enter the percentage to remove a number: ";
			do
			{
				getline(cin, userEntry);
				removePercentage = getValidInt(userEntry);
				if (removePercentage < 1 || removePercentage > 100)
				{
					cout << "Please enter a percentage from 1 to 100: ";
				}
			} while (removePercentage < 1 || removePercentage > 100);
			
			// Call bufferQueue function to run buffer sim
			bufferQueue(numberRounds, addPercentage, removePercentage);
		}

		// Run the palindrome function
		else if (menuChoice == 2)
		{
			// Get a string from user
			cout << endl;
			cout << "Please enter a string to turn into a palindrome: ";
			cout << endl;
			getline(cin, userEntry);
			
			// Call palindrome function with the user's string
			palindrome(userEntry);
		}
	} while (menuChoice != 3);	

	return 0;
}
