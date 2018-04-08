# File Name: makefile (for Project 4)
# Author: Andrew Funk
# Date: 11-17-17
# Description: This makefile is used to compile project 4
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = fight

$(EXE): mainFight.o getValidInput.o menu.o game.o character.o diceRoll.o list.o node.o tournament.o
	$(CC) mainFight.o getValidInput.o menu.o game.o character.o diceRoll.o list.o node.o tournament.o -o $(EXE)

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

list.o: list.cpp list.hpp
	$(CC) $(CFLAGS) list.cpp

node.o: node.cpp node.hpp
	$(CC) $(CFLAGS) node.cpp

tournament.o: tournament.cpp tournament.hpp
	$(CC) $(CFLAGS) tournament.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
