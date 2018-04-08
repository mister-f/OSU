/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Scissors Class Header File
*********************************************************************/

#ifndef SCISSORSCLASS_HPP
#define SCISSORSCLASS_HPP

#include "toolClass.hpp"

class Scissors: public Tool
{
	public:
		
		//Default Constructor
		Scissors();
		
		//Constructor
		Scissors(int);
		
		//Destructor
		~Scissors();
		
		//function that returns the result of the fight as an enum
		Result fight(Tool*);	

};

#endif
