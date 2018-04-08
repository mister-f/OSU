# File Name: makefile (for Group Project: Rock, Paper, Scissors)
# Authors: Eric Riemer, Nathan Chang, Andrew Funk, 
# 		   Nicholas Marozick, Jessica Richmond 
# Date: 11-02-17
# Description: This is a makefile used to compile a rock, paper, scissors
# 			   program.
#

Group14: play_game.o RPSGame.o toolClass.o rockClass.o paperClass.o scissorClass.o
	g++ -std=c++11 play_game.o RPSGame.o toolClass.o rockClass.o paperClass.o scissorClass.o -o Group14

play_game.o: play_game.cpp
	g++ -std=c++11 -c play_game.cpp

RPSGame.o: RPSGame.cpp RPSGame.hpp
	g++ -std=c++11 -c RPSGame.cpp

toolClass.o: toolClass.cpp toolClass.hpp
	g++ -std=c++11 -c toolClass.cpp

rockClass.o: rockClass.cpp rockClass.hpp
	g++ -std=c++11 -c rockClass.cpp

paperClass.o: paperClass.cpp paperClass.hpp
	g++ -std=c++11 -c paperClass.cpp

scissorClass.o: scissorClass.cpp scissorClass.hpp
	g++ -std=c++11 -c scissorClass.cpp

clean: 
	rm *.o Group14
