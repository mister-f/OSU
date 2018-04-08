/**************************************
 * Program Name: game.cpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: game.cpp is the class implementation file for the
 * 				Game class. It contains the delcarations for the 
 * 				member variables and functions of the Game class.
 *************************************/

#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;

/**************************************
 * Description: This is the default Game constructor. It contains the 
 * 				bulk of the game initialization. It establishes the 
 * 				network of pointers between game spaces as well as setting
 * 				most of the descriptory text of the game. It also
 * 				sets the game timer and other flags.
 *************************************/

Game::Game()
{
	timer = 18;
	victory = false;
	odinHas = 0;
	currentSpace = &hel;
	// Pointer network between spaces
	hel.setUp(&trunk1);
	trunk1.setUp(&trunk2);
	trunk1.setDown(&hel);
	trunk1.setLeft(&nilfheim);
	trunk1.setRight(&jotunheim);
	nilfheim.setRight(&trunk1);
	jotunheim.setLeft(&trunk1);
	trunk2.setUp(&asgard);
	trunk2.setDown(&trunk1);
	trunk2.setLeft(&midgard);
	trunk2.setRight(&vanaheim);
	midgard.setRight(&trunk2);
	vanaheim.setLeft(&trunk2);
	asgard.setDown(&trunk2);
	// Location names
	hel.setLocation("Hel");
	trunk1.setLocation("Yggdrasil - Lower Trunk");
	trunk2.setLocation("Yggdrasil - Upper Trunk");
	nilfheim.setLocation("Nilfheim");
	jotunheim.setLocation("Jotunheim");
	midgard.setLocation("Midgard");
	vanaheim.setLocation("Vanaheim");
	asgard.setLocation("Asgard");
	// Location descriptions
	hel.setSpaceDescrip("You are in Hel, at the base of the world tree, Yggdrasil. It is very dark here shaded by the many domains above. The ground trembles and you can hear creaking and moaning. Yggdrasil stretches above you to the lowest tier of its braches. In front of you stands THOR, with a concerned look on his face.");
	trunk1.setSpaceDescrip("You cling to Yggdrasil, its branches spread out to the lower domains of the world. Below you lies Hel. Above you are the higher domains of the world. To the left lies the cold and misty land of Nilfheim, to the right is the land of the Giants, Jotunheim.");
	trunk2.setSpaceDescrip("You are high on the massive trunk of Yggdrasil. Below you the tree goes as far as your vision allows. Up above you can see glittering Asgard in the highest boughs. To the left is the land of the humans, Midgard, and to the right are the fertile lands of Vanaheim.");
	nilfheim.setSpaceDescrip("You find yourself in the cold frozen expanse of Nilfheim. Craggy peaks and white tundra spread around you. You can see your breath billow in quick puffs. To your right is the path back to Yggdrasil, and in front of you is FREYA, standing confidently.");
	jotunheim.setSpaceDescrip("Welcome to the land of the Giants. The denizens of this land surely won't pay attention to a small creature such as yourself. To your left lies Yggdrasil. Everything seems magnified and huge, but not too far in the distance you see the glittering spear GUNGNIR stuck in the ground.");
	midgard.setSpaceDescrip("Ah, Midgard. This is one of your favorite places to visit. There are such delicious nuts grown here. Nothing helps speed your deliveries like an acorn from Yggdrasil's branches. To your right lies the way back to Yggdrasil's wide trunk. At your feet is a gleaming, tasty ACORN.");
	vanaheim.setSpaceDescrip("The fertile fields and valleys of Vanaheim lay before you. The light is stong here and everything glitters as if made of gold. To your left lies your path back to Yggdrasil. You see none of the Vanir that usually live here, but the trickster LOKI stands in the path ahead.");
	asgard.setSpaceDescrip("You've made it to Asgard at the very top of Yggdrasil. The homes of the most powerful gods stand here. You can see Valhalla and the incomplete wall that surrounds Asgard. Below you is Yggdrasil and all the rest of the world. Ahead of you on a tall throne is ODIN, large and strong.");
	// Character names and conversations
	thor.setName("Thor");
	thor.setFirstConvo("Ratatoskr my friend! I am in dire need of your help. The dragon NIDHOGG has gnawed at the roots of Yggdrasil for far too long. Its foundations become weak and threaten the whole of the world. I can only defeat it with my hammer MJOLNIR, but I have misplaced it. Please find it and deliver it to me before it is too late!");
	thor.setSecondConvo("Please, Ratatoskr. You must find my hammer, MJOLNIR! Time runs short!");
	loki.setName("Loki");
	loki.setFirstConvo("Ah, hello little Ratatoskr. What brings you here? Actually, I don't really care. I do care about games though. Maybe you'd like to win a prize? What say you, Ratatoskr?");
	loki.setSecondConvo("Back again? Maybe you'd like to win a prize after all?");
	loki.setSuccess("I have given you your prize little squirrel. Bother me no more.");
	odin.setName("Odin");
	odin.setFirstConvo("Hello messenger. You have traveled very high up Yggdrasil. THOR has left his hammer MJOLNIR here and I keep it in my possession. I cannot part with it though until I get back my own belongings. I threw my spear GUNGNIR far down Yggdrasil and know not where it lies. My ring DRAUPNIR has also been misplaced. Bring them both and I shall give you MJOLNIR.");
	odin.setSecondConvo("I say, Ratatoskr. I need both GUNGNIR and DRAUPNIR before I will part with MJOLNIR.");
	odin.setSuccess("Thank you for bringing me my possessions, Ratatoskr. You are a true friend.");
	freya.setName("Freya");
	freya.setFirstConvo("Hello, Ratatoskr. Your tail is unusually puffy in this cold. Can you help me? Someone has taken my prized necklace BRISINGAMEN. I bet it was that lout LOKI. I can trade it for Odin's prized ring DRAUPNIR if you bring it to me.");
	freya.setSecondConvo("I am missing my necklace BRISINGAMEN. Retrieve it for me and I shall gift you DRAUPNIR.");
	freya.setSuccess("Many thanks to you Ratatoskr! My necklace has returned!");
	// Item names
	mjolnir.setName("Mjolnir");
	acorn.setName("Acorn");
	brisingamen.setName("Brisingamen");
	draupnir.setName("Draupnir");
	gungnir.setName("Gungnir");
}

