# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#
all: pc1 pc2 pc3

# Target for programming challenge 1
# Date completed: 2-3-2014
pc1: pc1.cpp
	g++ -o pc1 pc1.cpp
	
# Target for programming challenge 2
# Date completed: 2-3-2014
pc2: pc2.cpp
	g++ -o pc2 pc2.cpp

# Target for programming challenge 3
# Date completed: 2-3-2014
pc3: pc3.cpp
	g++ -o pc3 pc3.cpp