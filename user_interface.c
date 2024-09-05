/******************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    PROJECT 1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 23, 2023
//
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//      This program will begin by prompting you to enter one of the following commands. I made a compare function that will compare the user input to the command and if the user input fits inside the conditions of the assignment,
//      it will pass and continue to prompt the user to input the relevant information in executing the command. It will then successfully call the functions from the database.c file with the information collected in the
//       user_interface.c file.
//      
******************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"
int DEBUGMODE = 0; /* Global variable */

/******************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   Will prompt the user to enter their address, if the user tries to make their address longer then the given size, it will prompt the user that they typed too many characters
//                 and to retry. Once the user enters their address and hits enter twice. Their input will be saved to the character array called address.
//
//  Parameters:    address (char {]) : Where the address information will be stored
//                 size    (int)     : Size of the address array
//
//  Return values: void
//
******************************************************************/

void getaddress(char address[], int size)
{
    int input, addressFull, charRead, i;
    int counter = 0; /* Amount of times user presses enter */

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in getaddress function with following parameters:<<<\n");
        printf("DEBUG: char address[]: %s\n", address);
        printf("DEBUG: int size: %d\n", size);
    }

    do
    {
        i = 0;
        addressFull = 0;

        printf("\nEnter your address: When you are done, hit enter twice\n>");
        input = fgetc(stdin);
        while (counter != 2 && !addressFull) /* Counter is how many times user hits enter */
        {
            counter = 0;
            if (input == '\n')
            {
                printf(">");
                counter++;
            }
            if (counter == 1)
            {
                if (i < size - 1) /* since needs room for '\0' character */
                {
                    address[i] = input;
                    i++;
                    input = fgetc(stdin);
                }
                else
                {
                    printf("\nAddress size limit reached. You can't enter more characters.\n");
                    while ((charRead = getchar()) != '\n')
                    {
                    }
                    addressFull = 1;
                }

                if (input == '\n')
                {
                    counter++;
                }
            }
            else
            {
                if (i < size - 1)
                {
                    address[i] = input;
                    i++;
                    input = fgetc(stdin);
                }
                else
                {
                    printf("\nAddress size limit reached. You can't enter more characters.\n");
                    while ((charRead = getchar()) != '\n')
                    {
                    }
                    addressFull = 1;
                }
            }
        }
        address[i] = '\0'; /* Making address into a 'string' */
    }
    while (strlen(address) >= size - 1);

    if (DEBUGMODE == 1)
    {
        printf("DEBUG: Final Address data:\n%s", address);
    }
}

/******************************************************************
//  
//  Function name: main
//
//  DESCRIPTION:   Prompts user to enter a command while successfully calling other functions to get the desired results.
//                 Makes sure that all data is entered in correctly and will prompt user to redo their input if theres an error.
//
//  Parameters:    argc (int) : number of arguements
//                 argv (char*[]): array of arguments
//
//  Return values: 0 : success
//
******************************************************************/

int main(int argc, char* argv[])
{
    int accountno, numRead, charRead, commandPass, commandFail, result, i, j;
    char input[20], name[30], address[50];
    char commands[5][9] = {"add", "printall", "find", "delete", "quit"};
    struct record * start = NULL;

    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        DEBUGMODE = 1;
        printf("\nDebug mode has been enabled.\n");
    }
    if (argc > 1 && DEBUGMODE == 0)
    {
        printf("Incorrectly called. Please execute: %s debug\n", argv[0]);
        result = -1;
    }
    else
    {
        readfile(&start, "records.txt");
        printf("\n***This is a bank database application where you will interact with the UI***\n");
        do
        {
            printf("\nType one of the following commands\n");
            printf("add:       Add a new record in the database\n");
            printf("printall:  Print all records in the database\n");
            printf("find:      Find record(s) with a specified account #\n");
            printf("delete:    Delete existing record(s) using a specified account #\n");
            printf("quit:      Quit the program\n");
            printf("\nEnter command:\n>");
            fgets(input, 20, stdin);
            input[strlen(input) - 1] = '\0';
            /* Algorithm for finding what choice user enters. */
            /* commandPass = 1 means add option commandPass = 2 means printall option and so on */
            /* commandPass = -1 means invalid command */
            i = 0;
            commandPass = -1;
            while (i < 5 && commandPass == -1)
            {
                commandFail = 0;
                if (strlen(commands[i]) >= strlen(input) && strlen(input) != 0)
                {
                    j = 0;
                    while (j < strlen(input) && commandFail == 0)
                    {
                        if (input[j] != commands[i][j])
                        {
                            commandFail = -1;
                        }
                        j+=1;
                    }
                    if (commandFail == 0)
                    {
                        commandPass = i+1;
                    }
                }
                i+=1;
            }

            if (commandPass == 1) /* add option */
            {
                printf("\nEnter account number:\n>");
                do
                {
                    numRead = scanf("%d", &accountno);
                    while (numRead != 1)
                    {
                        printf("\nERROR. Enter an integer:\n>");
                        while ((charRead = getchar()) != '\n')
                        {
                        }
                        numRead = scanf("%d", &accountno);
                    }
                    if (accountno <= 0)
                    {
                        printf("\nERROR. Enter a positive integer:\n>");
                    }
                }
                while (accountno <= 0);

                while ((charRead = getchar()) != '\n')
                {
                }
                printf("\nEnter name:\n>");
                fgets(name, 30, stdin);
                name[strlen(name) - 1] = '\0';
                strcpy(address, ""); /* making address empty incase of recall to the function */
                getaddress(address, 50);

                addRecord(&start, accountno, name, address);
            }

            else if (commandPass == 2) /* print option */
            {
                printAllRecords(start);
            }

            else if (commandPass == 3) /* find option */
            {
                printf("\nEnter account number:\n>");
                do
                {
                    numRead = scanf("%d", &accountno);
                    while (numRead != 1)
                    {
                        printf("\nERROR. Enter an integer:\n>");
                        while ((charRead = getchar()) != '\n')
                        {
                        }
                        numRead = scanf("%d", &accountno);
                    }
                    if (accountno <= 0)
                    {
                        printf("\nERROR. Enter a positive integer:\n>");
                    }
                }
                while (accountno <= 0);

                while ((charRead = getchar()) != '\n')
                {
                }

                findRecord(start, accountno);
            }

            else if (commandPass == 4) /* delete option */
            {
                printf("\nEnter account number:\n>");
                do
                {
                    numRead = scanf("%d", &accountno);
                    while (numRead != 1)
                    {
                        printf("\nERROR. Enter an integer:\n>");
                        while ((charRead = getchar()) != '\n')
                        {
                        }
                        numRead = scanf("%d", &accountno);
                    }
                    if (accountno <= 0)
                    {
                        printf("\nERROR. Enter a positive integer:\n>");
                    }
                }
                while (accountno <= 0);

                while ((charRead = getchar()) != '\n')
                {
                }

                deleteRecord(&start, accountno);
            }

            else if (commandPass == -1) /* Invalid user input */
            {
                printf("\nInput was not a command\n");
            }
        }
        while (commandPass != 5); /* 5 = quit option */

        writefile(start, "records.txt");
        cleanup(&start);
        result = 0;
    }

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: Quitting program. Return value : %d\n", result);
    }
    return result;
}
