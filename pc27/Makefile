FLAGS = -Wall -Wextra -Werror -pedantic

pc27: BSTNode.o BSTree.o pc27.o 
	g++ $(FLAGS) pc27.o BSTree.o BSTNode.o -o pc27

pc27.o: pc27.cpp
	g++ $(FLAGS) -c pc27.cpp -o pc27.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o
	
BSTree.o: BSTree.cpp BSTree.h
	g++ -c $(FLAGS) BSTree.cpp -o BSTree.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc27