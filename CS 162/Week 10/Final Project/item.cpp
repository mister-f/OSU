/**************************************
 * Program Name: item.cpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: item.cpp is the class implementation file for the
 * 				Item class.
 *************************************/

#include "item.hpp"

/******************************
 * Description: The default Item constructor. It sets the name to blank
 * 				and the inBag flag to false.
 *****************************/

Item::Item()
{
	name = " ";
	inBag = false;
}

// Set function
void Item::setName(string nameIn)
{
	name = nameIn;
}

// Set function
void Item::setInBag(bool bagState)
{
	inBag = bagState;
}

// Get function
string Item::getName()
{
	return name;
}

// Get function
bool Item::getInBag()
{
	return inBag;
}
