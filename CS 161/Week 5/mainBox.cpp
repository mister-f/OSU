/**************************************
 * Name: Andrew Funk
 * Date: 7-20-17
 * Description:  Main method for testing Box class.
 *************************************/

#include <iostream>
#include "Box.hpp"
using namespace std;

int main ()
{
	Box box1(2.4, 7.1, 5.0);
	Box box2;
	double h, w, l;
	double volume1 = box1.calcVolume();
	double surfaceArea1 = box1.calcSurfaceArea();
	double volume2 = box2.calcVolume();
	double surfaceArea2 = box2.calcSurfaceArea();

	cout << "Enter H, W, L" << endl;
	cin >> h >> w >> l;

	box2.setHeight(h);
	box2.setWidth(w);
	box2.setLength(l);

	volume2 = box2.calcVolume();
	surfaceArea2 = box2.calcSurfaceArea();

	cout << " VOL: " << volume2 << " SA: " << surfaceArea2 << endl;
	return 0;
}
