/**************************************
 * Program Name: ant.hpp
 * Name: Andrew Funk
 * Date: 10-05-17
 * Description: ant.hpp is the class specification file for the 
 * 				Ant class. It contains the declarations for the
 * 				member variables and functions of the Ant class.
 *************************************/

#ifndef ANT_HPP
#define ANT_HPP

//Enumerated value for ant orientation
enum Orientation { UP, DOWN, LEFT, RIGHT };

//Ant class declaration
class Ant
{
	private:
		int antXPos;
		int antYPos;
		int boardWidth;
		int boardHeight;
		char** boardArray;
		Orientation antDirection;

	public:
		Ant(int, int, int, int);		//Constructor
		void displayBoard();
		void moveAnt();
		~Ant();							//Destructor
};

#endif
