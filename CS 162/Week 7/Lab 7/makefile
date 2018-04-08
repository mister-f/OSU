# File Name: makefile (for Lab 7)
# Author: Andrew Funk
# Date: 11-11-17
# Description: This makefile is used to compile lab 7
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = queueFun

$(EXE): mainQueue.o getValidInput.o menu.o queue.o
	$(CC) mainQueue.o getValidInput.o menu.o queue.o -o $(EXE)

mainQueue.o: mainQueue.cpp
	$(CC) $(CFLAGS) mainQueue.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

queue.o: queue.cpp queue.hpp
	$(CC) $(CFLAGS) queue.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
