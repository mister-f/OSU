/*************************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Rock, Paper, Scissors: play_game.cpp Main File
*************************************************************************/

//You must also have your main function in a play_game.cpp file, 
//separated from the class implementations.

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "RPSGame.hpp"		//Edited JER 11/1
#include "toolClass.hpp"	//Edited JER 11/1
#include "rockClass.hpp"	//Edited JER 11/1
#include "scissorClass.hpp"	//Edited JER 11/1
#include "paperClass.hpp"	//Edited JER 11/1

int main()
{

	srand(time(NULL));	//only do 1 random seeding at beginning 

	RPSGame start; 

	start.gameOn(); 

	return 0; 

}


