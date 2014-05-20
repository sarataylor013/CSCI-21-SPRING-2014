FLAGS = -Wall -Wextra -Werror -pedantic

pc20: SLNode.o pc20.o  SList.o
	g++ $(FLAGS) pc20.o SLNode.o SList.o -o pc20

pc20.o: pc20.cpp
	g++ $(FLAGS) -c pc20.cpp -o pc20.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
	
SList.o: SList.cpp SList.h
	g++ -c $(FLAGS) SList.cpp -o SList.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc20