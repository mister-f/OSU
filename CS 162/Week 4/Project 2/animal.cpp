/**************************************
 * Program Name: animal.cpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: animal.cpp is the class implementation file for the
 * 				Animal class and associated subclasses. It contains 
 * 				several accessor functions, as well as constructors
 * 				and other functions to manipulate animal age.
 *************************************/

#include "animal.hpp"

// Base class constructor
Animal::Animal()
{
}

/********************************
 * Description: increaseAge increments the age of an animal object
 * 				by one day.
 ******************************/

void Animal::increaseAge()
{
	age++;
}

// Get function
int Animal::getAge()
{
	return age;
}

// Get function
int Animal::getCost()
{
	return cost;
}

// Get function
int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

// Get function
int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

// Get function
int Animal::getPayoff()
{
	return payoff;
}

// Destructor
Animal::~Animal()
{
}

/************************************
 * Description: This is the constructor for the tiger object. It 
 * 				can be used to create Tiger objects of different ages.
 ***********************************/

Tiger::Tiger(int ageIn)
{
	age = ageIn;
	cost = TIGER_COST;
	numberOfBabies = 1;
	baseFoodCost = 5 * BASE_COST;
	payoff = 0.2 * TIGER_COST;
}

/***********************************
 * Description: This function incrememnts a tiger's age by one day.
 **********************************/

void Tiger::ageOneDay()
{
	age++;
}

// Destructor
Tiger::~Tiger()
{
}

/************************************
 * Description: This is the constructor for the Penguin object. It 
 * 				can be used to create Penguin objects of different ages.
 ***********************************/

Penguin::Penguin(int ageIn)
{
	age = ageIn;
	cost = PENGUIN_COST;
	numberOfBabies = 5;
	baseFoodCost = BASE_COST;
	payoff = 0.1 * PENGUIN_COST;
}

/***********************************
 * Description: This function incrememnts a penguin's age by one day.
 **********************************/

void Penguin::ageOneDay()
{
	age++;
}

// Destructor
Penguin::~Penguin()
{
}

/************************************
 * Description: This is the constructor for the Turtle object. It 
 * 				can be used to create Turtle objects of different ages.
 ***********************************/

Turtle::Turtle(int ageIn)
{
	age = ageIn;
	cost = TURTLE_COST;
	numberOfBabies = 10;
	baseFoodCost = BASE_COST;
	payoff = 0.05 * TURTLE_COST;
}

/***********************************
 * Description: This function incrememnts a turtle's age by one day.
 **********************************/

void Turtle::ageOneDay()
{
	age++;
}

// Destructor
Turtle::~Turtle()
{
}
