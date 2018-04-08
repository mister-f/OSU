/**************************************
 * Name: Andrew Funk
 * Date: 7-20-17
 * Description:  Main method for testing Taxicab class.
 *************************************/

#include <iostream>
#include "Taxicab.hpp"
using namespace std;

int main ()
{
	Taxicab cab1;
	Taxicab cab2(5, 7);

	cab1.moveX(2);
	cab1.moveY(2);
	cab1.moveX(2);
	cout << cab1.getDistanceTraveled() << endl;
	cab2.moveY(7);
	cout << cab2.getXCoord() << endl;
	return 0;
}
