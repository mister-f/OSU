/**************************************
 * Program Name: node.hpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: node.hpp is the class specification file for the
 * 				Node class. It describes the three member variables 
 * 				and the member functions.
 *************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
#include "character.hpp"

class Node
{
	private:
		Node* next;
		Node* prev;
		Character* fighter;

	public:
		Node(Character*, Node*, Node*);
		Node* getNext();
		Node* getPrev();
		Character* getFighter();
		void setNext(Node*);
		void setPrev(Node*);
};

#endif
