/**************************************
 * Program Name: mainUni.cpp
 * Name: Andrew Funk
 * Date: 10-22-17
 * Description: mainUni.cpp is used to run a very basic university 
 * 				information system. It creates a University object 
 * 				that the user can query and do a few simple tasks
 * 				with. It also instatiates several class objects to 
 * 				fill the University with.
 *************************************/

#include <ctime>
#include <cstdlib>
#include "university.hpp"

int main ()
{
	unsigned seed;

	// Seed random function for use in class member functions
	seed = time(0);
	srand(seed);

	University OSU;	

	// Pointers to Person objects so polymorphic behavior can be used
	Person* s1Ptr;
	Person* s2Ptr;
	Person* s3Ptr;
	Person* i1Ptr;
	Person* i2Ptr;
	Person* i3Ptr;

	Student student1("Andrew Funk", 35, 3.9);
	Student student2("Johnny Applecakes", 24, 2.7);
	Student student3("Missy Jo Weatherford", 41, 3.4);
	Instructor instructor1("Timothy Alcon", 40, 4.2);
	Instructor instructor2("Luyao Zhang", 30, 4.3);
	Instructor instructor3("Samina Ehsan", 35, 4.1);
	Building building1("HF Oil Shed", 71, 
		"3455 NE Granger, Corvallis, OR 97330");
	Building building2("Vet Dairy Barn", 5379, 
		"3201 SW Washington Way, Corvallis, OR 97331");
	Building building3("Swine Center", 15951, 
		"4500 SW Campus Way, Corvallis, OR 97330");

	s1Ptr = &student1;
	s2Ptr = &student2;
	s3Ptr = &student3;
	i1Ptr = &instructor1;
	i2Ptr = &instructor2;
	i3Ptr = &instructor3;

	// Add people and buildings to University object
	OSU.addPerson(s1Ptr);
	OSU.addPerson(s2Ptr);
	OSU.addPerson(s3Ptr);
	OSU.addPerson(i1Ptr);
	OSU.addPerson(i2Ptr);
	OSU.addPerson(i3Ptr);
	OSU.addBuilding(building1);
	OSU.addBuilding(building2);
	OSU.addBuilding(building2);

	OSU.displayMenu();

	return 0;
}
