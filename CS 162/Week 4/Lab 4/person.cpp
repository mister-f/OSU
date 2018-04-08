/**************************************
 * Program Name: person.cpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: person.cpp is the class implementation file for the
 * 				Person class as well as the derived Student and Instructor
 * 				subclasses. The Person class is an abstract class and 
 * 				the subclasses exhibit polymorphic behavior using virtual
 * 				functions.
 *************************************/

#include <string>
#include <cstdlib>
#include <iostream>
#include "person.hpp"
using std::string;
using std::cout;
using std::endl;
		
/*****************************
 * Description: Constructor for Person object. Used by subclasses when
 * 				constructing dervied objects.
 ****************************/

Person::Person(string nameIn, int ageIn)
{
	name = nameIn;
	age = ageIn;
}		

// Get function
int Person::getAge()
{
	return age;
}

// Get function
string Person::getName()
{
	return name;
}
		
// Destructor
Person::~Person()
{
}

/**************************
 * Description: Constructor for Student objects. Uses the base class 
 * 				constructor and adds in a variable to hold GPA.
 *************************/

Student::Student(string nameIn, int ageIn, double GPAIn) 
	: Person(nameIn, ageIn)
{
	GPA = GPAIn;
}

// Get function
double Student::getNumber()
{
	return GPA; 
}	

// Get function to return a label for the GPA to differentiate 
// between teacher rating
string Student::getLabel()
{
	string label = "GPA";

	return label;
}

/********************************
 * Description: The Student do_work function calculates a random 
 * 				amount of hours and prints out that a student did 
 * 				homework for that long.
 *******************************/

void Student::do_work()
{
	int hours;
	
	hours = ((rand() % 10) + 1);

	cout << endl << name;
	cout << " did " << hours << " hours of homework." << endl;
}

// Destructor
Student::~Student()
{
}

/**************************
 * Description: Constructor for Instructor objects. Uses the base class 
 * 				constructor and adds in a variable to hold teacher rating.
 *************************/

Instructor::Instructor(string nameIn, int ageIn, double ratingIn) : 
	Person(nameIn, ageIn)
{
	rating = ratingIn;
}

// Get function
double Instructor::getNumber()
{
	return rating;
}

// Get function to return a label for teacher rating to distiinguish
// from student GPA
string Instructor::getLabel()
{
	string label = "Rating";

	return label;
}

/********************************
 * Description: The Instructor do_work function calculates a random 
 * 				amount of hours and prints out that a teacher graded
 * 				papers for that long.
 *******************************/

void Instructor::do_work()
{
	int hours;

	hours = ((rand() % 5) + 1);

	cout << endl << name;
	cout << " graded papers for " << hours << " hours." << endl;
}

// Destructor
Instructor::~Instructor()
{
}
