/**************************************
 * Program Name: lab5.cpp
 * Name: Andrew Funk
 * Date: 10-26-17
 * Description: lab5.cpp contains the main function to run another set
 * 				of functions the exhibit recursive behavior. It has a menu 
 * 				system to display a choice of which function to run to the
 * 				user. 
 *************************************/

#include <iostream>
#include "menu.hpp"
#include "getValidInput.hpp"
#include "recursion.hpp"
using std::cout;
using std::endl;
using std::cin;

int main ()
{
	string menuName;
	vector<string> menuItems;
	string userEntry;
	int menuChoice;
	int arraySize;
	int intEntry;
	int* arrayPtr;

	// Create list of menu items
	menuItems.push_back("Print a string in reverse.");
	menuItems.push_back("Find the sum of integers.");
	menuItems.push_back("Find the triangular number.");
	menuItems.push_back("Quit.");
	Menu mainMenu("--Recursive Functions--", menuItems);

	// Repeat menu display until user quits
	do
	{
		// Show menu and get user choice
		mainMenu.displayMenu();
		menuChoice = mainMenu.getChoice();

		// Run the string reverse function
		if (menuChoice == 1)
		{
			cout << endl << "Please enter something to reverse:" << endl;
			getline(cin, userEntry);
			cout << endl;
			reverseString(userEntry, userEntry.length());
			cout << endl;
		}
		// Run the integer array summation function
		else if (menuChoice == 2)
		{
			// Get size of array
			cout << endl << "How many integers would you like to sum? ";
			do
			{
				getline(cin, userEntry);
				arraySize = getValidInt(userEntry);
				if (arraySize <= 0)
				{
					cout << "Please enter a positive number: ";
				}
			} while (arraySize <= 0);
			// Dynamically allocate the array
			arrayPtr = new int[arraySize];
			// Fill array with variables from user
			for (int i = 0; i < arraySize; i++)
			{
				cout << "Enter Integer #" << (i + 1) << ": ";
				getline(cin, userEntry);
				intEntry = getValidInt(userEntry);
				arrayPtr[i] = intEntry;
			}
			// Display result
			cout << endl << "The sum of the numbers is ";
			cout << sumArray(arrayPtr, arraySize) << "." << endl;
			// Delete dynamically allocated memory
			delete [] arrayPtr;
		}
		// Run the triangular number function
		else if (menuChoice == 3)
		{
			// Get a valid input from the user
			cout << endl << "What number would you like to get the";
			cout << " triangular number of? ";
			do
			{
				getline(cin, userEntry);
				intEntry = getValidInt(userEntry);
				if (intEntry < 0)
				{
					cout << "Please enter a non-negative number: ";
				}
			} while (intEntry < 0);
			// Run function and display result
			cout << endl << "The triangular number of " << intEntry;
			cout << " is " << triangularNumber(intEntry);
			cout << "." << endl;
		}
	} while (menuChoice != 4);

	return 0;
}
