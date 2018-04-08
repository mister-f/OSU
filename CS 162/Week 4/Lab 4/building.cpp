/**************************************
 * Program Name: building.cpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: building.cpp is the class implementation file for the
 * 				Building class.	It is very basic, with the only member 
 * 				functions being accessors.
 *************************************/

#include "building.hpp"

/*************************
 * Description: This is the constructor for the building object. It
 * 				take in three parameters to construct the object.
 ************************/

Building::Building(string nameIn, int sizeIn, string addressIn)
{
	name = nameIn;
	size = sizeIn;
	address = addressIn;
}

// Get function
string Building::getName()
{
	return name;
}

// Get function
int Building::getSize()
{
	return size;
}

// Get function
string Building::getAddress()
{
	return address;
}

// Destructor
Building::~Building()
{
}
