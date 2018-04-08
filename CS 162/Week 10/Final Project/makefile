# File Name: makefile (for Final Project)
# Author: Andrew Funk
# Date: 12-03-17
# Description: This makefile is used to compile CS162 Final Project
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = ratatosk

$(EXE): ratatosk.o getValidInput.o menu.o game.o character.o container.o item.o space.o
	$(CC) ratatosk.o getValidInput.o menu.o game.o character.o container.o item.o space.o -o $(EXE)

ratatosk.o: ratatosk.cpp
	$(CC) $(CFLAGS) ratatosk.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

game.o: game.cpp game.hpp
	$(CC) $(CFLAGS) game.cpp

character.o: character.cpp character.hpp
	$(CC) $(CFLAGS) character.cpp

container.o: container.cpp container.hpp
	$(CC) $(CFLAGS) container.cpp

item.o: item.cpp item.hpp
	$(CC) $(CFLAGS) item.cpp

space.o: space.cpp space.hpp
	$(CC) $(CFLAGS) space.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
