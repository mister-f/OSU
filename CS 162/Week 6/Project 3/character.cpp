/**************************************
 * Program Name: character.cpp
 * Name: Andrew Funk
 * Date: 11-03-17
 * Description: character.cpp is the class implementation file for the
 * 				Character class as well as the derived fighting
 * 				subclasses. The classes exhibit polymorphic behavior.
 *************************************/

#include <iostream>
#include "diceRoll.hpp"
#include "character.hpp"

using std::string;
using std::cout;
using std::endl;

// Accessor function
int Character::getArmor()
{
	return armor;
}

// Accessor function
int Character::getHP()
{
	return HP;
}

// Accessor function
string Character::getName()
{
	return name;
}

// Mutator function
void Character::setName(string nameIn)
{
	name = nameIn;
}

// Destructor
Character::~Character(){}

/********************************************
 * Description: This is the default constructor for the Barbarian 
 * 				class.  
 *******************************************/

Barbarian::Barbarian()
{
	name = "Barbarian";
	HP = 12;
	armor = 0;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice, prints the resulting total, and returns the 
 * 				amount as an integer.
 *******************************************/

int Barbarian::attack()
{
	int roll;
	
	// diceRoll function used to roll 2d6
	roll = diceRoll(2, 6);
	
	cout << name << " has an attack of " << roll << "." << endl;	

	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The results of the 
 * 				fight are then displayed to the user, along with the 
 * 				Barbarian's new strength and whether it died. The function
 * 				returns a boolean value: true if the character is still
 * 				alive, and false if dead.
 *******************************************/

bool Barbarian::defend(int attackIn)
{
	bool alive = true;
	int damage;
	int defendRoll;

	//Use diceRoll function to roll 2d6
	defendRoll = diceRoll(2, 6);
	//Calculate damage
	damage = attackIn - defendRoll - armor;
	//If damage is negative, set damage to 0
	if (damage < 0)
	{
		damage = 0;
	}
	
	//Calculate new strength
	HP -= damage;

	//Print results to screen
	cout << name << " has a defense of " << defendRoll << "." << endl;
	cout << "Damage calculation: " << attackIn << " - ";
	cout << defendRoll << " - " << armor << " = " << damage << endl;
	
	//Check if dead, print if it is, and return 'false' alive flag
	if (HP <= 0)
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		cout << endl << name << " has died!" << endl;
		alive = false;
		return alive;
	}	
	//Character is still alive
	else
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		return alive;
	}
}

// Destructor	
Barbarian::~Barbarian(){}

/********************************************
 * Description: This is the default constructor for the Vampire
 * 				class. 
 *******************************************/

Vampire::Vampire()
{
	name = "Vampire";
	HP = 18;
	armor = 1;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice, prints the resulting total, and returns the 
 * 				amount as an integer.
 *******************************************/

int Vampire::attack()
{
	int roll;
	
	//diceRoll used to get 1d12
	roll = diceRoll(1, 12);
	
	cout << name << " has an attack of " << roll << "." << endl;	

	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The results of the 
 * 				fight are then displayed to the user, along with the 
 * 				Vampire's new strength and whether it died. The function
 * 				returns a boolean value: true if the character is still
 * 				alive, and false if dead. It also determines whether
 * 				the CHARM ability is triggered.
 *******************************************/

bool Vampire::defend(int attackIn)
{
	bool alive = true;
	int damage;
	int defendRoll;
	int charm;

	// 50% chance of CHARM calculated
	charm = ((rand() % 2) + 1);

	// Check if CHARM is triggered, no attack lands if it is
	if (charm == 1)
	{
		cout << name << " has used CHARM. Attack failed!" << endl;
	}
	// If CHARM not triggered, get normal damage
	else
	{
		// Use diceRoll to determine 1d6
		defendRoll = diceRoll(1, 6);
		// Calculate damage
		damage = attackIn - defendRoll - armor;
		// Reset damage to zero if it is negative
		if (damage < 0)
		{
			damage = 0;
		}
	
		// Set new strength
		HP -= damage;

		// Print results
		cout << name << " has a defense of " << defendRoll << "." << endl;
		cout << "Damage calculation: " << attackIn << " - ";
		cout << defendRoll << " - " << armor << " = " << damage << endl;
	}

	// Check if dead
	if (HP <= 0)
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		cout << endl << name << " has died!" << endl;
		alive = false;
		return alive;
	}	
	// If alive, print new strength
	else
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		return alive;
	}
}

//Destructor
Vampire::~Vampire(){}

/********************************************
 * Description: This is the default constructor for the BlueMen 
 * 				class. 
 *******************************************/

