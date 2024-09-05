/******************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 5, 2023
//
//  FILE:        driver.c
//
//  DESCRIPTION: This file will be used to test the functions in the iofunctions.c file.
//
******************************************************************/

#include <stdio.h>
#include "pokemon.h"
#include "iofunctions.h"

/******************************************************************
//  
//  FUNCTION NAME:  main
//
//  DESCRIPTION:    Function will create a pokemon array along with an int which will hold the value of the size.
//                  Then the function will use this information to call upon the two functions from iofunctions.c
//                  showing what the code does, what function is called, the parameters, the return value and
//                  the results.
//
//  PARAMETERS:     argc (int) : The number of elements in argv
//                  argv (char*[]) : An array of arguments passed
//  
//  RETURN VALUES: 0 : SUCCESS
//
******************************************************************/

int main(int argc, char* argv[])
{
    struct pokemon pokemonbank[5];
    struct pokemon pokemonbankTWO[20];
    int numpokemons = 5;
    int i;
    int testLoop;
    int readFile;
    int writeFile;

    printf("\nTEST ONE: Testing incorrect function call to readfile\n");
    printf("Calling function readfile with NONEXISTENT file with following information:\n");
    printf("struct pokemon pokearray[] : pokemonbank (size 5)\n");
    printf("int * num                  : numpokemons (value of %d)\n", numpokemons);
    printf("char filename[]            : \"fakefile.txt\"\n");

    if (readfile(pokemonbank, &numpokemons, "fakefile.txt") == -1)
    {
        printf("Call to function readfile FAILED\n");
        printf("Function readfile returned: -1\n");
    }

    for (testLoop = 1; testLoop <= 2; testLoop++)
    {
        if (testLoop == 1)
        {
            printf("\nTEST TWO PART A: ");
            printf("Testing correct function call to readfile ");
            printf("with file containing MORE pokemon then array can hold\n");
        }

        if (testLoop == 2)
        {
            printf("\nTEST THREE PART A: ");
            printf("Testing correct function call to readfile ");
            printf("to hold LESS then the max amount pokebank can hold\n");
            numpokemons = 20;
        }

        printf("Calling function readfile with EXISTENT file with following information:\n");

        if (testLoop == 1)
        {
            printf("struct pokemon pokearray[] : pokemonbank (size 5)\n");
        }

        if (testLoop == 2)
        {
            printf("struct pokemon pokearray[] : pokemonbankTWO (size 20)\n");
        }

        printf("int * num                  : numpokemons (value of %d)\n", numpokemons);
        printf("char filename[]            : \"pokemoninput.txt\"\n");
        printf("Number of pokemon in the pokebank BEFORE function: %d\n", numpokemons);

        if (testLoop == 1)
        {
            readFile = readfile(pokemonbank, &numpokemons, "pokemoninput.txt");
        }

        if (testLoop == 2)
        {
            readFile = readfile(pokemonbankTWO, &numpokemons, "pokemoninput.txt");
        }

        if (readFile == 0)
        {
            printf("Number of pokemon in the pokebank AFTER function: %d\n", numpokemons);
            printf("Call to readfile function SUCCEEDED\n");
            printf("List of pokemon in pokebank:\n");
            for (i = 0; i < numpokemons; i++)
            {
                if (testLoop == 1)
                {
                    printf("Pokemon %d\n", i+1);
                    printf("    Level: %d\n", pokemonbank[i].level);
                    printf("    Name: %s\n", pokemonbank[i].name);
                }

                if (testLoop == 2)
                {
                    printf("Pokemon %d\n", i+1);
                    printf("    Level: %d\n", pokemonbankTWO[i].level);
                    printf("    Name: %s\n", pokemonbankTWO[i].name);
                }
            }
            printf("Function readfile returned: 0\n");
        }
        else
        {
            printf("Call to readfile function was UNSUCCESSFUL\n");
            printf("Function readfile returned: -1\n");
        }

        if (testLoop == 1)
        {
            printf("\nTEST TWO PART B: Testing function call to writefile\n");
        }

        if (testLoop == 2)
        {
            printf("\nTEST THREE PART B:");
            printf(" Testing function call to writefile to OVERRIDE previous text with new text\n");
        }

        printf("Calling function writefile with following information:\n");

        if (testLoop == 1)
        {
            printf("struct pokemon pokearray[] : pokebank (size 5)\n");
        }

        if (testLoop == 2)
        {
            printf("struct pokemon pokearray[] : pokebankTWO (size 20)\n");
        }

        printf("struct pokemon pokearray[] : pokebank (size 5)\n");
        printf("int num                     : numpokemons (value of %d)\n", numpokemons);
        printf("char filename[]             : \"pokemonoutput.txt\"\n");

        if (testLoop == 1)
        {
            writeFile = writefile(pokemonbank, numpokemons, "pokemonoutput.txt");
        }

        if (testLoop == 2)
        {
            writeFile = writefile(pokemonbankTWO, numpokemons, "pokemonoutput.txt");
        }

        if (writeFile == 0)
        {
            printf("Call to writefile function SUCCEEDED\n");
            printf("Function writefile returned: 0\n\n");
        }
        else
        {
            printf("Call to writefile function FAILED\n");
            printf("Function writefile returned: -1\n");
        }
    }
    return 0;
}
