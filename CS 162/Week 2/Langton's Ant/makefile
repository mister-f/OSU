# File Name: makefile (for langtonAnt)
# Author: Andrew Funk
# Date: 10-05-17
# Description: This makefile is used to compile the langtonAnt program
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = langtonAnt

$(EXE): langtonMain.o getValidInt.o ant.o menu.o
	$(CC) langtonMain.o getValidInt.o ant.o menu.o -o $(EXE)

langtonMain.o: langtonMain.cpp
	$(CC) $(CFLAGS) langtonMain.cpp

getValidInt.o: getValidInt.cpp getValidInt.hpp
	$(CC) $(CFLAGS) getValidInt.cpp

ant.o: ant.cpp ant.hpp
	$(CC) $(CFLAGS) ant.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
