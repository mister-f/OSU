# File Name: makefile (for Project 3)
# Author: Andrew Funk
# Date: 11-03-17
# Description: This makefile is used to compile project 3
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = fight

$(EXE): mainFight.o getValidInput.o menu.o game.o character.o diceRoll.o
	$(CC) mainFight.o getValidInput.o menu.o game.o character.o diceRoll.o -o $(EXE)

mainFight.o: mainFight.cpp
	$(CC) $(CFLAGS) mainFight.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

game.o: game.cpp game.hpp
	$(CC) $(CFLAGS) game.cpp

character.o: character.cpp character.hpp
	$(CC) $(CFLAGS) character.cpp

diceRoll.o: diceRoll.cpp diceRoll.hpp
	$(CC) $(CFLAGS) diceRoll.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
