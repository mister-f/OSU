/**************************************
 * Program Name: list.hpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: list.hpp is the class specification file for the
 * 				List class. It describes the member variables 
 * 				and the member functions.
 *************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "node.hpp"

class List
{
	private:
		Node* head;
		Node* tail;

	public:
		List();
		Character* getHeadVal();
		Node* getHead();
		void addTail(Character*);
		void deleteHead();
		void printReverse();
		~List();
};

#endif
