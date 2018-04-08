# File Name: makefile (for matrixCalc)
# Author: Andrew Funk
# Date: 9-28-17
# Description: This makefile is used to compile the matrixCalc program
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = matrixCalc

$(EXE): matrixCalc.o getValidInt.o determinant.o readMatrix.o
	$(CC) matrixCalc.o getValidInt.o determinant.o readMatrix.o -o $(EXE)

matrixCalc.o: matrixCalc.cpp
	$(CC) $(CFLAGS) matrixCalc.cpp

getValidInt.o: getValidInt.cpp getValidInt.hpp
	$(CC) $(CFLAGS) getValidInt.cpp

determinant.o: determinant.cpp determinant.hpp
	$(CC) $(CFLAGS) determinant.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	$(CC) $(CFLAGS) readMatrix.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
