FLAGS = -Wall -Wextra -Werror -pedantic
pc17: SLNode.o pc17.o 
	g++ $(FLAGS) pc17.o SLNode.o -o pc17

pc17.o: pc17.cpp
	g++ $(FLAGS) -c pc17.cpp -o pc17.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc17