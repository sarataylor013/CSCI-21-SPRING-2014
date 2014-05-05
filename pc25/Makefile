pc25: BSTNode.o pc25.o 
	g++ $(FLAGS) pc25.o BSTNode.o -o pc25

pc25.o: pc25.cpp
	g++ $(FLAGS) -c pc25.cpp -o pc25.o

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c $(FLAGS) BSTNode.cpp -o BSTNode.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc25