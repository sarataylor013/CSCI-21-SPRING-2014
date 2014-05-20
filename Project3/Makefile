FLAGS = -Wall -Wextra -Werror -pedantic

# Makefile for programming project 3
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#
project3: DLNode.h DList.h p3.o 
	g++ $(FLAGS) p3.o DLNode.h DList.h -o p3

p3.o: p3.cpp
	g++ $(FLAGS) -c p3.cpp -o p3.o

DLNode.o: DLNode.h
	g++ -c $(FLAGS) DLNode.h -o DLNode.o

DList.o: DList.h
	g++ -c $(FLAGS) DList.h -o DList.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f p3