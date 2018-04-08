/**************************************
 * Name: Andrew Funk
 * Date: 7-24-17
 * Description: Entree.hpp is the class specification file for
 * 				the 'Entree' class. It has get member functions 
 * 				for each variable, as well as a two constructors. 
 *************************************/

#ifndef ENTREE_HPP		//Include guard
#define ENTREE_HPP

#include <string>
using std::string;		//Standard namespace for strings

//Entree class declaration
class Entree
{
	private:	
		string entreeName;
		int calories;

	public:
		Entree();					//Default constructor
		Entree(string, int);		//Constructor
		string getName();
		int getNumCalories();
};

#endif
