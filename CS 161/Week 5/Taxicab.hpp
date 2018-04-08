/**************************************
 * Name: Andrew Funk
 * Date: 7-20-17
 * Description: Taxicab.hpp is the class specification file for the 
 * 				'Taxicab' class. It includes class declarations, including 
 * 				constructors, and include guards.
 *************************************/

#ifndef TAXICAB_HPP		//Include guard
#define TAXICAB_HPP

//Taxicab class declaration
class Taxicab
{
	private:
		int currentX;
		int currentY;
		int totalDistance;

	public:
		Taxicab();							//Default constructor
		Taxicab(int, int);					//Constructor
		int getXCoord();
		int getYCoord();
		int getDistanceTraveled();
		void moveX(int);
		void moveY(int);

};

#endif
