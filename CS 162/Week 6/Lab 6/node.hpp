/**************************************
 * Program Name: node.hpp
 * Name: Andrew Funk
 * Date: 11-04-17
 * Description: node.hpp is the class specification file for the
 * 				Node class. It describes the three member variables 
 * 				and the member functions.
 *************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

class Node
{
	private:
		Node* next;
		Node* prev;
		int val;

	public:
		Node(int, Node*, Node*);
		Node* getNext();
		Node* getPrev();
		int getVal();
		void setNext(Node*);
		void setPrev(Node*);
};

#endif
