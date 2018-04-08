/**************************************
 * Program Name: mainQueue.cpp
 * Name: Andrew Funk
 * Date: 11-11-17
 * Description: mainQueue just conatins the main function used to create
 * 				a queue object. It then calls the queue object member 
 * 				function to display the menu that manipulates the queue. 
 *************************************/

#include "queue.hpp"

int main ()
{
	Queue newQueue;

	newQueue.queueMenu();

	return 0;
}
