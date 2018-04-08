/**************************************
 * Name: Andrew Funk
 * Date: 8-7-17
 * Description: Board.hpp is the class specification file for
 * 				the 'Board' class. It has functions to print a
 * 				Tic Tac Toe board, make a player move and update
 * 				the board layout, return the game state, and a 
 * 				default board constructor. 
 *************************************/

#ifndef BOARD_HPP		//Include guard
#define BOARD_HPP

//enum for game state determination and a const
//int for the board size
enum Status { X_WON, O_WON, DRAW, UNFINISHED };
const int BOARD_SIZE = 3;

//Board class declaration
class Board
{
	private:	
		char layout[BOARD_SIZE][BOARD_SIZE];

	public:
		Board();						//Default constructor
		bool makeMove(int, int, char);
		Status gameState();
		void print();
};

#endif
