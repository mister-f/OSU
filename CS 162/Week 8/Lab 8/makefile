# File Name: makefile (for Lab 8)
# Author: Andrew Funk
# Date: 11-18-17
# Description: This makefile is used to compile lab 8
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = lab8

$(EXE): lab8.o getValidInput.o searchSort.o
	$(CC) lab8.o getValidInput.o searchSort.o -o $(EXE)

lab8.o: lab8.cpp
	$(CC) $(CFLAGS) lab8.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

searchSort.o: searchSort.cpp searchSort.hpp
	$(CC) $(CFLAGS) searchSort.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
