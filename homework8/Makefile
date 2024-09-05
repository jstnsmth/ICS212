homework9: Pokemon.o Pikachu.o Squirtle.o Charmander.o main.o
	g++ -o homework9 Pokemon.o Pikachu.o Squirtle.o Charmander.o main.o

Pokemon.o: Pokemon.cpp
	g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp -o Pokemon.o

Pikachu.o: Pikachu.cpp
	g++ -ansi -pedantic-errors -Wall -c Pikachu.cpp -o Pikachu.o

Squirtle.o: Squirtle.cpp
	g++ -ansi -pedantic-errors -Wall -c Squirtle.cpp -o Squirtle.o

Charmander.o: Charmander.cpp
	g++ -ansi -pedantic-errors -Wall -c Charmander.cpp -o Charmander.o

main.o: main.cpp
	g++ -ansi -pedantic-errors -Wall -c main.cpp -o main.o

clean:
	rm -f Pokemon.o Pikachu.o Squirtle.o Charmander.o main.o homework9
