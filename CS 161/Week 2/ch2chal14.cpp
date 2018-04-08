/**************************************
 * Name: Andrew Funk
 * Date: 7-2-17
 * Description: Chapter 2, Challenge 14 
 *************************************/

#include <iostream>
using namespace std;

int main ()
{
	int playerHeight = 74;
	int playerFeet, playerInches;

	playerFeet = playerHeight / 12;
	playerInches = playerHeight % 12;

	cout << "A basketball player that is " << playerHeight;
	cout << " inches tall, is " << playerFeet << " feet, ";
	cout << playerInches << " inches tall." << endl;

	return 0;
}
