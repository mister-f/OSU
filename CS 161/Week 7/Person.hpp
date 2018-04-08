/**************************************
 * Name: Andrew Funk
 * Date: 7-29-17
 * Description: Person.hpp is the class specification file for
 * 				the 'Person' class. It has get member functions 
 * 				for each variable, as well as a constructor. 
 *************************************/

#ifndef PERSON_HPP		//Include guard
#define PERSON_HPP

#include <string>
using std::string;		//Standard namespace for strings

//Person class declaration
class Person
{
	private:	
		string name;
		double age;

	public:
		Person(string, double);		//Constructor
		string getName();
		double getAge();
};

#endif
