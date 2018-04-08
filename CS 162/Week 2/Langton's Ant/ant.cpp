/**************************************
 * Program Name: ant.cpp
 * Name: Andrew Funk
 * Date: 10-05-17
 * Description: ant.cpp is the class implementation file for the 
 * 				Ant class. It has functions to display the current 
 * 				Langton's Ant board layout and to increment the ant
 * 				forward one move. There is also a constructor and
 * 				desctructor for the Ant objects.
 *************************************/

#include <iostream>
#include "ant.hpp"
using std::cout;
using std::endl;

/*************************************
 * Description: This is the default constructor for an Ant object.
 * 				It initializes an ant with a given board size, a starting
 * 				position for the ant, an initial orientation, and 
 * 				dynamically allocates a 2D array filled with 'white' 
 * 				spaces for the board.
 ************************************/

Ant::Ant(int widthIn, int heightIn, int antPosXIn, int antPosYIn)
{
	boardWidth = widthIn;
	boardHeight = heightIn;
	antXPos = antPosXIn;
	antYPos = antPosYIn;
	// Ant always starts in the 'UP' position
	antDirection = UP;

	// Dynamically allocate a 2D array of characteres of the 
	// size of the desired board.
	boardArray = new char*[boardHeight];
	for (int i = 0; i < boardHeight; i++)
	{
		boardArray[i] = new char[boardWidth];
	}

	// Nested for loops to start the board as all 'white' spaces
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			boardArray[i][j] = ' ';
		}
	}
}

/***********************************
 * Description: displayBoard is a member function that takes no input
 * 				and prints out the current board configuration. The function
 * 				prints an exterior border around the board as well. Black 
 * 				spaces are represented by '#' and white as blank space ' ' 
 * 				characters. The ant's current position is denoted by '*'.
 **********************************/

void Ant::displayBoard()
{
	// Print the upper border of the board
	for (int i = 0; i < boardWidth; i++)
	{
		if (i == 0)
		{
			cout << " -";
		}
		else if (i == boardWidth - 1)
		{
			cout << "- " << endl;
		}
		else
		{
			cout << "-";
		}
	}

	// Print all the board cells
	for (int i = 0; i < boardHeight; i++)
	{
		// Start each row with a border
		cout << "|";
		for (int j = 0; j < boardWidth; j++)
		{
			// Check if ant occupies current square
			if (!((antXPos == j) && (antYPos == i)))
			{
				cout << boardArray[i][j];
			}
			// Print '*' if ant is in square
			else
			{
				cout << "*";
			}
		}
		// End each row with a border
		cout << "|" << endl;
	}

	// Print the lower border of the board
	for (int i = 0; i < boardWidth; i++)
	{
		if (i == 0)
		{
			cout << " -";
		}
		else if (i == boardWidth - 1)
		{
			cout << "- " << endl;
		}
		else
		{
			cout << "-";
		}
	}

	cout << endl;
}

/**************************************
 * Description: moveAnt is a member function that takes no variables
 * 				and is used to increment the Ant object forward one 
 * 				cell. The three basic steps it uses are; change the ant
 * 				orientation, flip the current cell color, and move the
 * 				ant forward one cell. Orientation change is based on the 
 * 				current color of the cell the ant is in. If the ant 
 * 				reaches the edge of the board and has to move forward, it 
 * 				wraps around to the opposite side (as a torus).
 *************************************/

void Ant::moveAnt()
{
	// First change the orientation of the ant
	
	// If the ant is on a black square, turn 90 degrees left 
	if (boardArray[antYPos][antXPos] == '#')
	{
		if (antDirection == UP)
		{
			antDirection = LEFT;
		}
		else if (antDirection == LEFT)
		{
			antDirection = DOWN;
		}
		else if (antDirection == DOWN)
		{
			antDirection = RIGHT;
		}
		else if (antDirection == RIGHT)
		{
			antDirection = UP;
		}
	}
	// If ant is on a white square, turn 90 degrees right
	else
	{
		if (antDirection == UP)
		{
			antDirection = RIGHT;
		}
		else if (antDirection == RIGHT)
		{
			antDirection = DOWN;
		}
		else if (antDirection == DOWN)
		{
			antDirection = LEFT;
		}
		else if (antDirection == LEFT)
		{
			antDirection = UP;
		}
	}

	// Second, flip the color of the square the ant is on
	
	// If ant is on a black square, turn it white
	if (boardArray[antYPos][antXPos] == '#')
	{
		boardArray[antYPos][antXPos] = ' ';
	}
	// If ant is on a white square, turn it black
	else
	{
		boardArray[antYPos][antXPos] = '#';
	}

	// Last, move ant forward one cell, if on edge wrap around (torus)
	
	// Up orientation move
	if (antDirection == UP)
	{
		// Check if on edge
		if (antYPos != 0)
		{
			antYPos -= 1;
		}
		// If one edge, wrap to last row
		else
		{
			antYPos = boardHeight - 1;
		}
	}
	// Down orientation move
	else if (antDirection == DOWN)
	{
		// Check if on edge
		if (antYPos != (boardHeight - 1))
		{
			antYPos += 1;
		}
		// If on edge, wrap to first row
		else
		{
			antYPos = 0;
		}
	}
	// Left orientation move
	else if (antDirection == LEFT)
	{
		// Check if on edge
		if (antXPos != 0)
		{
			antXPos -= 1;
		}
		// If on edge, wrap to last column
		else
		{
			antXPos = boardWidth - 1;
		}
	}
	// Right orientation move
	else if (antDirection == RIGHT)
	{
		// Check if on edge
		if (antXPos != (boardWidth - 1))
		{
			antXPos += 1;
		}
		// If on edge, wrap to first column
		else
		{
			antXPos = 0;
		}
	}	
}

/************************************
 * Description: This is the destructor for an Ant object. The destructor
 * 				deallocates any dynamic memory that had been set aside for 
 * 				the 2D board arary.
 ***********************************/

Ant::~Ant()
{
	for (int i = 0; i < boardHeight; i++)
	{
		delete[] boardArray[i];
	}
	delete[] boardArray;
}
 
