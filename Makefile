FLAGS = -Wall -Wextra -Werror -pedantic

# Makefile for programming challenges
#
# CSCI 21, Spring 2014
#
# Programmer: Sara Taylor
#
all: project-1 pc1 pc2 pc3 pc4 pc5 pc6 pc7 pc8 pc9 pc10

# Target for programming project 1
# Date completed: 2-19-2014
project-1: project-1.cpp
	g++ $(FLAGS) -o project-1 project-1.cpp
	
# Target for programming challenge 1
# Date completed: 2-10-2014
pc1: pc1.cpp
	g++ $(FLAGS) -o pc1 pc1.cpp
	
# Target for programming challenge 2
# Date completed: 2-10-2014
pc2: pc2.cpp
	g++ $(FLAGS) -o pc2 pc2.cpp

# Target for programming challenge 3
# Date completed: 2-10-2014
pc3: pc3.cpp
	g++ $(FLAGS) -o pc3 pc3.cpp
	
# Target for programming challenge 4
# Date completed: 2-10-2014
pc4: pc4.cpp
	g++ $(FLAGS) -o pc4 pc4.cpp
	
# Target for programming challenge 5
# Date completed: 2-10-2014
pc5: pc5.cpp
	g++ $(FLAGS) -o pc5 pc5.cpp
	
# Target for programming challenge 6
# Date completed: 2-10-2014
pc6: pc6.cpp
	g++ $(FLAGS) -o pc6 pc6.cpp
	
# Target for programming challenge 7
# Date completed: 2-12-2014
pc7: pc7.cpp
	g++ $(FLAGS) -o pc7 pc7.cpp
	
# Target for programming challenge 8
# Date completed: 2-12-2014
pc8: pc8.cpp
	g++ $(FLAGS) -o pc8 pc8.cpp

# Target for programming challenge 9
# Date completed: 2-19-2014
pc9: pc9.cpp
	g++ $(FLAGS) -o pc9 pc9.cpp
	
# Target for programming challenge 10
# Date completed: 3-3-2014
pc10: pc10.cpp
	g++ $(FLAGS) -o pc10 pc10.cpp
	
