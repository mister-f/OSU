/**************************************
 * Name: Andrew Funk
 * Date: 7-29-17
 * Description: Person.cpp is the class implementation file for
 * 				the 'Person' class. The Person class takes a string
 * 				and a double, has a constructor, and get functions 
 * 				for each member variable. 
 *************************************/

#include "Person.hpp"
#include <string>
using std::string;		//Standard namespace for strings

/*************************************
 * Description: This is a constructor used to initialize the name 
 * 				and age of a Person object.
 ************************************/
					
Person::Person(string nameIn, double ageIn)
{
	name = nameIn;
	age = ageIn;
}

string Person::getName()		//Get function
{
	return name;
}

double Person::getAge()			//Get function
{
	return age;
}

