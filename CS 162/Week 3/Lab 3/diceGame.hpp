/**************************************
 * Program Name: diceGame.hpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: diceGame.hpp is the class specification file for the
 * 				DiceGame class. It contains the delcarations for the 
 * 				member variables and functions of the DiceGame class.
 *************************************/

#ifndef DICEGAME_HPP
#define DICEGAME_HPP

#include <string>
#include <vector>
#include "menu.hpp"
#include "getValidInt.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
using std::string;
using std::vector;

// Enumerated values for die type and round outcomes
enum DiceType { LOADED, UNLOADED };
enum RoundResult { DRAW, PLAYER1, PLAYER2 }; 

class DiceGame
{
	private:
		string menuName;
		vector<string> menuItems;
		string userEntry;
		int menuChoice;
		int player1Score;
		int player2Score;
		int player1Size;
		int player2Size;
		int roundNumber;
		int roll1;
		int roll2;
		RoundResult roundStatus;
		// Pointers to be used to dynamically allocate Die objects
		Die* diePtr1;
		Die* diePtr2;
		DiceType player1DieType;
		DiceType player2DieType;

		// Const values for die size limits
		const int MIN_SIDES = 2;
		const int MAX_SIDES = 20;
			
	public:
		DiceGame();
		void playGame();
		void printRound(int, int, RoundResult);
		void playRound(Die*, Die*);
};

#endif
