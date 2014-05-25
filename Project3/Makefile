FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

# Makefile for programming project 3
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#

#
# Grader comments 2014.05.24
# Any change to DLNode.h or DList.h needs to
# result in p3.cpp being compiled again. That
# doesn't happen here -- this controls only
# the linking of the already-compiled p3.cpp.
# Moved them down to p3.o to make it build properly.
#
project3: p3.o 
#
# Grader comments 2014.05.24
# You don't want to compile separate modules for
# DList and DLNode. The objects compile as part of
# your p3.cpp, which includes them.
#
	g++ $(FLAGS) p3.o -o p3

p3.o: p3.cpp DLNode.h DList.h
	g++ $(FLAGS) -c p3.cpp -o p3.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f p3