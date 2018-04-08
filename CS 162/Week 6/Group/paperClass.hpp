/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Paper Class Header File
*********************************************************************/

#ifndef PAPERCLASS_HPP
#define PAPERCLASS_HPP

#include "toolClass.hpp"

class Paper: public Tool
{
	public:
		
		//Default Constructor
		Paper();
		
		//Constructor
		Paper(int);
		
		//Destructor
		~Paper();
		
		//function that returns the result of the fight as an enum
		Result fight(Tool*);	

};

#endif
