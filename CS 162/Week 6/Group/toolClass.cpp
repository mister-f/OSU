/*********************************************************************
** Program name: Group 14 Rock, Paper, Scissors
** Author: Eric Riemer, Nathan Chang, Andrew Funk, 
**		   Nicholas Marozick, Jessica Richmond
** Date: 10/26/2017
** Description: Tool Class Implementation File
*********************************************************************/

#include "toolClass.hpp"
	
//Destructor
Tool::~Tool(){}
	
//sets the strength of the tool
void Tool::setStrength(int power)
{
	strength = power;
}
	
//returns the strength of the tool
int Tool::getStrength()
{
	return strength;
}

//returns the type of tool
char Tool::getType()
{
	return type;
}
