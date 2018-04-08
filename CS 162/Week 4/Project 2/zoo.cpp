/**************************************
 * Program Name: zoo.cpp
 * Name: Andrew Funk
 * Date: 10-19-17
 * Description: zoo.cpp is the class implementation file for the
 * 				Zoo class. It contains a number of functions related
 * 				to increasing and decreasing zoo size, as well as 
 * 				events occuring each day. 
 *************************************/

#include <iostream>
#include <cstdlib>
#include "zoo.hpp"
using std::cout;
using std::endl;

/************************************
 * Description: The constructor for the zoo object dynamically 
 * 				allocates three arrays in order to store the animal
 * 				objects. It also sets the initial number of animals
 * 				to zero.
 ***********************************/

Zoo::Zoo()
{
	tigers = new Tiger*[BASE_ARRAY_SIZE];
	tigerArraySize = BASE_ARRAY_SIZE;
	penguins = new Penguin*[BASE_ARRAY_SIZE];
	penguinArraySize = BASE_ARRAY_SIZE;
	turtles = new Turtle*[BASE_ARRAY_SIZE];
	turtleArraySize = BASE_ARRAY_SIZE;

	// Set initial arrays to null pointers
	for (int i = 0; i < tigerArraySize; i++)
	{
		tigers[i] = NULL;
	}
	for (int j = 0; j < penguinArraySize; j++)
	{
		penguins[j] = NULL;
	}
	for (int k = 0; k < turtleArraySize; k++)
	{
		turtles[k] = NULL;
	}
	
	// Initial number of animals is zero
	numberTigers = 0;
	numberPenguins = 0;
	numberTurtles = 0;
}

/*********************************************
 * Description: The addTiger function adds a tiger into the zoo.
 * 				it dynamically allocates a new tiger object and stores
 * 				it in the appropriate array. If the array is full
 * 				it calls a function to increase the array size.
 *******************************************/

void Zoo::addTiger(int ageIn)
{
	// Check if array is full
	if (tigerArraySize == (numberTigers))
	{
		// Increase array size
		growTigerArray();
		tigers[numberTigers] = new Tiger(ageIn);
	}
	// Add tiger if array has space
	else
	{
		tigers[numberTigers] = new Tiger(ageIn);
	}

	// Increment tiger counter
	numberTigers++;
}

/*********************************************
 * Description: The addPenguin function adds a penguin into the zoo.
 * 				it dynamically allocates a new penguin object and stores
 * 				it in the appropriate array. If the array is full
 * 				it calls a function to increase the array size.
 *******************************************/

void Zoo::addPenguin(int ageIn)
{
	// Check if array is full
	if (penguinArraySize == (numberPenguins))
	{
		// Increase array size
		growPenguinArray();
		penguins[numberPenguins] = new Penguin(ageIn);
	}
	// Add penguin if there is space
	else
	{
		penguins[numberPenguins] = new Penguin(ageIn);
	}

	// Increment penguin counter
	numberPenguins++;
}

/*********************************************
 * Description: The addTurtle function adds a turtle into the zoo.
 * 				it dynamically allocates a new turtle object and stores
 * 				it in the appropriate array. If the array is full
 * 				it calls a function to increase the array size.
 *******************************************/

void Zoo::addTurtle(int ageIn)
{
	// Check if array is full
	if (turtleArraySize == (numberTurtles))
	{
		// Increase array size
		growTurtleArray();
		turtles[numberTurtles] = new Turtle(ageIn);
	}
	// Add turtle is array has space
	else
	{
		turtles[numberTurtles] = new Turtle(ageIn);
	}

	// Increment turtle counter
	numberTurtles++;
}

/****************************************
 * Description: removeTiger is a function that removes a tiger object
 * 				from its associated array, deletes the allocated memory,
 * 				and sets the pointer in the array to null.
 ***************************************/

void Zoo::removeTiger()
{
	// Check to make sure array isn't already empty
	if (numberTigers != 0)
	{
		// Delete allocated memory
		delete tigers[numberTigers - 1];
		tigers[numberTigers - 1] = NULL;
		numberTigers--;
	}
}

