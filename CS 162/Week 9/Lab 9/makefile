# File Name: makefile (for Lab 9)
# Author: Andrew Funk
# Date: 11-25-17
# Description: This makefile is used to compile lab 9
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = lab9

$(EXE): lab9.o getValidInput.o menu.o stlFunctions.o
	$(CC) lab9.o getValidInput.o menu.o stlFunctions.o -o $(EXE)

lab9.o: lab9.cpp
	$(CC) $(CFLAGS) lab9.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

stlFunctions.o: stlFunctions.cpp stlFunctions.hpp
	$(CC) $(CFLAGS) stlFunctions.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
