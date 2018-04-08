/**************************************
 * Name: Andrew Funk
 * Date: 7-24-17
 * Description: EntreeSampler.cpp is the class implementation file for
 * 				the 'EntreeSampler' class. The EntreeSampler class has
 * 				four member variables of the Entree class. Member functions
 * 				are included for the constructor, to output the Entrees in 
 * 				an EntreeSampler member variable, and to output the total 
 * 				calories in a member variable. 
 *************************************/

#include <iostream>
#include "EntreeSampler.hpp"
using std::cout;
using std::endl;						//Namespace declarations for output

/*************************************
 * Description: This is a constructor member function that initializes a 
 * 				class object that comprises 4 Entree objects.
 ************************************/

EntreeSampler::EntreeSampler(Entree entree1In, Entree entree2In, 
								Entree entree3In, Entree entree4In)	
{
	entree1 = entree1In;
	entree2 = entree2In;
	entree3 = entree3In;
	entree4 = entree4In;
}

/***********************************
 * Description: This is a function that simply prints out the names
 * 				of the Entrees contained within an EntreeSampler object.
 **********************************/

void EntreeSampler::listEntrees()
{
	cout << "1. " << entree1.getName() << endl;
	cout << "2. " << entree2.getName() << endl;
	cout << "3. " << entree3.getName() << endl;
	cout << "4. " << entree4.getName() << endl;
}

/***********************************
 * Description: This function totals all of the calories of the Entrees
 * 				stored in an EntreeSampler object and then returns the
 * 				total as an integer.
 **********************************/

int EntreeSampler::totalCalories()
{
	return (entree1.getNumCalories() + entree2.getNumCalories() + 
			entree3.getNumCalories() + entree4.getNumCalories());
}