/****************************************
 * Description: removePenguin is a function that removes a penguin object
 * 				from its associated array, deletes the allocated memory,
 * 				and sets the pointer in the array to null.
 ***************************************/

void Zoo::removePenguin()
{
	// Make sure array isn't empty
	if (numberPenguins != 0)
	{
		// Delete allocated memory
		delete penguins[numberPenguins - 1];
		penguins[numberPenguins - 1] = NULL;
		numberPenguins--;
	}
}

/****************************************
 * Description: removeTurtle is a function that removes a turtle object
 * 				from its associated array, deletes the allocated memory,
 * 				and sets the pointer in the array to null.
 ***************************************/

void Zoo::removeTurtle()
{
	// Make sure array isn't empty
	if (numberTurtles != 0)
	{
		// Delete allocated memory
		delete turtles[numberTurtles - 1];
		turtles[numberTurtles - 1] = NULL;
		numberTurtles--;
	}
}

// Get function
int Zoo::getNumberTigers()
{
	return numberTigers;
}

// Get function
int Zoo::getNumberPenguins()
{
	return numberPenguins;
}

// Get function
int Zoo::getNumberTurtles()
{
	return numberTurtles;
}

/**********************************
 * Description: getFeedingCost is a function that returns the total
 * 				daily cost of food for all the animals currently in 
 * 				the zoo.
 *********************************/

int Zoo::getFeedingCost()
{
	Tiger tig(0);
	Penguin pen(0);
	Turtle tur(0);
	int feedCost;
		
	feedCost = ((tig.getBaseFoodCost() * numberTigers) + 
				(pen.getBaseFoodCost() * numberPenguins) + 
				(tur.getBaseFoodCost() * numberTurtles));

	return feedCost;
}

/**********************************
 * Description: getDailyCost is a function that returns the total 
 * 				daily payoff from visitors depending on the number
 * 				of animals in the zoo.
 *********************************/

int Zoo::getDailyProfit()
{
	Tiger tig(0);
	Penguin pen(0);
	Turtle tur(0);
	int dailyPayoff;
		
	dailyPayoff = ((tig.getPayoff() * numberTigers) + 
				(pen.getPayoff() * numberPenguins) + 
				(tur.getPayoff() * numberTurtles));

	return dailyPayoff;
}

/**********************************
 * Description: randomEvent executes one of four daily random events.
 * 				Animals can die, be born, get money bonuses, or nothing 
 * 				may happen.
 ********************************/

void Zoo::randomEvent()
{
	int eventNumber;
	int dailyBonus;
	bonusProfit = 0;

	eventNumber = ((rand() % 4) + 1);

	// Remove an animal
	if (eventNumber == 1)
	{
		killAnimal();
	}
	// Tiger attendance bonus
	else if (eventNumber == 2)
	{
		// Make sure there are tigers at zoo to get bonus.
		if (numberTigers > 0)
		{
			// Random amount between 250 and 500 dollars per tiger
			dailyBonus = ((rand() % 250) + 250);
			bonusProfit = dailyBonus * numberTigers;
			cout << "Attendance is very high today! $" << dailyBonus;
			cout << " extra for every tiger!" << endl;
		}
		// Display message if no tigers exist
		else
		{
			cout << "Attendance boom today! Everyone is disappointed";
			cout << " there are no tigers." << endl;
		}
	}
	// Animals are born
	else if (eventNumber == 3)
	{
		animalBorn();
	}
	// Nothing occurs
	else
	{
		cout << "No special events today." << endl;	
	} 
}

// Get function
int Zoo::getBonusProfit()
{
	return bonusProfit;
}

/************************************
 * Description: killAnimal is used to remove a random animal from the 
 * 				zoo.
 **********************************/

