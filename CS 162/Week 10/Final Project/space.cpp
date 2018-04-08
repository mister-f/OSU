/**************************************
 * Program Name: space.cpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: space.cpp is the class implementation file for the
 * 				Space class and associated dervied classes.
 *************************************/

#include "space.hpp"

using std::vector;

// Set function
void Space::setUp(Space* upIn)
{
	up = upIn;
}

// Set function
void Space::setDown(Space* downIn)
{
	down = downIn;
}

// Set function
void Space::setLeft(Space* leftIn)
{
	left = leftIn;
}

// Set function
void Space::setRight(Space* rightIn)
{
	right = rightIn;
}

// Set function
void Space::setLocation(string locationIn)
{
	location = locationIn;
}

// Set function
void Space::setSpaceDescrip(string descripIn)
{
	spaceDescrip = descripIn;
}

// Get function
Space* Space::getUp()
{
	return up;
}

// Get function
Space* Space::getDown()
{
	return down;
}

// Get function
Space* Space::getLeft()
{
	return left;
}

// Get function
Space* Space::getRight()
{
	return right;
}

// Get function
string Space::getDescrip()
{
	return spaceDescrip;
}

// Get function
string Space::getLocation()
{
	return location;
}

// Destructor
Space::~Space() {}

/******************************
 * Description: This is a default constructor that sets unused 
 * 				pointers to NULL.
 *****************************/

Hel::Hel()
{
	left = NULL;
	right = NULL;
	down = NULL;	
}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Hel::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go up.");
	menuItems.push_back("Open satchel.");
	menuItems.push_back("Talk to Thor.");

	Menu helMenu("-- Choose an action --", menuItems);
	helMenu.displayMenu();
	menuChoice = helMenu.getChoice();

	if (menuChoice == 1)
	{
		return 1;
	}
	else if (menuChoice == 2)
	{
		return 5;
	}
	else
	{
		return 6;
	}
}

// Destructor
Hel::~Hel() {}

// Constructor
Trunk::Trunk() {}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Trunk::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go up.");
	menuItems.push_back("Go down.");
	menuItems.push_back("Go left.");
	menuItems.push_back("Go right.");
	menuItems.push_back("Open satchel.");

	Menu trunkMenu("-- Choose an action --", menuItems);
	trunkMenu.displayMenu();
	menuChoice = trunkMenu.getChoice();

	if (menuChoice == 1)
	{
		return 1;
	}
	else if (menuChoice == 2)
	{
		return 2;
	}
	else if (menuChoice == 3)
	{
		return 3;
	}
	else if (menuChoice == 4)
	{
		return 4;
	}
	else
	{
		return 5;
	}
}

// Destructor
Trunk::~Trunk() {}

/******************************
 * Description: This is a default constructor that sets unused 
 * 				pointers to NULL.
 *****************************/

Nilfheim::Nilfheim()
{
	up = NULL;
	down = NULL;
	left = NULL;
}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Nilfheim::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go right.");
	menuItems.push_back("Open satchel.");
	menuItems.push_back("Talk to Freya.");

	Menu helMenu("-- Choose an action --", menuItems);
	helMenu.displayMenu();
	menuChoice = helMenu.getChoice();

	if (menuChoice == 1)
	{
		return 4;
	}
	else if (menuChoice == 2)
	{
		return 5;
	}
	else
	{
		return 8;
	}
}

// Destructor
Nilfheim::~Nilfheim() {}

/******************************
 * Description: This is a default constructor that sets unused 
 * 				pointers to NULL.
 *****************************/

Jotunheim::Jotunheim()
{
	up = NULL;
	down = NULL;
	right = NULL;
	itemPresent = true;
}

// Set function
void Jotunheim::setItemPresent(bool statusIn)
{
	itemPresent = statusIn;
}

// Get function
bool Jotunheim::getItemPresent()
{
	return itemPresent;
}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Jotunheim::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go left.");
	menuItems.push_back("Open satchel.");
	// Only add option to menu if item wasn't already picked up
	if (itemPresent)
	{
		menuItems.push_back("Pick up Gungnir.");
	}

	Menu jotunMenu("-- Choose an action --", menuItems);
	jotunMenu.displayMenu();
	menuChoice = jotunMenu.getChoice();

	if (menuChoice == 1)
	{
		return 3;
	}
	else if (menuChoice == 2)
	{
		return 5;
	}
	else
	{
		return 11;
	}
}

// Destructor
Jotunheim::~Jotunheim() {}

/******************************
 * Description: This is a default constructor that sets unused 
 * 				pointers to NULL.
 *****************************/

Midgard::Midgard()
{
	up = NULL;
	down = NULL;
	left = NULL;
	itemPresent = true;
}

// Set function
void Midgard::setItemPresent(bool statusIn)
{
	itemPresent = statusIn;
}

// Get function
bool Midgard::getItemPresent()
{
	return itemPresent;
}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Midgard::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go right.");
	menuItems.push_back("Open satchel.");
	// Only add option to menu if item hasn't been picked up 
	if (itemPresent)
	{
		menuItems.push_back("Pick up acorn.");
	}

	Menu midgardMenu("-- Choose an action --", menuItems);
	midgardMenu.displayMenu();
	menuChoice = midgardMenu.getChoice();

	if (menuChoice == 1)
	{
		return 4;
	}
	else if (menuChoice == 2)
	{
		return 5;
	}
	else
	{
		return 10;
	}
}

// Destructor
Midgard::~Midgard() {}

/******************************
 * Description: This is a default constructor that sets unused 
 * 				pointers to NULL.
 *****************************/

Vanaheim::Vanaheim()
{
	up = NULL;
	down = NULL;
	right = NULL;
}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Vanaheim::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go left.");
	menuItems.push_back("Open satchel.");
	menuItems.push_back("Talk to Loki.");

	Menu vanaMenu("-- Choose an action --", menuItems);
	vanaMenu.displayMenu();
	menuChoice = vanaMenu.getChoice();

	if (menuChoice == 1)
	{
		return 3;
	}
	else if (menuChoice == 2)
	{
		return 5;
	}
	else
	{
		return 9;
	}
}

// Destructor
Vanaheim::~Vanaheim() {}

/******************************
 * Description: This is a default constructor that sets unused 
 * 				pointers to NULL.
 *****************************/

Asgard::Asgard()
{
	up = NULL;
	right = NULL;
	left = NULL;
}

/*******************************
 * Description: showMenu is a function that creates a menu for the
 * 				given space, displays the menu, and then returns 
 * 				an integer based upon the user's selection.
 ******************************/

int Asgard::showMenu()
{
	vector<string> menuItems;
	int menuChoice;

	menuItems.push_back("Go down.");
	menuItems.push_back("Open satchel.");
	menuItems.push_back("Talk to Odin.");

	Menu asgardMenu("-- Choose an action --", menuItems);
	asgardMenu.displayMenu();
	menuChoice = asgardMenu.getChoice();

	if (menuChoice == 1)
	{
		return 2;
	}
	else if (menuChoice == 2)
	{
		return 5;
	}
	else 
	{
		return 7;
	}
}

// Destructor
Asgard::~Asgard() {}
