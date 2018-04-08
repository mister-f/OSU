/**************************************
 * Name: Andrew Funk
 * Date: 7-10-17
 * Description: This program prompts a user for a number, and then prompts
 * 				another user to guess that number. After each guess the program 
 * 				outputs whether the guess was too high or low until the correct
 * 				number is guessed. It finally outputs the number of guesses it took. 
 *************************************/

#include <iostream>
using namespace std;

int main ()
{
	int playerTarget;			// Number to guess
	int playerGuess;			// Guess
	int guessCounter = 1;		// Attempt counter, initalized to one (one guess guaranteed)

	// Prompt user for number to guess and first guess
	cout << "Enter the number for the player to guess." << endl;
	cin >> playerTarget;
	cout << "Enter your guess." << endl;
	cin >> playerGuess;

	// Loop checks if guess matches target
	while (playerGuess != playerTarget)
	{
		// Checks if guess is too low
		if (playerGuess < playerTarget)
		{
			cout << "Too low - try again." << endl;
		}
		// If guess is not too low it must be too high
		else
		{
			cout << "Too high - try again." << endl;
		}
		// Increment counter and input new guess
		guessCounter++;
		cin >> playerGuess;
	}
	
	// Display total number of guesses after correct value ends loop
	cout << "You guessed it in " << guessCounter << " tries." << endl;

	return 0;
}
