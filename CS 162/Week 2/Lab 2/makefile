# File Name: makefile (for letterCount)
# Author: Andrew Funk
# Date: 10-07-17
# Description: This makefile is used to compile the letterCount program
#
# Note: This makefile was written using information adapted from 
# 		https://www.youtube.com/watch?v=_r7i5X0rXJk and
# 		http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ and
# 		http://mrbook.org/blog/tutorials/make/

CC = g++
CFLAGS = -c -Wall -std=c++0x
EXE = letterCount

$(EXE): letterCount.o output_letters.o count_letters.o
	$(CC) letterCount.o output_letters.o count_letters.o -o $(EXE)

letterCount.o: letterCount.cpp
	$(CC) $(CFLAGS) letterCount.cpp

output_letters.o: output_letters.cpp output_letters.hpp
	$(CC) $(CFLAGS) output_letters.cpp

count_letters.o: count_letters.cpp count_letters.hpp
	$(CC) $(CFLAGS) count_letters.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXE)
