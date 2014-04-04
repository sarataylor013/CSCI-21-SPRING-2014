FLAGS = -Wall -Wextra -Werror -pedantic

# Makefile for programming project 2
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#
p2: Prize.o Box.o p2.o 
	g++ $(FLAGS) p2.o Prize.o Box.o -o p2

p2.o: p2.cpp
	g++ $(FLAGS) -c p2.cpp -o p2.o

Box.o: Box.cpp Box.h
	g++ -c $(FLAGS) Box.cpp -o Box.o

Prize.o: Prize.h Prize.cpp 
	g++ -c $(FLAGS) Prize.cpp -o Prize.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f p2