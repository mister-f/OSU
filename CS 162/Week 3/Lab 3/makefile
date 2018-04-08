# File Name: makefile (for diceGame)
# Author: Andrew Funk
# Date: 10-15-17
# Description: This makefile is used to compile the diceGame program
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = dice

$(EXE): mainDice.o getValidInt.o menu.o diceGame.o die.o loadedDie.o
	$(CC) mainDice.o getValidInt.o menu.o diceGame.o die.o loadedDie.o -o $(EXE)

mainDice.o: mainDice.cpp
	$(CC) $(CFLAGS) mainDice.cpp

getValidInt.o: getValidInt.cpp getValidInt.hpp
	$(CC) $(CFLAGS) getValidInt.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

diceGame.o: diceGame.cpp diceGame.hpp
	$(CC) $(CFLAGS) diceGame.cpp

die.o: die.cpp die.hpp
	$(CC) $(CFLAGS) die.cpp

loadedDie.o: loadedDie.cpp loadedDie.hpp
	$(CC) $(CFLAGS) loadedDie.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
