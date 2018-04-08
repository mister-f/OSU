/**************************************
 * Program Name: space.hpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: space.hpp is the class specification file for the
 * 				Space class and associated dervied classes.
 *************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <cstddef>
#include <string>
#include <vector>
#include "character.hpp"
#include "item.hpp"
#include "menu.hpp"
#include "getValidInput.hpp"

using std::string;

class Space
{
	protected:
		Space* up;
		Space* down;
		Space* left;
		Space* right;
		string location;
		string spaceDescrip;

	public:
		void setUp(Space*);
		void setDown(Space*);
		void setLeft(Space*);
		void setRight(Space*);
		void setLocation(string);
		void setSpaceDescrip(string);
		Space* getUp();
		Space* getDown();
		Space* getLeft();
		Space* getRight();
		string getDescrip();
		string getLocation();
		virtual int showMenu() = 0;
		virtual ~Space();
};

class Hel : public Space
{
	public:
		Hel();
		virtual int showMenu();
		virtual ~Hel();
};

class Trunk : public Space
{
	public:
		Trunk();
		virtual int showMenu();
		virtual ~Trunk();
};

class Nilfheim : public Space
{
	public:
		Nilfheim();
		virtual int showMenu();
		virtual ~Nilfheim();
};

class Jotunheim : public Space
{
	private:
		bool itemPresent;

	public:
		Jotunheim();
		void setItemPresent(bool);
		bool getItemPresent();
		virtual int showMenu();
		virtual ~Jotunheim();
};

class Midgard : public Space
{
	private:
		bool itemPresent;

	public:
		Midgard();
		void setItemPresent(bool);
		bool getItemPresent();
		virtual int showMenu();
		virtual ~Midgard();
};

class Vanaheim : public Space
{
	public:
		Vanaheim();
		virtual int showMenu();
		virtual ~Vanaheim();
};

class Asgard : public Space
{
	public:
		Asgard();
		virtual int showMenu();
		virtual ~Asgard();
};

#endif
