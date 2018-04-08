/**************************************
 * Program Name: container.hpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: container.hpp is the class specification file for the
 * 				container class.
 *************************************/

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"
#include "menu.hpp"
#include "getValidInput.hpp"

using std::string;
using std::vector;

class Container
{
	private:
		vector<Item*> bag;
		int bagSize;

	public:
		Container();
		Item* useBagMenu();
		void putInBag(Item*);
		void removeFromBag(Item*);
};

#endif
