FLAGS = -Wall -Wextra -Werror -pedantic

pc29: treasurechest.o pc29.o
	g++ $(FLAGS) pc29.o treasurechest.o -o pc29

pc29.o: pc29.cpp
	g++ $(FLAGS) -c pc29.cpp -o pc29.o

treasurechest.o: treasurechest.cpp treasurechest.h
	g++ -c $(FLAGS) treasurechest.cpp -o treasurechest.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc29