/**************************************
 * Program Name: building.hpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: building.hpp is the class specification file for the
 * 				Building class. It describes the three member variables 
 * 				and the member functions.
 *************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
using std::string;

class Building
{
	private:
		string name;
		int size;
		string address;

	public:
		Building(string, int, string);
		string getName();
		int getSize();
		string getAddress();
		~Building();
};

#endif
