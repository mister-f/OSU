/**************************************
 * Name: Andrew Funk
 * Date: 7-2-17
 * Description: Chapter 2, Challenge 3 
 *************************************/


#include <iostream>
using namespace std;

int main ()
{
	float purchaseAmount = 95.00;
	float stateTax = 0.065;
	float countyTax = 0.02;
	float purchaseStateTax = purchaseAmount * stateTax;
	float purchaseCountyTax = purchaseAmount * countyTax;

	cout << "Purchase price: " << purchaseAmount << endl;
	cout << "State tax: " << purchaseStateTax << endl;
	cout << "County tax: " << purchaseCountyTax << endl;
	
	return 0;
}
