FLAGS = -Wall -Wextra -Werror -pedantic

# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#
all: project-1 pc01 pc02 pc03 pc04 pc05 pc06 pc07 pc08 pc09 pc10 pc11 pc12 pc14

# Target for programming project 1
# Date completed: 2-19-2014
project-1: project-1.cpp
	g++ $(FLAGS) -o project-1 project-1.cpp
	
# Target for programming challenge 1
# Date completed: 2-10-2014
pc01: pc01.cpp
	g++ $(FLAGS) -o pc01 pc01.cpp
	
# Target for programming challenge 2
# Date completed: 2-10-2014
pc02: pc02.cpp
	g++ $(FLAGS) -o pc02 pc02.cpp

# Target for programming challenge 3
# Date completed: 2-10-2014
pc03: pc03.cpp
	g++ $(FLAGS) -o pc03 pc03.cpp
	
# Target for programming challenge 4
# Date completed: 2-10-2014
pc04: pc04.cpp
	g++ $(FLAGS) -o pc04 pc04.cpp
	
# Target for programming challenge 5
# Date completed: 2-10-2014
pc05: pc05.cpp
	g++ $(FLAGS) -o pc05 pc05.cpp
	
# Target for programming challenge 6
# Date completed: 2-10-2014
pc06: pc06.cpp
	g++ $(FLAGS) -o pc06 pc06.cpp
	
# Target for programming challenge 7
# Date completed: 2-12-2014
pc07: pc07.cpp
	g++ $(FLAGS) -o pc07 pc07.cpp
	
# Target for programming challenge 8
# Date completed: 2-12-2014
pc08: pc08.cpp
	g++ $(FLAGS) -o pc08 pc08.cpp

# Target for programming challenge 9
# Date completed: 2-19-2014
pc09: pc09.cpp
	g++ $(FLAGS) -o pc09 pc09.cpp
	
# Target for programming challenge 10
# Date completed: 3-3-2014
pc10: pc10.cpp
	g++ $(FLAGS) -o pc10 pc10.cpp
	
# Target for programming challenge 11
# Date completed: 3-3-2014
pc11: pc11.cpp
	g++ $(FLAGS) -o pc11 pc11.cpp

# Target for programming challenge 12
# Date completed: 3-10-2014
pc12: pc12.cpp
	g++ $(FLAGS) -o pc12 pc12.cpp
	
# Target for programming challenge 13
# Date completed: 3-12-2014
pc13: pc13.cpp
	g++ $(FLAGS) -o pc13 pc13.cpp

# Target for programming challenge 14
# Date completed: 3-24-2014
pc14: pc14.cpp
	g++ $(FLAGS) -o pc14 pc14.cpp