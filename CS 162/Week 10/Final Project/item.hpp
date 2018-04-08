/**************************************
 * Program Name: item.hpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: item.hpp is the class specification file for the
 * 				Item class.
 *************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

class Item
{
	private:
		string name;
		bool inBag;

	public:
		Item();
		void setName(string);
		void setInBag(bool);
		string getName();
		bool getInBag();
};

#endif
