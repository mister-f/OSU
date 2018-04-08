/**************************************
 * Program Name: tournament.hpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: tournament.hpp is the class specification file for the
 * 				Tournament class. It contains the delcarations for the 
 * 				member variables and functions of the Tournament class.
 *************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <string>
#include <vector>
#include "game.hpp"
#include "list.hpp"
#include "menu.hpp"
#include "getValidInput.hpp"
using std::string;
using std::vector;

class Tournament
{
	private:
		string menuName;
		vector<string> menuItems;
		string userEntry;
		int menuChoice;
		int teamASize;
		int teamBSize;
		int teamAWins;
		int teamBWins;
		List teamA;
		List teamB;
		List loserPile;
		Character* playerChoice;
		int battleNumber;
		bool playOn;
		bool bothAlive;
		
	public:
		Tournament();
		void playTournament();
		void fightTourney();
		void chooseCharacters();
		void recovery(Character*);
		void displayResults();
		void deleteCharacters();
		void playAgain();
		~Tournament();
};

#endif
