project: database.o user_interface.o
	gcc -o project database.o user_interface.o

database.o: database.c
	gcc -ansi -pedantic-errors -Wall -c database.c -o database.o

user_interface.o: user_interface.c
	gcc -ansi -pedantic-errors -Wall -c user_interface.c -o user_interface.o

clean:
	rm -f user_interface.o database.o project
	 
