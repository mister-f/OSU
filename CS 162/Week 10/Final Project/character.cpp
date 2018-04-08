/**************************************
 * Program Name: character.cpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: character.cpp is the class implementation file for the
 * 				Character class. It contains set and get functions for 
 * 				all the Character variables.
 *************************************/

#include "character.hpp"

/****************************
 * Description: This is the constructor for a character. It sets the text
 * 				fields to blank and initializes the flags as false.
 ***************************/

Character::Character()
{
	name = " ";
	firstConvo = " ";
	secondConvo = " ";
	success = " ";
	talkedTo = false;
	fulfilled = false;
}

// Set function
void Character::setName(string nameIn)
{
	name = nameIn;
}

// Set function
void Character::setFirstConvo(string convoIn)
{
	firstConvo = convoIn;
}

// Set function
void Character::setSecondConvo(string convoIn)
{
	secondConvo = convoIn;
}

// Set function
void Character::setSuccess(string successIn)
{
	success = successIn;
}

// Set function
void Character::setTalkedTo(bool talkIn)
{
	talkedTo = talkIn;
}

// Set function
void Character::setFulfilled(bool statusIn)
{
	fulfilled = statusIn;
}

// Get function
string Character::getName()
{
	return name;
}

// Get function
string Character::getFirstConvo()
{
	return firstConvo;
}

// Get function
string Character::getSecondConvo()
{
	return secondConvo;
}

// Get function
string Character::getSuccess()
{
	return success;
}

// Get function
bool Character::getTalkedTo()
{
	return talkedTo;
}

// Get function
bool Character::getFulfilled()
{
	return fulfilled;
}
