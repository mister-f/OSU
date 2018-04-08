/**************************************
 * Program Name: character.hpp
 * Name: Andrew Funk
 * Date: 12-03-17
 * Description: character.hpp is the class specification file for the
 * 				Character class.
 *************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using std::string;

class Character
{
	private:
		string name;
		string firstConvo;
		string secondConvo;
		string success;
		// Flags used to track converstations
		bool talkedTo;
		bool fulfilled;

	public:
		Character();
		void setName(string);
		void setFirstConvo(string);
		void setSecondConvo(string);
		void setSuccess(string);
		void setTalkedTo(bool);
		void setFulfilled(bool);
		string getName();
		string getFirstConvo();
		string getSecondConvo();
		string getSuccess();
		bool getTalkedTo();
		bool getFulfilled();
};

#endif
