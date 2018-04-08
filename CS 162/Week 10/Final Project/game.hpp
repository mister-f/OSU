/**************************************
 * Program Name: game.hpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: game.hpp is the class specification file for the
 * 				Game class. It contains the delcarations for the 
 * 				member variables and functions of the Game class.
 *************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "getValidInput.hpp"
#include "space.hpp"
#include "item.hpp"
#include "character.hpp"
#include "container.hpp"

class Game
{
	private:
		int timer;
		int odinHas;
		bool victory;
		Space* currentSpace;
		// Game objects
		Hel hel;
		Trunk trunk1;
		Trunk trunk2;
		Nilfheim nilfheim;
		Jotunheim jotunheim;
		Midgard midgard;
		Vanaheim vanaheim;
		Asgard asgard;
		Character thor;
		Character loki;
		Character odin;
		Character freya;
		Item mjolnir;
		Item acorn;
		Item brisingamen;
		Item draupnir;
		Item gungnir;	
		Container satchel;
	
	public:
		Game();
		void playGame();
		void useItem(Item*);
		void miniGame();
};

#endif
