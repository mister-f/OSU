/**************************************
 * Program Name: container.cpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: container.cpp is the class implmentation file for the
 * 				Container class.
 *************************************/

#include "container.hpp"

using std::cout;
using std::endl;

/*******************************
 * Description: The default constructor for the Container class. It sets 
 * 				the container size to 0. 
 ******************************/

Container::Container()
{
	bagSize = 0;
}

/*******************************
 * Description: useBagMenu is a function that constructs a menu based
 * 				on the current items in the container. It then gets a 
 * 				selection of one of those items and returns a pointer 
 * 				to it.
 ******************************/

Item* Container::useBagMenu()
{
	vector<string> menuItems;
	int selection;

	// Check if bag is empty, return NULL if it is.
	if (bagSize == 0)
	{
		cout << endl << "Your satchel is empty." << endl;
		return NULL;
	}
	// Bag has items
	else
	{
		// Loop through items in bag and put them in a Menu vector
		for (int i = 0; i < bagSize; i++)
		{
			menuItems.push_back(bag.at(i)->getName());
		}
	
		// Finish creating and display menu of items in bag
		menuItems.push_back("Close satchel.");	
		Menu bagMenu("What item would you like to use?", menuItems);
		bagMenu.displayMenu();
		selection = bagMenu.getChoice();
		// Check if user chose to close bag
		if (selection == (bagSize + 1))
		{
			return NULL;
		}
		// Return pointer to selected item
		else
		{
			return bag[selection - 1];
		}
	}
}

/******************************
 * Description: putInBag is a function that takes a pointer to an Item
 * 				and adds it to the vector that makes up the Items in the
 * 				container.
 *****************************/

void Container::putInBag(Item* itemIn)
{
	// Put Item into vector
	bag.push_back(itemIn);
	// Increase tracked bag size
	bagSize++;
	// Inform user that item was added
	cout << endl;
	cout << itemIn->getName() << " has been added to your satchel.";
	cout << endl;
}

/*******************************
 * Description: removeFromBag is a function that takes a pointer to an 
 * 				Item, and then removes that Item from the container.
 ******************************/

void Container::removeFromBag(Item* itemIn)
{
	vector<Item*> tempVector;
	
	// Loop through container and add items to temporary vector
	for (int i = 0; i < bagSize; i++)
	{
		// Conditional to check and make sure item being removed isn't
		// added to temporary vector
		if (bag[i] != itemIn)
		{
			tempVector.push_back(bag.at(i));
		}
	}
	// Reduce tracked bag size
	bagSize--;	

	// Save temporary vector as new bag
	bag.clear();
	bag = tempVector;
}
