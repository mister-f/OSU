/**************************************
 * Program Name: person.hpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: person.hpp is the class specification file for the
 * 				Person class as well as the derived Student and Instructor
 * 				subclasses. The classes exhibit polymorphic behavior.
 *************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

class Person
{
	protected:
		string name;
		int age;

	public:
		Person(string, int);
		int getAge();
		string getName();
		// Virtual functions for polymorphism
		virtual string getLabel() = 0;
		virtual double getNumber() = 0;
		virtual void do_work() = 0; 
		virtual ~Person();
};

class Student : public Person
{
	protected:
		double GPA;

	public:
		Student(string, int, double);
		double getNumber();
		string getLabel();
		virtual void do_work();
		virtual ~Student();
};

class Instructor : public Person
{
	protected:
		double rating;
	
	public:
		Instructor(string, int, double);
		double getNumber();
		string getLabel();
		virtual void do_work();
		virtual ~Instructor();
};

#endif
