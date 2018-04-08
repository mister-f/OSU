/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Paper Class Implementation File
*********************************************************************/

#include "paperClass.hpp"

//Default Constructor
Paper::Paper()
{
	setStrength(1);
	type = 'p';
}
		
//Constructor
Paper::Paper(int toolStrength)
{
	setStrength(toolStrength);
	type = 'p';
}
	
//Destructor
Paper::~Paper(){}
	
//function that returns the result of the fight as an enum
Result Paper::fight(Tool *toolPtr)
{
	double tempStrength;	//holds the temporary strength value
		
	//if the opponent is a rock
	if (toolPtr->getType() == 'r')
	{
		tempStrength = strength * 2;	//paper strength is doubled
		
		//paper wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//paper loses if its strength is less than
		else if (tempStrength < toolPtr->getStrength())
		{
			return LOSS;
		}
		
		//the match ends in a draw
		else
		{
			return DRAW;
		}
	}
		
	//if the opponent is scissors
	else if (toolPtr->getType() == 's')
	{
		tempStrength = static_cast<double>(strength) / 2;	
		//paper strength is halved
			
		//paper wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
			
		//paper loses if its strength is less than
		else if (tempStrength < toolPtr->getStrength())
		{
			return LOSS;
		}
			
		//the match results in a draw
		else
		{
			return DRAW;
		}
	}
		
	else if (toolPtr->getType() == 'p')
	{
		tempStrength = strength;		

		//this paper wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//this paper loses if its strength is less than
		else if (tempStrength < toolPtr->getStrength())
		{
			return LOSS;
		}
			
		//the match results in a draw
		else
		{
			return DRAW;
		}		
	}
}
