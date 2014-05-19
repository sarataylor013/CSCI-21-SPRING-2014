FLAGS = -Wall -Wextra -Werror -pedantic

pc28: item.o fooditem.o magicitem.o pc28.o
	g++ $(FLAGS) pc28.o item.o fooditem.o magicitem.o -o pc28

pc28.o: pc28.cpp
	g++ $(FLAGS) -c pc28.cpp -o pc28.o

item.o: item.cpp item.h
	g++ -c $(FLAGS) item.cpp -o item.o
	
fooditem.o: fooditem.cpp fooditem.h
	g++ -c $(FLAGS) fooditem.cpp -o fooditem.o
	
magicitem.o: magicitem.cpp magicitem.h
	g++ -c $(FLAGS) magicitem.cpp -o magicitem.o	

clean:
	rm -f *o
	
cleanall: clean
	rm -f pc28