/********************************
 * Description: playGame is the main function that runs the game 
 * 				execution. It contains loops that run until game 
 * 				conditions are met or failed and contains actions to
 * 				execute depending on user menu selection.
 *******************************/

void Game::playGame()
{
	int selection;

	// Game introduction
	cout << endl;
	cout << "You are Ratatoskr, a squirrel god who runs up and down "
		 << "the world tree Yggdrasil delivering messages. You have "
		 << "run to the base of Yggdrasil to the world of Hel. Something"
		 << " does not seem quite right..." << endl;	
	// Run game loop until timer runs out or victory achieved
	do
	{
		// Run loop until moved to new game Space
		do
		{
			// Display timer and location info
			cout << endl << "Time remaining: " << timer << endl;
			cout << "Current Location: " << currentSpace->getLocation();
			cout << endl;
			cout << currentSpace->getDescrip() << endl;
			// Display menu and get choice
			selection = currentSpace->showMenu();
			
			// Open bag menu choice
			if (selection == 5)
			{
				// Display container submenu
				Item* tool = satchel.useBagMenu();
				// Run useItem function for returned value
				useItem(tool);
			}
			// Talk to Thor menu choice
			else if (selection == 6)
			{
				// Initial conversation
				if (!thor.getTalkedTo())
				{
					cout << endl << thor.getFirstConvo() << endl;
					thor.setTalkedTo(true);
				}
				// Followup conversation
				else
				{
					cout << endl << thor.getSecondConvo() << endl;
				}
			}
			// Talk to Odin menu choice
			else if (selection == 7)
			{
				// Initial convo
				if (!odin.getTalkedTo())
				{
					cout << endl << odin.getFirstConvo() << endl;
					odin.setTalkedTo(true);
				}
				// Followup convo
				else if (!odin.getFulfilled())
				{
					cout << endl << odin.getSecondConvo() << endl;
				}
				// Conditions met convo
				else
				{
					cout << endl << odin.getSuccess() << endl;
				}
			}
			// Talk to Freya menu choice
			else if (selection == 8)
			{
				// Initial convo
				if (!freya.getTalkedTo())
				{
					cout << endl << freya.getFirstConvo() << endl;
					freya.setTalkedTo(true);
				}
				// Followup convo
				else if (!freya.getFulfilled())
				{
					cout << endl << freya.getSecondConvo() << endl;
				}
				// Conditions met convo
				else
				{
					cout << endl << freya.getSuccess() << endl;
				}
			}
			// Talk to Loki menu choice
			else if (selection == 9)
			{
				// Initial convo
				if (!loki.getTalkedTo())
				{
					cout << endl << loki.getFirstConvo() << endl;
					// Run Loki mini game
					miniGame();
					loki.setTalkedTo(true);
				}
				// Followup convo
				else if (!loki.getFulfilled())
				{
					cout << endl << loki.getSecondConvo() << endl;
					// Run Loki mini game
					miniGame();
				}
				// Conditions met convo
				else
				{
					cout << endl << loki.getSuccess() << endl;
				}
			}
			// Pick up acorn menu choice
			else if (selection == 10)
			{
				// Add acorn to bag, remove from Space
				acorn.setInBag(true);
				satchel.putInBag(&acorn);
				midgard.setItemPresent(false);
				midgard.setSpaceDescrip("Ah, Midgard. This is one of your favorite places to visit. There are such delicious nuts grown here. Nothing helps speed your deliveries like an acorn from Yggdrasil's branches. To your right lies the way back to Yggdrasil's wide trunk.");
			}
			// Pick up gungnir menu choice
			else if (selection == 11)
			{
				// Add to bag, remove from scene
				gungnir.setInBag(true);
				satchel.putInBag(&gungnir);
				jotunheim.setItemPresent(false);
				jotunheim.setSpaceDescrip("Welcome to the land of the Giants. The denizens of this land surely won't pay attention to a small creature such as yourself. To your left lies Yggdrasil. Everything seems magnified and huge.");
			}
		} while (selection > 4 && !victory);

		// Movement choices, change to new space
		if (selection == 1)
		{
			currentSpace = currentSpace->getUp();
		}
		else if (selection == 2)
		{
			currentSpace = currentSpace->getDown();
		}
		else if (selection == 3)
		{
			currentSpace = currentSpace->getLeft();
		}
		else if (selection == 4)
		{
			currentSpace = currentSpace->getRight();
		}

		// Adjust timer
		timer--;
	} while (timer > 0 && !victory);

	// Timer fail condition
	if (timer == 0)
	{
		cout << "You are out of time! NIDHOGG has felled Yggdrasil! Ragnarok is upon us!";
		cout << endl;
	}
	// Victory condition
	else if (victory)
	{
		cout << "You have saved the world! Congratulations, Ratatoskr!";
		cout << endl;
	}
}

