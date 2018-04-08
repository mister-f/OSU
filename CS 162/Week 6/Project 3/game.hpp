/**************************************
 * Program Name: game.hpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: game.hpp is the class specification file for the
 * 				Game class. It contains the delcarations for the 
 * 				member variables and functions of the Game class.
 *************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "character.hpp"
#include "menu.hpp"
#include "getValidInput.hpp"
using std::string;
using std::vector;

class Game
{
	private:
		string menuName;
		vector<string> menuItems;
		string userEntry;
		int menuChoice1;
		int menuChoice2;
		int character1Choice;
		int character2Choice;
		Character* playerOne;
		Character* playerTwo;
		int roundNumber;
		bool playOn;
		bool bothAlive;	
		
	public:
		Game();
		void playGame();
		void chooseCharacters();
		void fightRound();
		void faceoff(Character*, Character*);
		void deleteCharacters();
		void playAgain();
};

#endif