void Zoo::killAnimal()
{
	int animalType;

	// Randomly choose an animal type		
	animalType = ((rand() % 3) + 1);

	// For tigers
	if (animalType == 1)
	{
		if (numberTigers == 0)
		{
			cout << "I hear the tiger fever is going around." << endl;
		}
		else 
		{
			removeTiger();
			cout << "One of your tigers is dead. RIP." << endl;
		}	
	}
	// For penguins
	else if (animalType == 2)
	{
		if (numberPenguins == 0)
		{
			cout << "It seems the penguin exhibit is empty." << endl;
		}
		else 
		{
			removePenguin();
			cout << "A penguin has died. Too bad, so sad." << endl;
		}	
	}
	// For turtles
	else if (animalType == 3)
	{
		if (numberTurtles == 0)
		{
			cout << "If you had any turtles I bet one would die." << endl;
		}
		else 
		{
			removeTurtle();
			cout << "A turtle will not come out of its shell.";
			cout << " Ever again. It's dead." << endl;
		}	
	}
}

/****************************************
 * Description: animalBorn is used to add animals into the zoo when
 * 				a random event occurs. The function checks the ages of 
 * 				the animals in the zoo to make sure they are old enough 
 * 				to breed. A random selection is made from sets of 
 * 				animals that have adult members.
 ***************************************/

void Zoo::animalBorn()
{
	int animalType;
	bool tigerCheck = false;
	bool penguinCheck = false;
	bool turtleCheck = false;

	// For loops are used to flag if adult members exist
	for (int i = 0; i < numberTigers; i++)
	{
		if (tigers[i]->getAge() >= 3)
		{
			tigerCheck = true;
		}		
	}
	for (int j = 0; j < numberPenguins; j++)
	{
		if (penguins[j]->getAge() >= 3)
		{
			penguinCheck = true;
		}	
	}
	for (int k = 0; k < numberTurtles; k++)
	{
		if (turtles[k]->getAge() >= 3)
		{
			turtleCheck = true;
		}
	}
	
	// A set of conditional statements is used to ensure that
	// a random animal group is selected from those that have 
	// adult members
	if (!tigerCheck && !penguinCheck && !turtleCheck)
	{
		cout << "No animals old enough to have babies." << endl;
	}
	else if (tigerCheck && penguinCheck && turtleCheck)
	{
		animalType = ((rand() % 3) + 1);
	}
	else if (tigerCheck && !penguinCheck && !turtleCheck)
	{
		animalType = 1;
	}
	else if (tigerCheck && penguinCheck && !turtleCheck)
	{
		animalType = ((rand() % 2) + 1);
	}
	else if (!tigerCheck && penguinCheck && !turtleCheck)
	{
		animalType = 2;
	}
	else if (!tigerCheck && !penguinCheck && turtleCheck)
	{
		animalType = 3;
	}
	else if (!tigerCheck && penguinCheck && turtleCheck)
	{
		animalType = ((rand() % 3) + 2);
	}
	else if (tigerCheck && !penguinCheck && turtleCheck)
	{
		animalType = ((rand() % 2) + 1);
		if (animalType == 2)
		{
			animalType = 3;
		}
	}
	
	// Another set of conditionals adds animals depending on the
	// random slection
	if (animalType == 1 && tigerCheck)
	{
		addTiger(0);
		cout << "A tiny baby tiger is born!" << endl;
	}
	else if (animalType == 2 && penguinCheck)
	{
		for (int x = 0; x < 5; x++)
		{
			addPenguin(0);
		}
		cout << "Five penguins have been born!" << endl;
	}
	else if (animalType == 3 && turtleCheck)
	{
		for (int y = 0; y < 10; y++)
		{
			addTurtle(0);
		}
		cout << "Ten baby turtles have been born!" << endl;
	}
}

/***********************************
 * Description: ageAnimals is a function that loops through all 
 * 				three animal arrays and ages each animal object 
 * 				by one day.
 *********************************/

void Zoo::ageAnimals()
{
	for (int i = 0; i < numberTigers; i++)
	{
		tigers[i]->ageOneDay();
	}
	for (int j = 0; j < numberPenguins; j++)
	{
		penguins[j]->ageOneDay();
	}
	for (int k = 0; k < numberTurtles; k++)
	{
		turtles[k]->ageOneDay();
	}
}

