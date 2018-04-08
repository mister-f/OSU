/**************************************
 * Program Name: list.hpp
 * Name: Andrew Funk
 * Date: 11-04-17
 * Description: list.hpp is the class specification file for the
 * 				List class. It describes the member variables 
 * 				and the member functions.
 *************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "node.hpp"
#include "getValidInput.hpp"
#include "menu.hpp"

class List
{
	private:
		Node* head;
		Node* tail;

	public:
		List();
		void addHead(int);
		void addTail(int);
		void deleteHead();
		void deleteTail();
		void printReverse();
		void printForward();
		void listMenu();
		void fileInput();
		~List();
};

#endif
