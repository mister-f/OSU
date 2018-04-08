/**************************************
 * Program Name: character.hpp
 * Name: Andrew Funk
 * Date: 11-17-17
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
		string properName;
		int HP;
		int maxHP;
		int armor;
		bool dead;

	public:
		int getArmor();
		int getHP();
		int getMaxHP();
		string getName();
		string getProperName();
		void setHP(int);
		void setName(string);
		void setProperName(string);
		bool isDead();
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
