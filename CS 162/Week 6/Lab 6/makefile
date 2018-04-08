# File Name: makefile (for Lab 6)
# Author: Andrew Funk
# Date: 11-04-17
# Description: This makefile is used to compile lab 6
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = lists

$(EXE): nodeList.o getValidInput.o menu.o node.o list.o
	$(CC) nodeList.o getValidInput.o menu.o node.o list.o -o $(EXE)

nodeList.o: nodeList.cpp
	$(CC) $(CFLAGS) nodeList.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

node.o: node.cpp node.hpp
	$(CC) $(CFLAGS) node.cpp

list.o: list.cpp list.hpp
	$(CC) $(CFLAGS) list.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
