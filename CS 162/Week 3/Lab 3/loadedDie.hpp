/**************************************
 * Program Name: loadedDie.hpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: loadedDie.hpp is the class specification file for the
 * 				LoadedDie class. It contains the delcarations for the 
 * 				functions of the LoadedDie class.
 *************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include <cstdlib>
#include "die.hpp"

class LoadedDie : public Die
{
	public:
		LoadedDie(int);
		// Function is virtual so correct roll function is used
		virtual int rollDie();	
};

#endif

