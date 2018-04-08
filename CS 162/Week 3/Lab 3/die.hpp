/**************************************
 * Program Name: die.hpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: die.hpp is the class specification file for the
 * 				Die class. It contains the delcarations for the 
 * 				member variables and functions of the Die class.
 *************************************/

#ifndef DIE_HPP
#define DIE_HPP
#include <cstdlib>

class Die
{
	protected:					//Protected class so LoadedDie can access
		int sides;

	public:
		Die(int);
		//Virtual declarations so LoadedDie accesses proper functions
		virtual int rollDie();	
		virtual ~Die();
};

#endif
