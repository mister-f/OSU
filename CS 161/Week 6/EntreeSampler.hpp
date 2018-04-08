/**************************************
 * Name: Andrew Funk
 * Date: 7-24-17
 * Description: EntreeSampler.hpp is the class specification file for
 * 				the 'EntreeSampler' class. It four member variables of
 * 				the Entree class as well as a constructor function and
 * 				two member functions. 
 *************************************/

#ifndef ENTREESAMPLER_HPP		//Include guard
#define ENTREESAMPLER_HPP

#include "Entree.hpp"			//Header file to use 'Entree' objects

//EntreeSampler class declaration
class EntreeSampler
{
	private:	
		Entree entree1;
		Entree entree2;
		Entree entree3;
		Entree entree4;

	public:
		EntreeSampler(Entree, Entree, Entree, Entree);	//Constructor
		void listEntrees();
		int totalCalories();
};

#endif