/************************************
 * Description: useItem is a function that takes an Item pointer as a 
 * 				parameter. Depending on the current game Space and what
 * 				item is selected, it may complete a game action.
 ***********************************/

void Game::useItem(Item* toolIn)
{
	// Make sure NULL value wasn't returned
	if (toolIn != NULL)
	{
		cout << endl;
		// For acorn item used anywhere
		if (toolIn == &acorn)
		{
			// Acorn increases timer
			cout << "You eat the acorn. You feel energized! (+3 to time)";
			cout << endl;
			timer += 3;
			satchel.removeFromBag(&acorn);
		}
		// If mjolnir used in hel
		else if ((toolIn == &mjolnir) && (currentSpace == &hel))
		{
			cout << "You have done it, Ratatoskr! You are a true friend and hero! I shall now be able to beat back NIDHOGG!";
			cout << endl;
			satchel.removeFromBag(&mjolnir);
			victory = true;
		}
		// If birsingamen is used in nilfheim
		else if ((toolIn == &brisingamen) && (currentSpace == &nilfheim))
		{
			cout << "My necklace! Oh thank you squirrely friend. Here is DRAUPNIR, as I promised.";
			cout << endl;
			satchel.removeFromBag(&brisingamen);
			satchel.putInBag(&draupnir);
			freya.setFulfilled(true);
		}
		// If gungnir used in asgard
		else if ((toolIn == &gungnir) && (currentSpace == &asgard))
		{
			// Conditions to check if Odin received an item already
			if (odinHas == 0)
			{
				cout << "You have found GUNGNIR! My thanks, but have you found DRAUPNIR too?";
				cout  << endl;
				satchel.removeFromBag(&gungnir);
				odinHas++;
			}
			else if (odinHas == 1)
			{
				cout << "Wonderful! Thank you for bringing me my prized possessions. Here is MJOLNIR. I hope it isn't too heavy.";
				cout << endl;
				satchel.removeFromBag(&gungnir);
				satchel.putInBag(&mjolnir);
				odin.setFulfilled(true);
			}
		}
		// If draupnir is used in asgard
		else if ((toolIn == &draupnir) && (currentSpace == &asgard))
		{
			// Conditions to check if Odin already received an item
			if (odinHas == 0)
			{
				cout << "Oh! My ring! Thank you, Ratatoskr. I still need my spear GUNGNIR before I can give you MJOLNIR."; 
				cout << endl;
				satchel.removeFromBag(&draupnir);
				odinHas++;
			}
			else if (odinHas == 1)
			{
				cout << "Wonderful! Thank you for bringing me my prized possessions. Here is MJOLNIR. I hope it isn't too heavy.";
				cout << endl;
				satchel.removeFromBag(&draupnir);
				satchel.putInBag(&mjolnir);
				odin.setFulfilled(true);
			}
		}
		// Items don't work except in above conditions
		else
		{
			cout << "That doesn't seem to do anything." << endl;
		}
	}
}

