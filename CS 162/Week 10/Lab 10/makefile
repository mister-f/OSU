# File Name: makefile (for Lab 10)
# Author: Andrew Funk
# Date: 12-01-17
# Description: This makefile is used to compile lab 10
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = lab10

$(EXE): lab10.o getValidInput.o FibonacciNR.o FibonacciR.o
	$(CC) lab10.o getValidInput.o FibonacciNR.o FibonacciR.o -o $(EXE)

lab10.o: lab10.cpp
	$(CC) $(CFLAGS) lab10.cpp

getValidInput.o: getValidInput.cpp getValidInput.hpp
	$(CC) $(CFLAGS) getValidInput.cpp

FibonacciNR.o: FibonacciNR.cpp FibonacciNR.h
	$(CC) $(CFLAGS) FibonacciNR.cpp

FibonacciR.o: FibonacciR.cpp FibonacciR.h
	$(CC) $(CFLAGS) FibonacciR.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
