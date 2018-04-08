/**************************************
 * Program Name: queue.cpp
 * Name: Andrew Funk
 * Date: 11-11-17
 * Description: queue.cpp is the class implementation file for the
 * 				Queue class. It contains the functions used to generate 
 * 				a circular linked queue of nodes and to manipulate the list.
 *************************************/

#include "queue.hpp"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/*********************************************
 * Description: This is the default constructor for the Queue object. It
 * 				sets a list head to null.
 ********************************************/

Queue::Queue()
{
	head = NULL;
}

/*********************************************
 * Description: isEmpty checks the pointer to the head of the queue and
 * 				returns a true value if it is empty, false if it has list
 * 				elements in it.
 ********************************************/

bool Queue::isEmpty()
{
	return head == NULL;
}

/*********************************************
 * Description: The addBack function adds a new QueueNode and value to the 
 * 				'end' of the list. It takes an integer value that is 
 * 				stored in the node.
 ********************************************/

void Queue::addBack(int valIn)
{
	// Check if list is empty
	if (isEmpty())
	{
		// If list is empty, add a new node, pointed at by head,
		// and that has prev and next pointers that point to itself
		head = new QueueNode(valIn, NULL, NULL);
		head->next = head;
		head->prev = head;
	}
	// List already has items
	else
	{
		// Declare a new pointer to the current head's previous node
		QueueNode* lastPtr = head->prev;
	
		// Set the element 'prev' to head as the new node
		// New node points next to head and prev to the old 'last' 
		// node
		head->prev = new QueueNode(valIn, head, lastPtr);
		// Set old 'last' node to point next to new 'last'
		lastPtr->next = head->prev;
	}
}

// Accessor function returns value at head of queue
int Queue::getFront()
{
	return head->val;
}


/*********************************************
 * Description: removeFront removes the head element of the node list,
 * 				deletes it from memory, and establishes a new head of
 * 				the linked list.
 ********************************************/

void Queue::removeFront()
{
	QueueNode* nodePtr;

	// Make sure list is not empty
	if (isEmpty())
	{
		cout << endl << "The queue is empty." << endl;
	}
	else
	{
		// Set pointer to current head
		nodePtr = head;
		// Check if there is only one element in the list
		if (nodePtr->next == head)
		{
			// delete the element and set head to NULL
			delete nodePtr;
			head = NULL;
		}
		// If there is more than one element
		else
		{
			QueueNode* lastPtr = nodePtr->prev;
			// Set head to the next node
			head = head->next;
			// Set prev value of new head to 'last' node
			head->prev = nodePtr->prev;
			// Set next value of 'last' node to new head
			lastPtr->next = head;
			// Delete old head
			delete nodePtr;
		}
	}
}

/*********************************************
 * Description: printQueue traverses the list of nodes starting from the
 * 				head and prints the value stored at each node.
 ********************************************/

void Queue::printQueue()
{
	QueueNode* nodePtr = head;

	cout << endl;
	// Check if list is empty
	if (isEmpty())
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		// Print the value at the head
		cout << nodePtr->val << " ";
		nodePtr = nodePtr->next;
		// Continue printing values until head is reached
		while (nodePtr != head)
		{
			cout << nodePtr->val << " ";
			// Traverse to next node
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

/*********************************************
 * Description: queueMenu displays a menu for the user with a number of
 * 				options to manipulate the queue.
 ********************************************/

void Queue::queueMenu()
{
	vector<string> menuList;
	int menuChoice = 0;
	int entryValue;
	string userEntry;

	// Create menu list vector
	menuList.push_back("Add a value to the back of queue;");
	menuList.push_back("Display the front value;");
	menuList.push_back("Remove the front node;");
	menuList.push_back("Display the queue's content;");
	menuList.push_back("Exit;");

	Menu mainMenu("-- Choose from the following options --", menuList);

	// Continue to display menu until user exits
	while (menuChoice != 5)
	{
		// Display menu
		mainMenu.displayMenu();
		menuChoice = mainMenu.getChoice();

		// Add to head
		if (menuChoice == 1)
		{
			cout << "Please enter an integer: ";
			getline(cin, userEntry);
			entryValue = getValidInt(userEntry);
			addBack(entryValue);
		}
		// Display front value
		else if (menuChoice == 2)
		{
			if (isEmpty())
			{
				cout << endl << "The queue is empty." << endl;
			}
			else
			{
				cout << endl << getFront() << endl;
			}
		}
		else if (menuChoice == 3)
		{
			removeFront();
		}
		else if (menuChoice == 4)
		{
			printQueue();
		}
	}
}

/*********************************************
 * Description: This is the Queue destructor. It ensures that any 
 * 				remaining queue nodes are deleted from the heap.
 ********************************************/

Queue::~Queue()
{
	QueueNode* nodePtr = head;
	QueueNode* temp = nodePtr;

	// Make sure list is not empty	
	if (!isEmpty())
	{
		// Delete the first node
		nodePtr = nodePtr->next;
		delete temp;
		// If list has more nodes, traverse and delete each one
		while (nodePtr != head)
		{
			QueueNode* toDelete = nodePtr;
			nodePtr = nodePtr->next;
			delete toDelete;
		}
	}
}
