/**************************************
 * Program Name: character.hpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: character.hpp is the class specification file for the
 * 				Character class as well as the derived fighting
 * 				subclasses. The classes exhibit polymorphic behavior.
 *************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using std::string;

class Character
{
	protected:
		string name;
		int HP;
		int armor;

	public:
		int getArmor();
		int getHP();
		string getName();
		void setName(string);
		// Virtual functions for polymorphism
		virtual int attack() = 0;
		virtual bool defend(int) = 0;
		virtual ~Character();
};

// Inherited class
class Barbarian : public Character
{
	public:
		Barbarian();
		virtual int attack();
		virtual bool defend(int);
		virtual ~Barbarian();
};

// Inherited class
class Vampire : public Character
{
	public:
		Vampire();
		virtual int attack();
		virtual bool defend(int);
		virtual ~Vampire();
};

// Inherited class
class BlueMen : public Character
{
	public:
		BlueMen();
		virtual int attack();
		virtual bool defend(int);
		virtual ~BlueMen();
};

// Inherited class
class Medusa : public Character
{
	public:
		Medusa();
		virtual int attack();
		virtual bool defend(int);
		virtual ~Medusa();
};

// Inherited class
class HarryPotter : public Character
{
	private:
		// Boolean value to track HOGWARTS ability
		bool firstLife;	

	public:
		HarryPotter();
		virtual int attack();
		virtual bool defend(int);
		virtual ~HarryPotter();
};

#endif
