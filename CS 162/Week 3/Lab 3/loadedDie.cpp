/**************************************
 * Program Name: loadedDie.cpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: loadedDie.cpp is the class implementation file for the
 * 				LoadedDie class. It contains a constructor for the class
 * 				and a fucntion to simulate a "loaded" die roll.
 *************************************/

#include "loadedDie.hpp"

/*************************************
 * Description: This is the constructor for the LoadedDie class.
 * 				it inherits the characteristics of the Die class.
 ************************************/

LoadedDie::LoadedDie(int sidesIn) : Die(sides)
{
	sides = sidesIn;
}

/************************************
 * Description: rollDie is a member function that simulates rolling 
 * 				a dice where the higher values have a greater chance of
 * 				turning up. It does this by simulating two die rolls and
 * 				returning the value of the highest roll.
 **********************************/

int LoadedDie::rollDie()
{
	int rollA;
	int rollB;

	// Simulate two normal rolls
	rollA = ((rand() % sides) + 1);
	rollB = ((rand() % sides) + 1);

	// Return the higher roll
	if (rollA >= rollB)
	{
		return rollA;
	}
	else
	{
		return rollB;
	}
}


