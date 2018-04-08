/**************************************
 * Program Name: stlFunctions.cpp
 * Name: Andrew Funk
 * Date: 11-25-17
 * Description: stlFunctions.cpp is an implementation file for helper 
 * 				functions that make use of the STL.
 *************************************/

#include "stlFunctions.hpp"

using std::string;
using std::cout;
using std::endl;
using std::queue;
using std::stack;

/*************************************
 * Description: bufferQueue is a function that takes three parameters,
 * 				a number of rounds, a percentage of time to add to the 
 * 				buffer queue, and a percentage of time to remove a number
 * 				from the queue. It generates a random number to add to the 
 * 				queue and then prints out the queue along with the size 
 * 				and the average buffer length.
 ************************************/

void bufferQueue(int rounds, int addPct, int remPct)
{
	double avgLength = 0.0;
	int randomNumber;
	int randomAdd;
	int randomRem;
	queue<int> bufferQueue;
	queue<int> printQueue;

	//Run for the number of rounds chosen by user
	for (int i = 0; i < rounds; i++)
	{
		// Generate random numbers to either add or compare to percentages
		randomNumber = ((rand() % 1000) + 1);
		randomAdd = ((rand() % 100) + 1);
		randomRem = ((rand() % 100) + 1);

		// Add number to queue if random percent is less than user's
		if (randomAdd <= addPct)
		{
			bufferQueue.push(randomNumber);
		}
		// Remove number from queue if random percent is less than user's
		// and queue is not already empty
		if (randomRem <= remPct && !bufferQueue.empty())
		{
			bufferQueue.pop();
		}

		// Calculate new average length
		avgLength = ((avgLength * i) + bufferQueue.size()) / (i + 1);
		
		// Print info for each round
		cout << endl << "-- Round " << i + 1 << " --" << endl;
		// Print if buffer is empty
		if (bufferQueue.empty())
		{
			cout << "The buffer is empty.";
		}
		// Print values in buffer if not empty
		else
		{
			// Make copy of queue for printing
			printQueue = bufferQueue;
			cout << "Values in buffer:" << endl;
			// Print and remove values until copied queue is empty
			while (!printQueue.empty())
			{
				cout << printQueue.front() << " ";
				printQueue.pop();
			}
		}
		// Print buffer info
		cout << endl << "Buffer length: " << bufferQueue.size(); 
		cout << endl << "Average buffer length: " << avgLength << endl;
 	}
}

/********************************
 * Description: palindrome is a function that takes a string as a 
 * 				parameter. It copies each character of the string into 
 * 				a stack. It then concatenates each character back onto the
 * 				original string and forms a palindrome. This palindrome is
 * 				displayed back to the user.
 ********************************/

void palindrome(string phrase)
{
	stack<char> letterStack;
	
	// Fill stack with letters from the string
	for (unsigned int i = 0; i < phrase.length(); i++)
	{
		letterStack.push(phrase[i]);
	}

	// If the stack is not empty, add each letter back to the string and
	// remove that letter from the stack
	while (!letterStack.empty())
	{
		phrase += letterStack.top();
		letterStack.pop();
	}
	
	// Print resultant palindrome to user
	cout << endl << "The palindrome of your string is: " << endl;
	cout << phrase << endl;
}
