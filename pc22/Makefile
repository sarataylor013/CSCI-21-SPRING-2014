FLAGS = -Wall -Wextra -Werror -pedantic

pc22: cleanall SLNode.h SList.h pc22.o
	g++ $(FLAGS) pc22.o SList.h SLNode.h -o pc22

pc22.o: pc22.cpp 
	g++ $(FLAGS) -c pc22.cpp -o pc22.o

SLNode.o: SLNode.h
	g++ -c $(FLAGS) SLNode.h -o SLNode.o

SList.o: SList.h
	g++ -c $(FLAGS) SList.h -o SList.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc22