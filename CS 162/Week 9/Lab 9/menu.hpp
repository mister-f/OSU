/**************************************
 * Program Name: menu.hpp
 * Name: Andrew Funk
 * Date: 10-05-17
 * Description: menu.hpp is the class specification file for the 
 * 				Menu class. It contains the declarations for the
 * 				member variables and functions of the Menu class.
 *************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
using std::string;
using std::vector;

//Menu class declaration
class Menu
{
	private:
		string menuName;
		vector<string> menuItems;
		string userEntry;
		unsigned int userSelection;

	public:
		Menu(string, vector<string>);		//Constructor
		void displayMenu();
		unsigned int getChoice();
};

#endif
