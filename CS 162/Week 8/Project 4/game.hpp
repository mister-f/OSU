/**************************************
 * Program Name: game.hpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: game.hpp is the class specification file for the
 * 				Game class. It contains the delcarations for the 
 * 				member variables and functions of the Game class.
 *************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"

class Game
{
	private:
		bool playOn;
		bool bothAlive;	
		
	public:
		Game();
		void playGame(Character*, Character*);
		void fightRound(Character*, Character*);
		void faceoff(Character*, Character*);
};

#endif
