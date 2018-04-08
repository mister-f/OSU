/***********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: RPSGame Class Implementation File
***********************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>			//Edited JER 11/1
#include "RPSGame.hpp"		//Edited JER 11/1

using std::cout;			//Edited JER 11/1
using std::endl;			//Edited JER 11/1
using std::string;
using std::stringstream;
using std::cin;

/**********************************************************************
** RPSGame()- creates RPSGame object 
***********************************************************************/
RPSGame::RPSGame()
{
	// Constructor sets default varibale options
	userStrength = 1;
	compStrength = 1;
	human_wins = 0; 
	computer_wins = 0; 
	ties = 0;
	roundNumber = 1;
	playOn = true;  
}

/**********************************************************************
** void setStrength()- sets strength as default or custom per user 
** choice and if it is custom, then it randomizes computer tool strength 
**********************************************************************/

void RPSGame::setStrength()
{
	string input; 
	int choice; 

	// Print game introduction
	cout << "Welcome to the rock, paper, scissors game! " << "\n\n"; 
	cout << "Would you like to have default strength for your and ";
	cout << "the opponents tool," << "\n";
	cout << "or select a strength value yourself?" << "\n\n"; 
	cout << "1) Default Strength" << "\n"; 
	cout << "2) Select Strength" << "\n\n"; 

	// Validate user strength option
	do
	{
		cout << "Choose strength option by inputting 1 or 2: " << "\n";	 
		getline(cin, input); 
		stringstream selection(input); 
		selection >> choice;
	} while ((choice != 1) && (choice != 2));

	if (choice == 2)
	{
		string strength; 
		int strengthChoice; 

		cout << "\nChoose a strength value between 1 and 15" << "\n";

		do
		{ 
			cout << "Enter strength value: " << "\n"; 
			getline(cin, strength); 
			stringstream selection(strength); 
			selection >> strengthChoice;
		} while ((strengthChoice < 1) || (strengthChoice > 15));

		// Set user strength
		userStrength = strengthChoice; 

		// Generate random computer strength
		compStrength = rand() % 15 + 1; 

		cout << "\nComputer selected strength: " << compStrength << "\n"; 
	}
}
 	
/******************************************************************
** void RPSGame::selectTool()- has user select his type of tool and 
** computer randomly selected its tool 
******************************************************************/

void RPSGame::selectTool()
{
	string toolInput; 
	int toolChoice; 
	int compTool = rand() % 3 + 1; //decides between 1,2,3 for computer Tool

	// Print menu for tool input
	cout << "\nPlease select your tool choice between: ";
	cout << "Rock, Paper, or Scissors" << "\n"; 
	cout << "1) Rock" << "\n"; 
	cout << "2) Paper" << "\n"; 
	cout << "3) Scissors" << "\n"; 

	// Get and validate user tool choice
	do
	{ 
		cout << "Enter tool choice: " << "\n"; 
		getline(cin, toolInput); 
		stringstream selection(toolInput); 
		selection >> toolChoice;
	} while ((toolChoice != 1) && (toolChoice != 2) && (toolChoice !=3 ));

	// Dynamically allocate the human tool
	if (toolChoice == 1)
	{	
		humanPtr = new Rock(userStrength);
		// put userStrength in constructor
	}
	else if (toolChoice == 2)
	{
		humanPtr = new Paper(userStrength);
	}
	else if (toolChoice == 3)
	{
		humanPtr = new Scissors(userStrength); 
	}

	// Dynamically allocate computer tool, print out computer choice
	// put compStrength in constructor
	if (compTool == 1)
	{
		cout << "\nThe computer chose rock.\n"; 
		compPtr = new Rock(compStrength);	
	}
	else if (compTool == 2)
	{
		cout << "\nThe computer chose paper.\n"; 
		compPtr = new Paper(compStrength);
	}
	else if (compTool == 3)	
	{
		cout << "\nThe computer chose scissors.\n"; 
		compPtr = new Scissors(compStrength);
	}
}

/************************************************************************
** void RPSGame::playRound()- This function deferences the tool pointers
** previously created and executes their fight function and then gets 
** the return values (which are ENUMS). It also updates the win total.
************************************************************************/

//Check human tool's fight results with computer pointer. 
//Add to score counter if either player wins. Add to tie counter 
//if the game is a draw
void RPSGame::playRound()
{
	if (humanPtr->fight(compPtr) == WIN)  
	{
		cout << "You win!" << endl;
		human_wins++;
	}

	else if(humanPtr->fight(compPtr) == LOSS)
	{
		cout << "The Computer wins!" << endl;
		computer_wins++;
	}
	
	else if(humanPtr->fight(compPtr) == DRAW)
	{
		cout << "This round is a draw!" << endl;
		ties++;
	}
}

/**********************************************************************
** deleteToolsFromRound()- This function deletes any dynamically 
** allocated tools from the prior round.
**********************************************************************/

void RPSGame::deleteToolsFromRound()			//Edited typo - JER 11/1
{
	delete humanPtr;
	humanPtr = NULL;
	delete compPtr;
	compPtr = NULL;
}

/************************************************************************
** printResults()- Prints the current win totals of the game
************************************************************************/

void RPSGame::printResults()
{
	cout << "\nPlayer Wins: " << human_wins << "\n"; 
	cout << "Computer Wins: " << computer_wins << "\n"; 
	cout << "Ties: " << ties << "\n";
} 

/************************************************************************
** void RPSGame::gameOn()- Quarterbacks all the functions for the game and 
** quits once the user inputs they would not like to play again.
************************************************************************/

void RPSGame::gameOn()
{

	setStrength(); 
	//includes welcome to game and gives option for 
	//default or custom strength 

	//Repeat each round until user quits
	while (playOn == true) 
	{	
		cout << "\n------- Round " << roundNumber << "-------\n";

		selectTool(); 
		
		playRound();
		
		deleteToolsFromRound();
 
		printResults(); 
	
		playAgain(); 
		
		roundNumber++;	
	}
	
	cout << "Game Over. Thanks for playing!" << "\n"; 
}

/*****************************************
void RPSGame::playAgain()
*****************************************/ 
void RPSGame::playAgain()
{
	string playInput; 
	int playChoice;

	// Ask user if they wish to continue
	do
	{
	cout << "\nWould you like to play again?" << "\n"; 
	cout << "1) Yes 2) No" << "\n"; 
	cout << "Enter your choice: " << "\n"; 

	// Validate user input
	getline(cin, playInput); 
	stringstream selection(playInput); 
	selection >> playChoice;
	} while ((playChoice != 1) && (playChoice != 2));
	

	// Set playOn flag per user choice
	if (playChoice == 1)		//Edited typo - JER 11/1
	{
		playOn=true; 
	}

	if (playChoice == 2)		//Edited typo - JER 11/1
	{
		playOn=false;
	}
}
