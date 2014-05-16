FLAGS = -Wall -Wextra -Werror -pedantic

p4: BSTNode.h BSTree.h Word.o p4.o 
	g++ $(FLAGS) p4.o BSTree.h BSTNode.h Word.o -o p4

p4.o: p4.cpp 
	g++ $(FLAGS) -c p4.cpp -o p4.o

Word.o: Word.cpp Word.h
	g++ -c $(FLAGS) Word.cpp -o Word.o

BSTNode.o: BSTNode.h
	g++ -c $(FLAGS) BSTNode.h -o BSTNode.o

BSTree.o: BSTree.h
	g++ -c $(FLAGS) BSTree.h -o BSTree.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f p4