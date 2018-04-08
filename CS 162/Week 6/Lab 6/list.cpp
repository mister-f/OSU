/**************************************
 * Program Name: list.cpp
 * Name: Andrew Funk
 * Date: 11-04-17
 * Description: list.cpp is the class implementation file for the
 * 				List class. It contains the functions used to generate 
 * 				a list of nodes and to manipulate the list.
 *************************************/

#include "list.hpp"

using std::ifstream;
using std::string;
using std::vector;
using std::cin;
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

/*********************************************
 * Description: The addHead function adds a new Node and value to the 
 * 				head of the list. It takes an integer value that is 
 * 				stored in the node.
 ********************************************/

void List::addHead(int valIn)
{
	// Check if list is empty
	if (head == NULL)
	{
		// If list is empty, add a new node, pointed at by head and tail,
		// that has NULL prev and next pointers
		head = new Node(valIn, NULL, NULL);
		tail = head;
	}
	// List already has items
	else
	{
		// Set a pointer to current head
		Node* nodePtr = head;
	
		// Set head to a new node that points next to old head
		head = new Node(valIn, nodePtr, NULL);
		// Set old head prev to point to new head
		nodePtr->setPrev(head);
	}
}

/*********************************************
 * Description: The addTail function adds a new Node and value to the 
 * 				tail of the list. It takes in an integer valuer that is
 * 				stored in the node.
 ********************************************/

void List::addTail(int valIn)
{
	// Check if list is empty
	if (tail == NULL)
	{	
		// If list is empty, add a new node, pointed at by head and tail,
		// that has NULL prev and next pointers
		tail = new Node(valIn, NULL, NULL);
		head = tail;
	}
	// List already has items
	else
	{
		// Set a pointer to current tail
		Node* nodePtr = tail;
		
		// Set tail to a new node that points prev to old tail
		tail = new Node(valIn, NULL, nodePtr);
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
		printForward();
	}
}

/*********************************************
 * Description: deleteTail removes the tail element of the node list and
 * 				deletes it from memory.
 ********************************************/

void List::deleteTail()
{
	Node* nodePtr;
	
	// Check if list is empty
	if (tail == NULL)
	{
		cout << endl << "The list is empty.";
	}
	else
	{
		nodePtr = tail;
		// Check if there is only one element in the list
		if (nodePtr->getPrev() == NULL)
		{
			// Delete the node and set head and tail to NULL
			delete nodePtr;
			head = NULL;
			tail = NULL;
		}
		else
		{
			// Set tail value to previous node
			tail = tail->getPrev();
			// Set next value of new tail to NULL
			tail->setNext(NULL);
			// Delete old tail
			delete nodePtr;
		}
		printForward();
	}
}

/*********************************************
 * Description: printReverse traverses the list of nodes from tail to 
 * 				head and prints the value stored at each node.
 ********************************************/

void List::printReverse()
{
	Node* nodePtr = tail;

	cout << endl;	
	//Check if list is empty
	if (tail == NULL)
	{
		cout << "The list is empty.";
	}
	else
	{	
		// Continue printing until NULL value is reached
		while (nodePtr != NULL)
		{
			cout << nodePtr->getVal() << " ";
			// Traverse to previous node
			nodePtr = nodePtr->getPrev();
		}
	}
}

/*********************************************
 * Description: printForward traverses the list of nodes from head to
 * 				tail and prints the value stored at each node.
 ********************************************/

void List::printForward()
{
	Node* nodePtr = head;

	cout << endl;
	// Check if list is empty
	if (head == NULL)
	{
		cout << "The list is empty.";
	}
	else
	{
		// Continue printing values until NULL is reached
		while (nodePtr != NULL)
		{
			cout << nodePtr->getVal() << " ";
			// Traverse to next node
			nodePtr = nodePtr->getNext();
		}
	}
}

/*********************************************
 * Description: listMenu displays a menu for the user with a number of
 * 				options to manipulate the list.
 ********************************************/

void List::listMenu()
{
	vector<string> menuList;
	int menuChoice;
	int entryValue;
	string userEntry;

	// Create menu list vector
	menuList.push_back("Add a new node to the head;");
	menuList.push_back("Add a new node to the tail;");
	menuList.push_back("Delete from head;");
	menuList.push_back("Delete from tail;");
	menuList.push_back("Traverse the list reversely;");
	menuList.push_back("Print value at the head node;");
	menuList.push_back("Print value at the tail node;");
	menuList.push_back("Input list from file;");
	menuList.push_back("Exit.");

	Menu mainMenu("-- Choose from the following options --", menuList);

	// Continue to display menu until user exits
	while (menuChoice != 9)
	{
		// Display menu
		cout << endl;
		mainMenu.displayMenu();
		menuChoice = mainMenu.getChoice();

		// Add to head
		if (menuChoice == 1)
		{
			cout << "Please enter an integer: ";
			getline(cin, userEntry);
			entryValue = getValidInt(userEntry);
			addHead(entryValue);
			printForward();
		}
		// Add to tail
		else if (menuChoice == 2)
		{
			cout << "Please enter an integer: ";
			getline(cin, userEntry);
			entryValue = getValidInt(userEntry);
			addTail(entryValue);
			printForward();
		}
		else if (menuChoice == 3)
		{
			deleteHead();
		}
		else if (menuChoice == 4)
		{
			deleteTail();
		}
		else if (menuChoice == 5)
		{
			printReverse();
		}
		// Print the value stored at the head
		else if (menuChoice == 6)
		{
			cout << endl;
			if (head == NULL)
			{
				cout << "The list is empty.";
			}
			else
			{
				cout << head->getVal();
			}
		}
		// Print the vallue stored at the tail
		else if (menuChoice == 7)
		{
			cout << endl;
			if (tail == NULL)
			{
				cout << "The list is empty.";
			}
			else
			{
				cout << tail->getVal();
			}	
		}
		else if (menuChoice == 8)
		{
			cout << endl;
			cout << "NOTE: This will input a list of numbers";
			cout << " from a file and add it to the" << endl;
			cout << "      tail of any current list." << endl;
			fileInput();
		}
	}
}

void List::fileInput()
{
	ifstream inputFile;
	string fileName;
	int currentNumber;

	cout << endl << "Enter a file to read integers from: ";
	getline(cin, fileName);

	inputFile.open(fileName);

	if (!inputFile)
	{
		cout << endl << "File open error." << endl;
	}
	else
	{
		while (inputFile >> currentNumber)
		{
			addTail(currentNumber);
		}
	}
	
	printForward();
	inputFile.close();
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
