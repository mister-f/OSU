/**************************************
 * Program Name: zoo.hpp
 * Name: Andrew Funk
 * Date: 10-15-17
 * Description: zoo.hpp is the class specification file for the
 * 				Zoo class. It contains the delcarations for the 
 * 				member variables and functions of the Zoo class.
 *************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"

class Zoo
{
	private:
		Tiger** tigers;
		Penguin** penguins;
		Turtle** turtles;
		int bonusProfit;
		int numberTigers;
		int numberPenguins;
		int numberTurtles;
		int tigerArraySize;
		int penguinArraySize;
		int turtleArraySize;

		static const int STARTING_BANK = 100000;
		static const int BASE_ARRAY_SIZE = 10;		
	
	public:
		Zoo();
		void addTiger(int);
		void addPenguin(int);
		void addTurtle(int);
		void removeTiger();
		void removePenguin();
		void removeTurtle();
		int getNumberTigers();
		int getNumberPenguins();
		int getNumberTurtles();
		int getFeedingCost();
		int getDailyProfit();
		void randomEvent();
		int getBonusProfit();
		void killAnimal();
		void animalBorn();
		void ageAnimals();
		void growTigerArray();
		void growPenguinArray();
		void growTurtleArray();
		~Zoo();
};

#endif
