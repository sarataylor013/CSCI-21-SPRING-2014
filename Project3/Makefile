FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Makefile for programming project 3
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#
project3: p3.o 
	g++ $(FLAGS) p3.o DLNode.h DList.h -o p3

p3.o: p3.cpp DLNode.h DList.h
	g++ $(FLAGS) -c p3.cpp -o p3.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f p3