/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Tool Class Header File
*********************************************************************/

#ifndef TOOLCLASS_HPP
#define TOOLCLASS_HPP

#include <iostream>

//enumerator for result of the fight
enum Result{WIN, LOSS, DRAW};
	
class Tool
{
	protected:
		//strength of the tool
		int strength;
		//type of tool
		char type;
		
		
	public:
		
		//Destructor
		virtual ~Tool();
		
		//sets the strength of the tool
		void setStrength(int);
		
		//returns the strength of the tool
		int getStrength();
		
		//returns the type of tool
		char getType();
		
		//pure virtual function that returns the result 
		//of the fight as an enum
		virtual Result fight(Tool*) = 0;

};

#endif