/****************************************
 * Description: growTigerArray is used to increase the size of the 
 * 				array holding the animal objects. It dynamically 
 * 				creates a array of incerased size, transfers
 * 				over the animal objects to it, and then deletes the 
 * 				old dynamically allocated memory.
 ***************************************/

void Zoo::growTigerArray()
{
	Tiger** tempArray = NULL;
	Tiger** tempPtr = NULL;

	// Create larger array
	tempArray = new Tiger*[tigerArraySize + BASE_ARRAY_SIZE];

	// Transfer values into new array, set empty slots to null pointers
	for (int i = 0; i < (tigerArraySize + BASE_ARRAY_SIZE); i++)
	{
		if (i < tigerArraySize)
		{
			tempArray[i] = tigers[i];
		}
		else
		{
			tempArray[i] = NULL;
		}
	}

	tigerArraySize += BASE_ARRAY_SIZE;
	
	// Swap the arrays that the pointers are pointing to
	tempPtr = tigers;
	tigers = tempArray;
	tempArray = tempPtr;

	// Delete old memory
	delete [] tempArray;
}

/****************************************
 * Description: growPenguinArray is used to increase the size of the 
 * 				array holding the animal objects. It dynamically 
 * 				creates a array of incerased size, transfers
 * 				over the animal objects to it, and then deletes the 
 * 				old dynamically allocated memory.
 ***************************************/

void Zoo::growPenguinArray()
{
	Penguin** tempArray = NULL;
	Penguin** tempPtr = NULL;

	// Create larger array
	tempArray = new Penguin*[penguinArraySize + BASE_ARRAY_SIZE];

	// Transfer values into new array, set empty elements to null
	for (int i = 0; i < (penguinArraySize + BASE_ARRAY_SIZE); i++)
	{
		if (i < penguinArraySize)
		{
			tempArray[i] = penguins[i];
		}
		else
		{
			tempArray[i] = NULL;
		}
	}

	penguinArraySize += BASE_ARRAY_SIZE;
	
	//Swap arrays the pointers are indicating
	tempPtr = penguins;
	penguins = tempArray;
	tempArray = tempPtr;

	// Delete old dynamic memory
	delete [] tempArray;
}

/****************************************
 * Description: growTurtleArray is used to increase the size of the 
 * 				array holding the animal objects. It dynamically 
 * 				creates a array of incerased size, transfers
 * 				over the animal objects to it, and then deletes the 
 * 				old dynamically allocated memory.
 ***************************************/

void Zoo::growTurtleArray()
{
	Turtle** tempArray = NULL;
	Turtle** tempPtr = NULL;

	// Create larger array
	tempArray = new Turtle*[turtleArraySize + BASE_ARRAY_SIZE];

	// Transfer values into new array, set empty elements to null
	for (int i = 0; i < (turtleArraySize + BASE_ARRAY_SIZE); i++)
	{
		if (i < turtleArraySize)
		{
			tempArray[i] = turtles[i];
		}
		else
		{
			tempArray[i] = NULL;
		}
	}

	turtleArraySize += BASE_ARRAY_SIZE;
	
	// Swap arrays the pointers are pointing to
	tempPtr = turtles;
	turtles = tempArray;
	tempArray = tempPtr;

	// Delete dynamically allocated memory
	delete [] tempArray;
}

/************************************
 * Description: This is the destructor for zoo objects. It is used to
 * 				free any dynamically allocated memory.
 **********************************/

Zoo::~Zoo()
{
	// Loop through each array, delete any remaining objects
	for (int i = 0; i < tigerArraySize; i++)
	{
		delete tigers[i];
	}
	for (int j = 0; j < penguinArraySize; j++)
	{
		delete penguins[j];
	}
	for (int k = 0; k < turtleArraySize; k++)
	{
		delete turtles[k];
	}
		
	// Delete the dynamically allocated arrays
	delete [] tigers;
	delete [] penguins;
	delete [] turtles;
}

