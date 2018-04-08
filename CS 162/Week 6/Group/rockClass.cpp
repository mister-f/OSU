/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Rock Class Implementation File
*********************************************************************/

#include "rockClass.hpp"

//Default Constructor
Rock::Rock()
{
	setStrength(1);
	type = 'r';
}
		
//Constructor
Rock::Rock(int toolStrength)
{
	setStrength(toolStrength);
	type = 'r';
}
	
//Destructor
Rock::~Rock(){}

//function that returns the result of the fight as an enum
Result Rock::fight(Tool *toolPtr)
{
	double tempStrength;	//holds the temporary strength value
	
	//if the opponent is scissors
	if (toolPtr->getType() == 's')
	{
		tempStrength = strength * 2;	//rock's strength is doubled
		
		//rock wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//rock loses if its strength is less than
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
	
	//if the opponent is paper
	else if (toolPtr->getType() == 'p')
	{
		tempStrength = static_cast<double>(strength) / 2;	
		//rock's strength is halved
		
		//rock wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//rock loses if its strength is less than
		else if (tempStrength < toolPtr->getStrength())
		{
			return LOSS;
		}
		
		//the match results in a tie
		else
		{
			return DRAW;
		}
	}
		
	else if (toolPtr->getType() == 'r')
	{
		tempStrength = strength;		

		//this rock wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//this rock loses if its strength is less than
		else if (tempStrength < toolPtr->getStrength())
		{
			return LOSS;
		}
		
		//the match results in a tie
		else
		{
			return DRAW;
		}
	}
}
