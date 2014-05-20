FLAGS = -Wall -Wextra -Werror -pedantic

pc18: SLNode.o pc18.o  SList.o
	g++ $(FLAGS) pc18.o SLNode.o SList.o -o pc18

pc18.o: pc18.cpp
	g++ $(FLAGS) -c pc18.cpp -o pc18.o

SLNode.o: SLNode.cpp SLNode.h
	g++ -c $(FLAGS) SLNode.cpp -o SLNode.o
	
SList.o: SList.cpp SList.h
	g++ -c $(FLAGS) SList.cpp -o SList.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc18