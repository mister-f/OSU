/**************************************
 * Program Name: queue.hpp
 * Name: Andrew Funk
 * Date: 11-11-17
 * Description: queue.hpp is the class specification file for the
 * 				Queue class. It describes the member variables 
 * 				and the member functions.
 *************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "getValidInput.hpp"
#include "menu.hpp"

class Queue
{
	private:
		// QueueNode struct used to build each node
		struct QueueNode
		{
			int val;
			QueueNode* next;
			QueueNode* prev;
			// QueueNode constructor
			QueueNode(int valIn, QueueNode* nextIn, 
				QueueNode* prevIn)
			{
				val = valIn;
				next = nextIn;
				prev = prevIn;
			}
		};			
		QueueNode* head;

	public:
		Queue();
		bool isEmpty();
		void addBack(int);
		int getFront();
		void removeFront();
		void printQueue();
		void queueMenu();
		~Queue();
};

#endif