BlueMen::BlueMen()
{
	name = "Blue Men";
	HP = 12;
	armor = 3;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice, prints the resulting total, and returns the 
 * 				amount as an integer.
 *******************************************/

int BlueMen::attack()
{
	int roll;
	
	//diceRoll function used to get 2d10 roll
	roll = diceRoll(2, 10);
	
	cout << name << " have an attack of " << roll << "." << endl;	

	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The results of the 
 * 				fight are then displayed to the user, along with the 
 * 				BlueMen's new strength and whether it died. The function
 * 				returns a boolean value: true if the character is still
 * 				alive, and false if dead. The function also executes
 * 				BlueMen's MOB ability.
 *******************************************/

bool BlueMen::defend(int attackIn)
{
	bool alive = true;
	int damage;
	int defendRoll;
	int numberDice;
	
	// The number of dice for defense roll is calculated for 
	// the MOB ability. Number of dice reduced as strength goes down
	numberDice = (HP + 3) / 4; 
	
	// diceRoll calculated based on numberDice of 6 sided dice
	defendRoll = diceRoll(numberDice, 6);
	// Calculate damage
	damage = attackIn - defendRoll - armor;
	// Reset damage to 0 if it is negative
	if (damage < 0)
	{
		damage = 0;
	}
	
	// Set new strength
	HP -= damage;

	// Print results
	cout << name << " have a defense of " << defendRoll << "." << endl;
	cout << "Damage calculation: " << attackIn << " - ";
	cout << defendRoll << " - " << armor << " = " << damage << endl;
	
	// Check if dead
	if (HP <= 0)
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		cout << endl << name << " have died!" << endl;
		alive = false;
		return alive;
	}	
	// Return new strength if not dead
	else
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		return alive;
	}
}

//Destructor
BlueMen::~BlueMen(){}

/********************************************
 * Description: This is the default constructor for the Medusa 
 * 				class. 
 *******************************************/

Medusa::Medusa()
{
	name = "Medusa";
	HP = 8;
	armor = 3;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice, prints the resulting total, and returns the 
 * 				amount as an integer. This function also passes aa value 
 * 				of 1000000 if the Medusa rolls a 12 and triggers the 
 * 				GLARE ability.
 *******************************************/

int Medusa::attack()
{
	int roll;
	
	// Use diceRoll function to roll 2d6
	roll = diceRoll(2, 6);

	// If a 12 is rolled, trigger GLARE ability
	if (roll == 12)
	{
		cout << "Oh no! " << name << " has used GLARE!" << endl;
		return 1000000;
	}
	// Return normal attack if less than 12
	else
	{
		cout << name << " has an attack of " << roll << "." << endl;	
		return roll;
	}
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The results of the 
 * 				fight are then displayed to the user, along with the 
 * 				Medusa's new strength and whether it died. The function
 * 				returns a boolean value: true if the character is still
 * 				alive, and false if dead.
 *******************************************/

bool Medusa::defend(int attackIn)
{
	bool alive = true;
	int damage;
	int defendRoll;

	// Use diceRoll to calculate 1d6
	defendRoll = diceRoll(1, 6);
	// Calculate damage
	damage = attackIn - defendRoll - armor;
	// Reset damage to zero if it is negative
	if (damage < 0)
	{
		damage = 0;
	}
	
	// Set new strength
	HP -= damage;

	// Print results
	cout << name << " has a defense of " << defendRoll << "." << endl;
	cout << "Damage calculation: " << attackIn << " - ";
	cout << defendRoll << " - " << armor << " = " << damage << endl;
	
	// Check if dead
	if (HP <= 0)
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		cout << endl <<  name << " has died!" << endl;
		alive = false;
		return alive;
	}	
	// Return new strength if alive
	else
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		return alive;
	}
}

//Destructor
Medusa::~Medusa(){}

/********************************************
 * Description: This is the default constructor for the HarryPotter 
 * 				class. It has a variable, firstLife, used to track
 * 				the HOGWARTS ability.
 *******************************************/

HarryPotter::HarryPotter()
{
	name = "Harry Potter";
	HP = 10;
	armor = 0;
	//Boolean value for HOGWARTS ability
	firstLife = true;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice, prints the resulting total, and returns the 
 * 				amount as an integer.
 *******************************************/

int HarryPotter::attack()
{
	int roll;
	
	//diceRoll function used to roll 2d6
	roll = diceRoll(2, 6);
	
	cout << name << " has an attack of " << roll << "." << endl;	

	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The results of the 
 * 				fight are then displayed to the user, along with the 
 * 				HarryPotter's new strength and whether it died. The function
 * 				returns a boolean value: true if the character is still
 * 				alive, and false if dead. This also determines whether 
 * 				the HOGWARTS ability is triggered.
 *******************************************/

bool HarryPotter::defend(int attackIn)
{
	bool alive = true;
	int damage;
	int defendRoll;

	// Use diceRoll to get 2d6
	defendRoll = diceRoll(2, 6);
	// Calculate damage
	damage = attackIn - defendRoll - armor;
	// Reset damage to 0 if it is negative
	if (damage < 0)
	{
		damage = 0;
	}
	
	// Set new strength
	HP -= damage;

	// Print results of fight to screen
	cout << name << " has a defense of " << defendRoll << "." << endl;
	cout << "Damage calculation: " << attackIn << " - ";
	cout << defendRoll << " - " << armor << " = " << damage << endl;
	
	// Check if HOGWARTS is triggered
	if (HP <= 0 && firstLife)
	{	
		// Print that HOGWARTS is triggered
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		cout << name << " has died! But uses HOGWARTS!" << endl;
		// Reset strength to 20
		HP = 20;
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		// Set HOGWARTS trigger to false
		firstLife = false;
		return alive;
	}	
	// Check if character is dead and HOGWARTS trigger already been set
	else if (HP <= 0 && !firstLife)
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		cout << endl << name << " has died!" << endl;
		// Return that character is truly dead
		alive = false;
		return alive;
	}
	// Return new strength
	else
	{
		cout << "Strength of " << name << " is now " << HP << "." << endl;
		return alive;	
	}
}

//Destructor
HarryPotter::~HarryPotter(){}
