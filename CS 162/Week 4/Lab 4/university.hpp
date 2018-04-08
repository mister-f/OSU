/**************************************
 * Program Name: university.hpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: university.hpp is the class specification file for the
 * 				University class. It contains the declarations for the
 * 				class member variables and functions.
 *************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <string>
#include <vector>
#include "building.hpp"
#include "person.hpp"
#include "menu.hpp"
using std::string;
using std::vector;

class University
{
	private:
		vector<Building> buildings;
		vector<Person*> people;
		string uniName;
		vector<string> menuList;
		int menuChoice;
		string userEntry;

	public:
		University();
		void addPerson(Person*);
		void addBuilding(Building);
		void displayMenu();
		void printBuildings();
		void printPeople();
		void doWork();
		~University();
};

#endif
