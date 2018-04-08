#include <iostream>
#include "Quadratic.hpp"

using namespace std;

int main()
{
	double a, b, c;

	Quadratic quad1(1, 0, 1);
	quad1.setC(1.5);
	cout << quad1.getA() << endl;
	cout << quad1.valueFor(7) << endl;
	cout << quad1.numRealRoots() << endl;

	cout << "Set a, b, and c: " << endl;
	cin >>  a >> b >> c;

	quad1.setA(a);
	quad1.setB(b);
	quad1.setC(c);

	cout << quad1.getA() << endl;
	cout << quad1.getB() << endl;
	cout << quad1.getC() << endl;
	cout << quad1.numRealRoots() << endl;

	return 0;
}

