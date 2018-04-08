/**************************************
 * Program Name: die.cpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: die.cpp is the class implementation file for the
 * 				Die class. It contains a constructor, destructor, and 
 * 				a function to simulate a die roll.
 *************************************/

#include "die.hpp"

/**********************************
 * Description: This is the constructor for a Die object. It sets 
 * 				the number if sides of the die.
 ********************************/

Die::Die(int sidesIn)
{
	sides = sidesIn;
}
	
/********************************
 * Description: The rollDie function returns a random integer that
 * 				represents rolling a die. The number is limited to 
 * 				the number of sides to the die.
 *******************************/

int Die::rollDie()
{
	return ((rand() % sides) + 1);
}

/********************************
 * Description: Destructor for the Die class. It is empty but declared
 * 				for proper function in parent/child class relationship.
 *******************************/
Die::~Die()
{
}
