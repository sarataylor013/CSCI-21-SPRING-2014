FLAGS = -Wall -Wextra -Werror -pedantic -Wno-newline-eof

p4: Word.o p4.o 
	g++ $(FLAGS) p4.o Word.o -o p4

p4.o: p4.cpp BSTNode.h BSTree.h
	g++ $(FLAGS) -c p4.cpp -o p4.o

Word.o: Word.cpp Word.h
	g++ -c $(FLAGS) Word.cpp -o Word.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f p4