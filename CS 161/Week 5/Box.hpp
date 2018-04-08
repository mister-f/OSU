/**************************************
 * Name: Andrew Funk
 * Date: 7-20-17
 * Description: Box.hpp is the class specification file for the 'Box'
 * 				class. It includes class declarations, including 
 * 				constructors, and include guards.
 *************************************/

#ifndef BOX_HPP		//Include guard
#define BOX_HPP

//Box class declaration
class Box
{
	private:
		double height;
		double width;
		double length;

	public:
		Box();								//Constructor
		Box(double, double, double);		//Constructor
		void setHeight(double);
		void setWidth(double);
		void setLength(double);
		double calcVolume();
		double calcSurfaceArea();

};

#endif
