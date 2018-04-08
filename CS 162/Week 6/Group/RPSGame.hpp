/***********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: RPSGame Class Header File
***********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "toolClass.hpp"	//Edited JER 11/1
#include "rockClass.hpp"	//Edited JER 11/1
#include "scissorClass.hpp"	//Edited JER 11/1
#include "paperClass.hpp"	//Edited JER 11/1

#ifndef RPSGAME_HPP		//Edited JER 11/1
#define RPSGAME_HPP		//Edited JER 11/1

class RPSGame
{
	public: 

		RPSGame(); 
		void gameOn();
		void setStrength(); 
		void selectTool(); 
		void playRound();
		void deleteToolsFromRound(); 
		void printResults(); 
		void playAgain(); 

	protected: 

		Tool* compPtr; 
		Tool* humanPtr;
		int human_wins; 
		int computer_wins; 
		int ties; 
		int userStrength; 	
		int compStrength; 	
		int roundNumber;		
		bool playOn;			//Edited JER 11/1
}; 

#endif 
