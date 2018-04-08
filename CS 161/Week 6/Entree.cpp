/**************************************
 * Name: Andrew Funk
 * Date: 7-24-17
 * Description: Entree.cpp is the class implementation file for
 * 				the 'Entree' class. The Entree class takes a string
 * 				and an int, has two constructors, and get functions 
 * 				for each member variable. 
 *************************************/

#include "Entree.hpp"
#include <string>
using std::string;		//Standard namespace for strings

/**************************************
 * Description: This is the default constructor member fucntion. It
 * 				sets the entree name to a blank string and calories 
 * 				to zero.
 *************************************/

Entree::Entree()
{
	entreeName = "";
	calories = 0;
}

/*************************************
 * Description: This is a constructor used to initialize the name 
 * 				and calories of an Entree object.
 ************************************/
					
Entree::Entree(string nameIn, int caloriesIn)
{
	entreeName = nameIn;
	calories = caloriesIn;
}

string Entree::getName()		//Get function
{
	return entreeName;
}

int Entree::getNumCalories()	//Get function
{
	return calories;
}

