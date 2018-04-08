/**************************************
 * Name: Andrew Funk
 * Date: 8-7-17
 * Description: TicTacToe.cpp includes the class implementation for
 * 				the 'TicTacToe' class and runs a two player Tic Tac Toe
 * 				game.
 *************************************/

#include <iostream>
#include <cctype>
#include "TicTacToe.hpp"
using std::cout;
using std::cin;
using std::endl;

/**************************************
 * Description: This is the constructor for the TicTacToe object.
 * 				It takes a character in as the first move of the 
 * 				game.
 *************************************/

TicTacToe::TicTacToe(char initialMove)
{
	playerMove = initialMove;
}

/************************************
 * Description: The play function starts a game of Tic Tac Toe.
 * 				It continues printing out boards and accepting moves
 * 				until a end game state is reached. It also validates
 * 				moves to ensure the same move isn't made twice.
 ***********************************/

void TicTacToe::play()
{
	int rowPlay, colPlay;

	// Loop that continues as long as game is not finished
	while (gameBoard.gameState() == UNFINISHED)
	{
		// Print the board and get a new move
		gameBoard.print();
		cout << "Player " << static_cast<char>(toupper(playerMove));
		cout << ": please enter your move (row first)." << endl;
		cin >> rowPlay >> colPlay;
		// Verify that a move is not made into an already 
		// occupied square
		while (!gameBoard.makeMove(rowPlay, colPlay, playerMove))
		{
			cout << endl << "That square is already taken." << endl;		
			gameBoard.print();
			cout << "Player " << static_cast<char>(toupper(playerMove));
			cout << ": please enter your move (row first)." << endl;
			cin >> rowPlay >> colPlay;
		}

		// After a successful move, swap player turn
		if (playerMove == 'x')
		{
			playerMove = 'o';
		}
		else
		{
			playerMove = 'x';
		}
	}
	
	// If X has won print message
	if (gameBoard.gameState() == X_WON)
	{
		gameBoard.print();
		cout << "X Wins!" << endl;
	}
	// If O has won print message
	else if (gameBoard.gameState() == O_WON)
	{
		gameBoard.print();
		cout << "O Wins!" << endl; 
	}
	// If game is drawn, impart some WOPR wisdom
	else if (gameBoard.gameState() == DRAW)
	{
		gameBoard.print();
		cout << "It's a draw. The only winning move is not to play."; 
		cout << endl;
	}
}

/************************************
 * Description: The main function gets a starting token for
 * 				a Tic Tac Toe game, and then initiates the 
 * 				game.
 ***********************************/

int main()
{
	char firstMove;
	
	// Get starting character
	cout << "Shall we play a game?" << endl << endl;
	cout << "1. Tic Tac Toe" << endl;
	cout << "2. Global Thermonuclear War" << endl;
	cin.get();
	cout << "Just messing around. We're playing Tic Tac Toe." << endl;
	cout << "Who goes first; X or O?" << endl;
	cin >> firstMove;

	// Validate starting character
	while ((tolower(firstMove) != 'x') && (tolower(firstMove) != 'o'))
	{
		cout << "Try again, X or O?" << endl;
		cin >> firstMove;
	}
	
	// Create a new TicTacTow object and play game
	TicTacToe newBoard(tolower(firstMove));
	newBoard.play();

	return 0;
}
