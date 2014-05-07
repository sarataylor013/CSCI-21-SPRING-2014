FLAGS = -Wall -Wextra -Werror -pedantic

pc26: BSTNode.o BSTree.o pc26.o 
	g++ $(FLAGS) pc26.o BSTree.o BSTNode.o -o pc26

pc26.o: pc26.cpp
	g++ $(FLAGS) -c pc26.cpp -o pc26.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o
	
BSTree.o: BSTree.cpp BSTree.h
	g++ -c $(FLAGS) BSTree.cpp -o BSTree.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc26