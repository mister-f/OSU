/**************************************
 * Name: Andrew Funk
 * Date: 8-7-17
 * Description: TicTacToe.hpp is the class specification file for
 * 				the 'TicTacToe' class. It has a Board member variable
 * 				along with a member variable for a player's move. The
 * 				class also has a constructor and a play function that
 * 				starts a Tic Tac Toe game.
 *************************************/

#ifndef TICTACTOE_HPP		//Include guard
#define TICTACTOE_HPP

#include "Board.hpp"

//TicTacToe class declaration
class TicTacToe
{
	private:	
		Board gameBoard;
		char playerMove;

	public:
		TicTacToe(char);					//Constructor
		void play();
};

#endif
