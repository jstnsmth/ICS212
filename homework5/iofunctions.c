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
//  FILE:        iofunctions.c
//
//  DESCRIPTION: Contains two functions: - one will read a file and copy the contents of that file into an array of pokemon
//                                       - one will write into a file the contents of the pokemon array
//
******************************************************************/

#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#include "iofunctions.h"

/******************************************************************
//  
//  Function name: writefile
//
//  DESCRIPTION:   This function will open a file and write contents of the pokemon array.
//                 It will go through each pokemon in the array and print the level first and then the name on the next line.
//
//  Parameters:    pokearray (struct pokemon[]) : Array of pokemon
//                 num (int) : Number of pokemon space in the array.
//                 filename (char[]) : The file name the function will write to
//
//  Return values: 0 : Success
//                -1 : Fail, could not open file correctly.
//
******************************************************************/

int writefile(struct pokemon pokearray[], int num, char filename[])
{
    FILE * filePointer;
    int counter;
    int result = 0;
    filePointer = fopen(filename, "w");
    if (filePointer != NULL)
    {
        counter = 0;
        while (counter < num)
        {
            fprintf(filePointer, "%d\n", pokearray[counter].level);
            fprintf(filePointer, "%s", pokearray[counter].name);

            if (counter < num - 1)
            {
                fprintf(filePointer, "\n");
            }
            counter++;
        }
        fclose(filePointer);
    }
    else
    {
        result = -1;
    }
    return result;
}

/******************************************************************
//  
//  Function name: readfile
//
//  DESCRIPTION:   This function will read the contents from a file and store the data. The file will be in a specific format such that
//                 the level will be on one line and on the next line will be a name on so forth. This function will read each line,
//                 store the data and assign it correctly to the pokemon array. It will continue to do this until it either gets to the
//                 end of the file or fills up the array. It will then update the value of how many pokemon are in the array.
//
//  Parameters:    pokearray (struct pokemon[]) : Array of pokemon
//                 num (int *) : Points to the number of pokemon in the array. (Pointer used to update the value in the function)
//                 filename (char[]) : The file name the function will read from
//
//  Return values: 0 : Success
//                -1 : Fail, could not open file correctly.
//
******************************************************************/

int readfile(struct pokemon pokearray[], int* num, char filename[])
{
    FILE * filePointer;
    int counter;
    int result = 0;
    filePointer = fopen(filename, "r");

    if (filePointer != NULL)
    {
        int level;
        char name[20];
        counter = 0;
        while ((fscanf(filePointer, "%d", &level) == 1) && counter < *num)
        {
            fgetc(filePointer);
            fgets(name, 20, filePointer);
            name[strlen(name) - 1] = '\0';
            pokearray[counter].level = level;
            strcpy(pokearray[counter].name, name);
            counter++;
        }
        fclose(filePointer);
        *num = counter;
    }
    else
    {
        result = -1;
    }
    return result;
}
