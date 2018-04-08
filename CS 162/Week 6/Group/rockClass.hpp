/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Rock Class Header File
*********************************************************************/

#ifndef ROCKCLASS_HPP
#define ROCKCLASS_HPP

#include "toolClass.hpp"

class Rock: public Tool
{
	public:
		
		//Default Constructor
		Rock();
		
		//Constructor
		Rock(int);
		
		//Destructor
		~Rock();
		
		//function that returns the result of the fight as an enum
		Result fight(Tool*);	

};

#endif
