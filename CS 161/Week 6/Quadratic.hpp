/**************************************
 * Name: Andrew Funk
 * Date: 7-23-17
 * Description: Quadratic.hpp is the class specification file for
 * 				the 'Quadratic' class. It includes setter and getter
 * 				member functions for each variable, as well as two
 * 				constructors and two other member fucntions. 
 *************************************/

#ifndef QUADRATIC_HPP		//Include guard
#define QUADRATIC_HPP

//Quadratic class declaration
class Quadratic
{
	private:	
		double a;
		double b;
		double c;

	public:
		Quadratic();							//Default constructor
		Quadratic(double, double, double);		//Constructor
		double getA();
		double getB();
		double getC();
		void setA(double);
		void setB(double);
		void setC(double);
		double valueFor(double);
		int numRealRoots();
};

#endif
