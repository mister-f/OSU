/*********************************
** Author: Andrew Funk (copied from Assignment 1 instructions)
** Date: 6-29-17
** Description: Asks for and returns your favorite animal
*********************************/

#include <iostream>
#include <string>

// a simple example program

int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

	return 0;
} 
