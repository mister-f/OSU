/**************************************
 * Program Name: university.cpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: university.cpp is the class implementation file for the
 * 				University class. It contains the Building and Person 
 * 				classes and uses them to construct a rudimentary 
 * 				database and menu system.
 *************************************/

#include <iostream>
#include "university.hpp"
using std::cout;
using std::endl;

/******************************
 * Description: Constructor for the University object. It clears the 
 * 				vectors used for object storage and names the school.
 *****************************/

University::University()
{
	uniName = "Oregon State University";
	buildings.clear();
	people.clear();
	menuChoice = 0;
}

/***************************
 * Description: addPerson is a simple function that takes a pointer
 * 				to a Person and adds them to the pepole vector.
 ***************************/

void University::addPerson(Person* ptrIn)
{
	people.push_back(ptrIn);
}

/***************************
 * Description: addBuilding takes a Building object and adds it to the 
 * 				buildings vector.
 **************************/

void University::addBuilding(Building buildingIn)
{
	buildings.push_back(buildingIn);
}

/******************************
 * Description: displayMenu is used to display the main menu for 
 * 				university information system. It uses the Menu class
 * 				to create the menu and calls other functions depending 
 * 				on user choice. It continues to be displayed until user
 * 				chooses to exit.
 *****************************/

void University::displayMenu()
{
	//Create menu choices
	menuList.clear();
	menuList.push_back("Print information about buildings");
	menuList.push_back("Print information about people");
	menuList.push_back("Choose a person to do work");
	menuList.push_back("Exit");
	
	Menu mainMenu("--OSU Information System--", menuList);
	
	// Continue to display menu until user exits
	while (menuChoice != 4)
	{
		mainMenu.displayMenu();
		menuChoice = mainMenu.getChoice();
		
		if (menuChoice == 1)
		{
			printBuildings();
		}
		else if (menuChoice == 2)
		{
			printPeople();
		}
		else if (menuChoice == 3)
		{
			doWork();
		}
	}
}
		
/*****************************
 * Description: printBuildings loops through the buildings vector
 * 				and prints out all the stored information.
 *****************************/

void University::printBuildings()
{
	cout << endl << "--OSU Buildings-";	

	// Loop through whole vector
	for (unsigned int i = 0; i < buildings.size(); i++)
	{
		// Display info using get functions
		cout << endl << buildings[i].getName() << endl;
		cout << buildings[i].getSize() << " Sq. Ft." << endl;
		cout << buildings[i].getAddress() << endl;
	}
}

/****************************
 * Description: printPeople loops through the people vector and prints
 * 				out information that is stored for everyone.
 ***************************/

void University::printPeople()
{
	cout << endl << "--Who's On Campus?--";

	// Loop through whole vector
	for (unsigned int i = 0; i < people.size(); i++)
	{
		// Display info using get functions
		cout << endl << people[i]->getName() << endl;
		cout << "Age: " << people[i]->getAge() << endl;
		cout << people[i]->getLabel() << ": ";
		cout << people[i]->getNumber() << endl;
	}
}

/****************************
 * Description: doWork creates a menu of all the names of the stored
 * 				Person objects and lets the user choose one. It then 
 * 				exectes the do_work function on the selected object.
 ***************************/

void University::doWork()
{
	vector<string> menuNames;
	int workerChoice;	

	// Loop through people vector and store names in another
	// vector to pass to Menu object
	for (unsigned int i = 0; i < people.size(); i++)
	{
		menuNames.push_back(people[i]->getName());
	}

	// Create a new Menu object of names and get a selection
	Menu workMenu("--Worker List--", menuNames);
	workMenu.displayMenu();
	workerChoice = workMenu.getChoice();
	
	// Perform do_work function on selection
	people[workerChoice - 1]->do_work();
}

//Destructor
University::~University()
{
}
