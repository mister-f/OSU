/**************************************
 * Program Name: list.cpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: list.cpp is the class implementation file for the
 * 				List class. It contains the functions used to generate 
 * 				a list of nodes and to manipulate the list.
 *************************************/

#include "list.hpp"

using std::cout;
using std::endl;

/*********************************************
 * Description: This is the default constructor for the List object. It
 * 				sets a list head and tail to null.
 ********************************************/

List::List()
{
	head = NULL;
	tail = NULL;
}

// Accessor function
Character* List::getHeadVal()
{
	return head->getFighter();
}

// Accessor function
Node* List::getHead()
{
	return head;
}

/*********************************************
 * Description: The addTail function adds a new Node and value to the 
 * 				tail of the list. It takes in a Character pointer that is
 * 				stored in the node.
 ********************************************/

void List::addTail(Character* fighterIn)
{
	// Check if list is empty
	if (tail == NULL)
	{	
		// If list is empty, add a new node, pointed at by head and tail,
		// that has NULL prev and next pointers
		tail = new Node(fighterIn, NULL, NULL);
		head = tail;
	}
	// List already has items
	else
	{
		// Set a pointer to current tail
		Node* nodePtr = tail;
		
		// Set tail to a new node that points prev to old tail
		tail = new Node(fighterIn, NULL, nodePtr);
		// Set old tail next to point to new tail
		nodePtr->setNext(tail);
	}
}

/*********************************************
 * Description: deleteHead removes the head element of the node list and
 * 				deletes it from memory.
 ********************************************/

void List::deleteHead()
{
	Node* nodePtr;

	// Make sure list is not empty
	if (head == NULL)
	{
		cout << endl << "The list is empty.";
	}
	else
	{
		// Set pointer to current head
		nodePtr = head;
		// Check if there is only one element in the list
		if (nodePtr->getNext() == NULL)
		{
			// delete the element and set head and tail to NULL
			delete nodePtr;
			head = NULL;
			tail = NULL;
		}
		// If there is more than one element
		else
		{
			// Set head to the next node
			head = head->getNext();
			// Set prev value of new head to NULL
			head->setPrev(NULL);
			// Delete old head
			delete nodePtr;
		}
	}
}

/*********************************************
 * Description: printReverse traverses the list of nodes from tail to
 * 				head and prints the name stored at each node.
 ********************************************/

void List::printReverse()
{
	Node* nodePtr = tail;

	cout << endl;
	// Check if list is empty
	if (tail == NULL)
	{
		cout << "The list is empty.";
	}
	else
	{
		// Continue printing values until NULL is reached
		while (nodePtr != NULL)
		{
			cout << nodePtr->getFighter()->getProperName() << endl;
			// Traverse to next node
			nodePtr = nodePtr->getPrev();
		}
	}
}

/*********************************************
 * Description: This is the List destructor. It ensures that any 
 * 				remaining list nodes are deleted from the heap.
 ********************************************/

List::~List()
{
	Node* nodePtr = head;

	// If list has elements, traverse and delete each one
	while (nodePtr != NULL)
	{
		Node* toDelete = nodePtr;
		nodePtr = nodePtr->getNext();
		delete toDelete;
	}
}
