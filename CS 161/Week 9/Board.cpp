/**************************************
 * Name: Andrew Funk
 * Date: 8-7-17
 * Description: Board.cpp is the class implmentation file for
 * 				the 'Board' class. It has functions to print a
 * 				Tic Tac Toe board, make a player move and update
 * 				the board layout, return the game state, and a 
 * 				default board constructor. 
 *************************************/

#include <iostream>
#include "Board.hpp"
using std::cout;
using std::endl;

/*************************************
 * Description: This is the default constructor for a Board
 * 				object. It uses nested for loops to fill an
 * 				array with periods, representing an empty board.
 ************************************/

Board::Board()		
{
	for(int row = 0; row < BOARD_SIZE; row++)
	{
		for(int col = 0; col < BOARD_SIZE; col++)
		{
			layout[row][col] = '.';
		}
	}
}

/***********************************
 * Description: makeMove is a member function that takes two 
 * 				integers representing the board position, along
 * 				with the character being entered. It checks to 
 * 				see if the board has a 'blank' (period). If the 
 * 				space is empty it records the move and returns 
 * 				true, and otherwise returns false.
 **********************************/

bool Board::makeMove(int rowIn, int colIn, char moveIn)
{
	// Return false if space is occupied.
	if (layout[rowIn][colIn] != '.')
	{
		return false;
	}
	// If space is empty, enter move and return true.
	else
	{
		layout[rowIn][colIn] = moveIn;
		return true;
	}
}

/************************************
 * Description: The gameState function is used to check what
 * 				the status of the board is and returns an enum
 * 				value representing either an X win, O win, draw,
 * 				or an unfinished game.
 ***********************************/

Status Board::gameState()
{
	// Check all rows, columns, and diagonals for possible
	// 'X' win states
	if ((layout[0][0] == 'x' && layout[0][1] == 'x' && 
			layout[0][2] == 'x') ||	
		(layout[1][0] == 'x' && layout[1][1] == 'x' && 
			layout[1][2] == 'x') ||	
		(layout[2][0] == 'x' && layout[2][1] == 'x' && 
			layout[2][2] == 'x') ||	
		(layout[0][0] == 'x' && layout[1][0] == 'x' && 
			layout[2][0] == 'x') ||	
		(layout[0][1] == 'x' && layout[1][1] == 'x' && 
			layout[2][1] == 'x') ||	
		(layout[0][2] == 'x' && layout[1][2] == 'x' && 
			layout[2][2] == 'x') ||	
		(layout[0][0] == 'x' && layout[1][1] == 'x' && 
			layout[2][2] == 'x') ||	
		(layout[2][0] == 'x' && layout[1][1] == 'x' && 
			layout[0][2] == 'x'))
	{
		return X_WON;
	}
	// Check all rows, columns, and diagonals for 'O'
	// win states.
	else if ((layout[0][0] == 'o' && layout[0][1] == 'o' && 
				layout[0][2] == 'o') ||	
			(layout[1][0] == 'o' && layout[1][1] == 'o' && 
				layout[1][2] == 'o') ||	
			(layout[2][0] == 'o' && layout[2][1] == 'o' && 
				layout[2][2] == 'o') ||	
			(layout[0][0] == 'o' && layout[1][0] == 'o' && 
				layout[2][0] == 'o') ||	
			(layout[0][1] == 'o' && layout[1][1] == 'o' && 
				layout[2][1] == 'o') ||	
			(layout[0][2] == 'o' && layout[1][2] == 'o' && 
				layout[2][2] == 'o') ||	
			(layout[0][0] == 'o' && layout[1][1] == 'o' && 
				layout[2][2] == 'o') ||	
			(layout[2][0] == 'o' && layout[1][1] == 'o' && 
				layout[0][2] == 'o'))
	{
		return O_WON;
	}

	// Nested loops to loop through entire board
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			// Check for empty spaces, and if found 
			// return unfinished state
			if (layout[row][col] == '.')
			{
				return UNFINISHED;
			}
			// If board is looped through with no empty
			// spaces remaining, return as a draw
			else if ((row == 2) && (col == 2))
			{
				return DRAW;
			}
		}
	}
}

/************************************
 * Description: The print function prints a three by three
 * 				Tic Tac Toe board out with the current contents
 * 				of each board square.
 ***********************************/

void Board::print()
{
	cout << endl << "  0 1 2" << endl << endl;
	cout << "0 " << layout[0][0] << " " << layout[0][1];
	cout << " " << layout[0][2] << endl << endl;
	cout << "1 " << layout[1][0] << " " << layout[1][1];
	cout << " " << layout[1][2] << endl << endl;
	cout << "2 " << layout[2][0] << " " << layout[2][1];
	cout << " " << layout[2][2] << endl << endl;
}
