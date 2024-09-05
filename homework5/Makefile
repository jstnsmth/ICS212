homework5: iofunctions.o driver.o
	gcc -o homework5 iofunctions.o driver.o

iofunctions.o: iofunctions.c
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c -o iofunctions.o

driver.o: driver.c
	gcc -ansi -pedantic-errors -Wall -c driver.c -o driver.o

clean:
	rm -f iofunctions.o driver.o homework5

