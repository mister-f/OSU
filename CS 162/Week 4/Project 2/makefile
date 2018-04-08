# File Name: makefile (for Zoo Game)
# Author: Andrew Funk
# Date: 10-20-17
# Description: This makefile is used to compile the zoo program
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = zoo

$(EXE): mainZoo.o getValidInt.o menu.o game.o zoo.o animal.o
	$(CC) mainZoo.o getValidInt.o menu.o game.o zoo.o animal.o -o $(EXE)

mainZoo.o: mainZoo.cpp
	$(CC) $(CFLAGS) mainZoo.cpp

getValidInt.o: getValidInt.cpp getValidInt.hpp
	$(CC) $(CFLAGS) getValidInt.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

game.o: game.cpp game.hpp
	$(CC) $(CFLAGS) game.cpp

zoo.o: zoo.cpp zoo.hpp
	$(CC) $(CFLAGS) zoo.cpp

animal.o: animal.cpp animal.hpp
	$(CC) $(CFLAGS) animal.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
