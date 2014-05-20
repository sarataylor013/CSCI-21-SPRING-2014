FLAGS = -Wall -Wextra -Werror -pedantic

pc21: pc21.o
	g++ $(FLAGS) pc21.o -o pc21


pc21.o: pc21.cpp box.h
	g++ -c $(FLAGS) pc21.cpp -o pc21.o

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc21