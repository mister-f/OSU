# File Name: makefile (for Lab 5)
# Author: Andrew Funk
# Date: 10-26-17
# Description: This makefile is used to compile lab 5
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = recur

$(EXE): lab5.o getValidInput.o menu.o recursion.o 
	$(CC) lab5.o getValidInput.o menu.o recursion.o -o $(EXE)

lab5.o: lab5.cpp
	$(CC) $(CFLAGS) lab5.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

recursion.o: recursion.cpp recursion.hpp
	$(CC) $(CFLAGS) recursion.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
