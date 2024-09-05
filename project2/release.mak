project: llist.o user_interface.o
	g++ -o project llist.o user_interface.o
	rm -f llist.o user_interface.o

llist.o: llist.cpp
	g++ -ansi -pedantic-errors -Wall -c llist.cpp -o llist.o

user_interface.o: user_interface.cpp
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp -o user_interface.o

clean:
	rm -f llist.o user_interface.o project_debug

