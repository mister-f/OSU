/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Scissors Class Implementation File
*********************************************************************/

#include "scissorClass.hpp"

//Default Constructor
Scissors::Scissors()
{
	setStrength(1);
	type = 's';
}
		
//Constructor
Scissors::Scissors(int toolStrength)
{
	setStrength(toolStrength);
	type = 's';
}

//Destructor
Scissors::~Scissors(){}

//function that returns the result of the fight as an enum
Result Scissors::fight(Tool *toolPtr)
{
	double tempStrength;	//holds the temporary stength of scissors
	
	//if the opponent is paper
	if (toolPtr->getType() == 'p')
	{
		tempStrength = strength * 2;	//scissors' stength doubles
		
		//scissors wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//scissors loses if its strength is less than
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
	
	//if the opponent is rock
	else if (toolPtr->getType() == 'r')
	{
		tempStrength = static_cast<double>(strength) / 2;	
		//scissors' strength is halved
		
		//scissors wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//scissors loses if its strength is less than
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
	
	else if (toolPtr->getType() == 's')
	{
		tempStrength = strength;

		//this scissors wins if its strength is greater
		if (tempStrength > toolPtr->getStrength())
		{
			return WIN;
		}
		
		//this scissors loses if its strength is less than
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
