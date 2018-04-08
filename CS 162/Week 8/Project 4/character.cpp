/**************************************
 * Program Name: character.cpp
 * Name: Andrew Funk
 * Date: 11-17-17
 * Description: character.cpp is the class implementation file for the
 * 				Character class as well as the derived fighting
 * 				subclasses. The classes exhibit polymorphic behavior.
 *************************************/

#include "diceRoll.hpp"
#include "character.hpp"

using std::string;

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
int Character::getMaxHP()
{
	return maxHP;
}

// Accessor function
string Character::getName()
{
	return name;
}

// Accessor function
string Character::getProperName()
{
	return properName;
}

// Mutator function
void Character::setHP(int newHP)
{
	HP = newHP;
}

// Mutator function
void Character::setName(string nameIn)
{
	name = nameIn;
}

// Mutator function
void Character::setProperName(string properNameIn)
{
	properName = properNameIn;
}

// Accessor function
bool Character::isDead()
{
	return dead;
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
	properName = " ";
	HP = 12;
	maxHP = 12;
	armor = 0;
	dead = false;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice and returns the amount as an integer.
 *******************************************/

int Barbarian::attack()
{
	int roll;
	
	// diceRoll function used to roll 2d6
	roll = diceRoll(2, 6);
	
	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The function
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

	//Check if dead and return 'false' alive flag
	if (HP <= 0)
	{
		alive = false;
		dead = true;
		return alive;
	}	
	//Character is still alive
	else
	{
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
	properName = " ";
	HP = 18;
	maxHP = 18;
	armor = 1;
	dead = false;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice and returns the amount as an integer.
 *******************************************/

int Vampire::attack()
{
	int roll;
	
	//diceRoll used to get 1d12
	roll = diceRoll(1, 12);

	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The function
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

	// If CHARM not triggered, get normal damage
	if (charm == 2)
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
	}

	// Check if dead
	if (HP <= 0)
	{
		alive = false;
		dead = true;
		return alive;
	}	
	// If alive
	else
	{
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
	properName = " ";
	HP = 12;
	maxHP = 12;
	armor = 3;
	dead = false;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice and returns the amount as an integer.
 *******************************************/

int BlueMen::attack()
{
	int roll;
	
	//diceRoll function used to get 2d10 roll
	roll = diceRoll(2, 10);
	
	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The function
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

	// Check if dead
	if (HP <= 0)
	{
		alive = false;
		dead = true;
		return alive;
	}	
	// Return new strength if not dead
	else
	{
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
	properName = " ";
	HP = 8;
	maxHP = 8;
	armor = 3;
	dead = false;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice and returns the amount as an integer. This 
 * 				function also passes aa value of 1000000 if the Medusa 
 * 				rolls a 12 and triggers the GLARE ability.
 *******************************************/

int Medusa::attack()
{
	int roll;
	
	// Use diceRoll function to roll 2d6
	roll = diceRoll(2, 6);

	// If a 12 is rolled, trigger GLARE ability
	if (roll == 12)
	{
		return 1000000;
	}
	// Return normal attack if less than 12
	else
	{
		return roll;
	}
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The function
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

	// Check if dead
	if (HP <= 0)
	{
		alive = false;
		dead = true;
		return alive;
	}	
	// Return new strength if alive
	else
	{
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
	properName = " ";
	HP = 10;
	maxHP = 10;
	armor = 0;
	//Boolean value for HOGWARTS ability
	firstLife = true;
	dead = false;
}

/********************************************
 * Description: The attack function rolls a specific number and sides 
 * 				of dice and returns the amount as an integer.
 *******************************************/

int HarryPotter::attack()
{
	int roll;
	
	//diceRoll function used to roll 2d6
	roll = diceRoll(2, 6);

	return roll;
}

/********************************************
 * Description: The defend fucntion takes in an attack value and then 
 * 				calculates a defense roll. It subtracts this from the 
 * 				attack along with any armor value. The function
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

	// Check if HOGWARTS is triggered
	if (HP <= 0 && firstLife)
	{	
		// Reset strength to 20
		HP = 20;
		maxHP = 20;
		// Set HOGWARTS trigger to false
		firstLife = false;
		return alive;
	}	
	// Check if character is dead and HOGWARTS trigger already been set
	else if (HP <= 0 && !firstLife)
	{
		// Return that character is truly dead
		alive = false;
		dead = true;
		return alive;
	}
	// Return new strength
	else
	{
		return alive;	
	}
}

//Destructor
HarryPotter::~HarryPotter(){}
