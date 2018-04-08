/**************************************
 * Program Name: menu.cpp
 * Name: Andrew Funk
 * Date: 10-05-17
 * Description: menu.cpp is the class implementation file for the 
 * 				Menu class. It has functions to create and display a menu
 * 				as well as get and return a user selected choice from the 
 * 				menu. User choices are validated. 
 *************************************/

#include <iostream>
#include "menu.hpp"
#include "getValidInt.hpp"
using std::string;
using std::vector;
using std::cout;
using std::endl;

/******************************
 * Description: This is the default constructor for a Menu object. It
 * 				takes a menu name as a string and a list of menu items
 * 				for display as a vector.
 *****************************/

Menu::Menu(string menuNameIn, vector<string> menuItemsIn)
{
	menuName = menuNameIn;
	menuItems = menuItemsIn;
}
		
/*******************************
 * Description: displayMenu is a member function that takes no parameters
 * 				and displays to the user a menu title along with a list of 
 * 				menu choices.
 ******************************/

void Menu::displayMenu()
{
	cout << endl << menuName << endl << endl;
	// Loop through vector based on vector size and display all items
	for (unsigned int i = 1; i <= menuItems.size(); i++)
	{
		cout << i << ". " << menuItems[i - 1] << endl;
	}
	cout << endl;
}
		
/*******************************
 * Description: getChoice is a member function that takes no parameters 
 * 				and returns a user selection as an unsigned integer. The
 * 				user entry is validated as an integer using a separate 
 * 				function, 'getValidInt' and also verified to be within the
 * 				bounds of the vector of menu items.
 ******************************/

unsigned int Menu::getChoice()
{
	do
	{
		cout << "Please enter a menu option." << endl;
		std::getline(std::cin, userEntry);
		userSelection = getValidInt(userEntry);
	} while (!(userSelection > 0 && userSelection <= menuItems.size()));

	return userSelection;
}
