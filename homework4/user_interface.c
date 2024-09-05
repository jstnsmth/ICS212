/******************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    3b
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
int DEBUGMODE = 0; /* Global variable */

/******************************************************************
//
//  Function Name: compare
//
//  DESCRIPTION: Will compare the keyword to the command which is what the user will input. It checks to see if the input is greater than the command, if so the function will return false. Otherwise, it will go into a for loop
//  where it will compare each index of the keyword and command to see if they match. If everything matches and the length of input is <= command. Then it will return true.
//  Examples:
//      Keyword: quit Command: q returns true because length of input <= command and keyword[0] = command[0]
//      Keyword: quit Command: quitter returns false because length of input is GREATER than command.
//
//  Parameters:    keyword (char []) : The keyword
//                 command (char []) : The command
//  
//  Return values:  0 : success
//                  1 : fail
//
******************************************************************/

int compare(char keyword[], char command[])
{
    int i; /* iteration variable */
    int result = 1;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in compare function<<\n");
        printf("DEBUG: Keyword data: %s\n", keyword);
        printf("DEBUG: Command data: %s\n", command);
    }

    if (strlen(command) > strlen(keyword))
    {
        if (DEBUGMODE == 1)
        {
            printf("DEBUG: Command length is greater than keyword.\n");
        }
        result = 0; /* false */
    }
    else
    {
        for (i = 0; i < strlen(command); i++)
        {
            if (command[i] != keyword[i])
            {
                if (DEBUGMODE == 1)
                {
                    printf("DEBUG: Command does NOT pass keyword.\n");
                }
                result = 0;
            }
        }
    }
    if (DEBUGMODE == 1)
    {
        printf("DEBUG: Command passes keyword.\n");
    }
    return result; /* true */
}

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
    int input, addressFull, i, c, counter = 0;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in getaddress function<<<\n");
        printf("DEBUG: Address data: %s\n", address);
        printf("DEBUG: Size data: %d\n", size);
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
                    while ((c = getchar()) != '\n') /* clearing buffer */
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
                    while ((c = getchar()) != '\n') /* clearing buffer */
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
//  DESCRIPTION:   Prompts user to enter a command while successfully calling other functions to get the desired results. Makes sure that all data is entered in correctly and will prompt user to redo their input if theres an error.
//
//  Parameters:    argc (int) : number of arguements
//                 argv (char*[]): array of arguments
//
//  Return values: 0 : success
//
******************************************************************/

int main(int argc, char* argv[])
{
    char command[20], name[30], address[50] = "";
    int accountno, numRead, c;
    struct record * start = NULL;

    if (argc == 2 && strcmp(argv[1], "debug") == 0)
    {
        DEBUGMODE = 1;
        printf("\nDebug mode has been enabled.\n");
    }
    else if (argc > 1)
    {
        printf("Incorrectly called. Please execute: %s debug\n", argv[0]);
        return 1;
    }

    printf("\n***This is a bank database application where you will interact with the UI***\n\n");

    do
    {
        printf("Type one of the following commands\n\n");
        printf("add:       Add a new record in the database\n");
        printf("printall:  Print all records in the database\n");
        printf("find:      Find record(s) with a specified account #\n");
        printf("delete:    Delete existing record(s) from the database using the account # as a key\n");
        printf("quit:      Quit the program\n");
        printf("\nEnter command:\n>");
        fgets(command, 20, stdin);
        command[strlen(command) - 1] = '\0'; /* had issues with calling my compare function when I left this character in */

        if (compare("add", command))
        {
            printf("\nEnter account number:\n>");
            do
            {
                numRead = scanf("%d", &accountno);
                while (numRead != 1)
                {
                    printf("\nERROR. Enter an integer:\n>");
                    while ((c = getchar()) != '\n')
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

            while ((c = getchar()) != '\n')
            {
            }
            printf("\nEnter name:\n>");
            fgets(name, 30, stdin);
            name[strlen(name) - 1] = '\0';
            strcpy(address, ""); /* making address empty incase of recall to the function */
            getaddress(address, 50);

            if (DEBUGMODE == 1)
            {
                printf("\nDEBUG: Calling function addRecord with following data:\n");
                printf("DEBUG: struct record **\n");
                printf("DEBUG: accountno: %d\n", accountno);
                printf("DEBUG: name: %s\n", name);
                printf("DEBUG address: \n%s", address);
            }

            addRecord(&start, accountno, name, address);
        }

        else if (compare("printall", command))
        {
            if (DEBUGMODE == 1)
            {
                printf("DEBUG: Calling function printAllRecords with following data:\n");
                printf("DEBUG: struct record *\n");
            }
            printAllRecords(start);
        }

        else if (compare("find", command))
        {
            printf("\nEnter account number:\n>");
            do
            {
                numRead = scanf("%d", &accountno);
                while (numRead != 1)
                {
                    printf("\nERROR. Enter an integer:\n>");
                    while ((c = getchar()) != '\n')
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

            while ((c = getchar()) != '\n')
            {
            }
            if (DEBUGMODE == 1)
            {
                printf("DEBUG: Calling function findRecord with following data:\n");
                printf("DEBUG: struct record *\n");
                printf("DEBUG: accountno: %d\n", accountno);
            }

            findRecord(start, accountno);
        }

        else if (compare("delete", command))
        {
            printf("\nEnter account number:\n>");
            do
            {
                numRead = scanf("%d", &accountno);
                while (numRead != 1)
                {
                    printf("\nERROR. Enter an integer:\n>");
                    while ((c = getchar()) != '\n')
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

            while ((c = getchar()) != '\n')
            {
            }
            if (DEBUGMODE == 1)
            {
                printf("DEBUGMODE: Calling function deleteRecord with following data:\n");
                printf("DEBUG: struct record **\n");
                printf("DEBUG: accountno: %d\n", accountno);
            }

            deleteRecord(&start, accountno);
        }

        else if (!(compare("quit", command)))
        {
            printf("\nInput was not a command");
        }
    }
    while (!(compare("quit", command)));

    return 0;
}
