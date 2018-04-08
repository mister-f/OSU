/**************************************
 * Program Name: game.hpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: game.hpp is the class specification file for the
 * 				Game class. It contains the delcarations for the 
 * 				member variables and functions of the Game class.
 *************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "zoo.hpp"
#include "menu.hpp"
#include "getValidInt.hpp"
using std::string;
using std::vector;

class Game
{
	private:
		string menuName;
		vector<string> menuItems;
		string userEntry;
		int menuChoice;
		int budget;
		int userChoice;
		int dailyProfit;
		int dailyFeedCost;
		int dayCounter;
		Zoo playerZoo;
		
			
	public:
		Game();
		void playGame();
		void playDay();
		void printSummary();
};

#endif
