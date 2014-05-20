FLAGS = -Wall -Wextra -Werror -pedantic

pc19: SLNode.o pc19.o  SList.o
	g++ $(FLAGS) pc19.o SLNode.o SList.o -o pc19

pc19.o: pc19.cpp
	g++ $(FLAGS) -c pc19.cpp -o pc19.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
	
SList.o: SList.cpp SList.h
	g++ -c $(FLAGS) SList.cpp -o SList.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc19