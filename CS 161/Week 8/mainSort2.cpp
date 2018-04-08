/**************************************
 * Name: Andrew Funk
 * Date: 8-4-17
 * Description: This set of functions takes the memory addresses 
 * 				of three integer variables and sorts the integers
 * 				stored at the addresses in ascending order. 
 *************************************/

//Header file and namespace used for testing in main
#include <iostream>
using namespace std;

void smallSort2(int *, int *, int *);

int main()
{
	int entryA, entryB, entryC;

	cout << "Enter three integers:" << endl;
	cin >> entryA >> entryB >> entryC;

	smallSort2(&entryA, &entryB, &entryC);

	cout << entryA << ", " << entryB << ", " << entryC << endl;

	return 0;
}