/********************************
 * Description: miniGame executes Loki's guessing game. It is just a 
 * 				number guessing game where Loki chooses a random number.
 *******************************/

void Game::miniGame()
{
	vector<string> menuItems;
	int menuChoice;
	string userEntry;
	int lokiNumber;
	int guessCounter = 6;
	int guess;

	// Create menu to see if user wants to play
	menuItems.push_back("Yes.");
	menuItems.push_back("No.");
	Menu guessMenu("Would you like to play my game?", menuItems);
	guessMenu.displayMenu();
	menuChoice = guessMenu.getChoice();

	// If user wants to play
	if (menuChoice == 1)
	{
		cout << endl;
		cout << "Excellent. I am thinking of a number from 1 to 100.";
		cout << endl;
		// Generate random number from 1 to 100
		lokiNumber = (rand() % 100) + 1;	
		
		// Take guesses until success or guesses run out
		do
		{
			cout << endl;
			cout << "You have " << guessCounter << " guesses left.";
			cout << endl;
			cout << "What is your guess?" << endl;
			// Get valid guess from user
			do
			{
				getline(cin, userEntry);
				guess = getValidInt(userEntry);
				if (guess < 1 || guess > 100)
				{
					cout << "That's not even between 1 and 100!";
					cout << endl << "I'll let you try again." << endl;
				}
			} while (guess < 1 || guess > 100);
			
			// Check if number guessed
			if (guess == lokiNumber)
			{
				cout << endl;
				cout << "Wow. You got it. Pretty smart for a squirrel.";
				cout << endl << "Here is the gift I promised." << endl;
				// Put brisingamen in bag if user wins
				satchel.putInBag(&brisingamen);
				loki.setFulfilled(true);
			}
			// For a low guess
			else if (guess < lokiNumber)
			{
				cout << "Wrong! That's much too low." << endl;
				guessCounter--;
			}
			// For a high guess
			else
			{
				cout << "Wrong! That's far too high." << endl;
				guessCounter--;
			}
		} while (guess != lokiNumber && guessCounter > 0);

		// Losing condition text
		if (guessCounter == 0)
		{
			cout << endl;
			cout << "Looks like you'll have to try again rodent." << endl;
		}
	}
	// User chooses not to play text
	else
	{
		cout << endl;
		cout << "Fine, let me know if you do little squirrel." << endl;
	}
}
