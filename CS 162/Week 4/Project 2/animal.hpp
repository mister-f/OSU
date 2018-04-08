/**************************************
 * Program Name: animal.hpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: animal.hpp is the class specification file for the
 * 				Animal class and associated subclasses. It contains 
 * 				the delcarations for the member variables and functions 
 * 				of the Zoo, Tiger, Penguin, and Turtle classes.
 *************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age;
		int cost;
		int numberOfBabies;
		int baseFoodCost;
		int payoff;
		static const int BASE_COST = 10;
		static const int TIGER_COST = 10000;
		static const int PENGUIN_COST = 1000;
		static const int TURTLE_COST = 100;

	public:
		Animal();
		void increaseAge();
		int getAge();
		int getCost();
		int getNumberOfBabies();
		int getBaseFoodCost();
		int getPayoff();
		~Animal();
};

// Derived class
class Tiger : public Animal
{
	public:
		Tiger(int);
		void ageOneDay();
		~Tiger();
};

// Derived class
class Penguin : public Animal
{
	public:
		Penguin(int);
		void ageOneDay();
		~Penguin();
};

// Derived class
class Turtle : public Animal
{
	public:
		Turtle(int);
		void ageOneDay();
		~Turtle();
};

#endif
