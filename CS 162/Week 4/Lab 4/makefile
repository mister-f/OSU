# File Name: makefile (for Lab 4)
# Author: Andrew Funk
# Date: 10-22-17
# Description: This makefile is used to compile lab 4
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = uni

$(EXE): mainUni.o getValidInt.o menu.o person.o building.o university.o
	$(CC) mainUni.o getValidInt.o menu.o person.o building.o university.o -o $(EXE)

mainUni.o: mainUni.cpp
	$(CC) $(CFLAGS) mainUni.cpp

getValidInt.o: getValidInt.cpp getValidInt.hpp
	$(CC) $(CFLAGS) getValidInt.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

person.o: person.cpp person.hpp
	$(CC) $(CFLAGS) person.cpp

building.o: building.cpp building.hpp
	$(CC) $(CFLAGS) building.cpp

university.o: university.cpp university.hpp
	$(CC) $(CFLAGS) university.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
