/**************************************
 * Program Name: node.cpp
 * Name: Andrew Funk
 * Date: 11-04-17
 * Description: node.cpp is the class implementation file for the
 * 				Node class. It contains the functions to set and 
 * 				get member node variables. 
 *************************************/

#include "node.hpp"

/************************************
 * Description: This is the constructor for a Node object. It takes in 
 * 				an integer value to store, along with pointers to the 
 * 				next and previous nodes.
 ***********************************/

Node::Node(int valIn, Node* nextIn, Node* prevIn)
{
	val = valIn;
	next = nextIn;
	prev = prevIn;
}

// Accessor
Node* Node::getNext()
{
	return next;
}

// Accessor
Node* Node::getPrev()
{
	return prev;
}

// Mutator
void Node::setNext(Node* nextIn)
{
	next = nextIn;
}

// Mutator
void Node::setPrev(Node* prevIn)
{
	prev = prevIn;
}

//Accessor
int Node::getVal()
{
	return val;
}
