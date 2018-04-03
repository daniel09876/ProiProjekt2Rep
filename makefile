

run: main.o element.o list_of_stuff.o
	g++ main.o element.o list_of_stuff.o -o run

debug: main.o element.o list_of_stuff.o
	g++ main.o element.o list_of_stuff.o -g -o runD
	
element.o: element.hpp element.cpp 
	g++ -c element.cpp
	
list_of_stuff.o: list_of_stuff.cpp list_of_stuff.hpp
	g++ -c list_of_stuff.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
clean:
	rm *.o
