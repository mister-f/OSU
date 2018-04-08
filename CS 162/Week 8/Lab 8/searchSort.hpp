/**************************************
 * Program Name: searchSort.hpp
 * Name: Andrew Funk
 * Date: 11-18-17
 * Description: searchSort.hpp is the specification file for several
 * 				functions that search and sort small ararys.
 *************************************/

#ifndef SEARCHSORT_HPP
#define SEARCHSORT_HPP

#include <string>
#include <fstream>
#include <iostream>

using std::string;

void fileInput(int[], int, string &);
void linearSearch(int[], int, int, string);
void sortAndOutput(int[], int, string, string);
void binarySearch(int[], int, int, string);

#endif
