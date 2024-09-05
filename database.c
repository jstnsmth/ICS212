/******************************************************************
// 
// NAME:        Justin Smith
//
// HOMEWORK:    PROJECT 1
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        October 17, 2023
//
// FILE:        database.c
//
// DESCRIPTION: This file will correctly use the user_interface.c data to create a database of records for the user.
//
******************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "database.h"
extern int DEBUGMODE;

/******************************************************************
//  Function name: addRecord
//
//  DESCRIPTION:   Will add a record to the heap if the record doesn't already exist. The data structure of this record collection will be a linked list in the heap.
//                 addRecord will correctly position the new record in the correct spot for it to maintain its descending order.
//
//  Parameters:    start (struct record **) : points to the beginning of the record list
//                 accountNum (int)         : user account number
//                 name       (char[])      : user name
//                 address    (char[])      : user address
//
//  Return values: 0 : Successfully added
//                -1 : Not added
//
******************************************************************/

int addRecord(struct record ** start, int accountNum, char name[], char address[])
{
    int result = -2; /* Set to a temp number. Will never return this value */
    struct record * temp;
    struct record * curr;
    struct record * prev;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in addRecord function with following parameters:<<<\n");
        printf("DEBUG: struct record ** start: &start\n");
        printf("DEBUG: int accountNum:         %d\n", accountNum);
        printf("DEBUG: char name[]:            %s\n", name);
        printf("DEBUG: char address[]: \n%s\n", address);
    }

    if (*start == NULL)
    {
        temp = (struct record *)malloc(sizeof(struct record));
        temp->accountno = accountNum;
        strcpy(temp->name, name);
        strcpy(temp->address, address);
        temp->next = NULL;
        *start = temp;
        result = 0;
    }
    curr = *start;
    prev = NULL;

    while (curr != NULL && result == -2)
    {
        if (accountNum > curr->accountno)
        {
            temp = (struct record *)malloc(sizeof(struct record));
            temp->accountno = accountNum;
            strcpy(temp->name, name);
            strcpy(temp->address, address);
            temp->next = curr;

            if (prev == NULL) /* First record */
            {
                *start = temp;
            }
            else
            {
                prev->next = temp;
            }
            result = 0;
        }
        else if (accountNum == curr->accountno) /* Duplicate found */
        {
            result = -1;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    if (result == -2) /* Last record */
    {
        temp = (struct record *)malloc(sizeof(struct record));
        temp->accountno = accountNum;
        strcpy(temp->name, name);
        strcpy(temp->address, address);
        temp->next = NULL;
        prev->next = temp;
        result = 0;
    }

    if (DEBUGMODE == 1)
    {
        if (result == 0)
        {
            printf("DEBUG: Record was added. Return value: %d\n", result);
        }
        else
        {
            printf("DEBUG: Record was NOT added. Return value: %d\n", result);
        }
    }

    if (result == 0)
    {
        printf("Record was successfully added.\n");
    }
    else
    {
        printf("Record was not added.\n");
    }
    return result;
}

/******************************************************************
//  Function name: printAllRecords
//
//  DESCRIPTION:   Will print all the records in the linked list. This will be done by traversing the linked list and printing each of the records along with the data inside
//
//  Parameters:    start (struct record *) : beginning of the record list
//  
//  Return values: void
//
******************************************************************/

void printAllRecords(struct record * start)
{
    int counter = 1;
    struct record * curr;
    curr = start;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in printAllRecords function with following parameters:<<<\n");
        printf("DEBUG: struct record *: start\n");
    }

    printf("\nPrinting all records...\n");
    if (curr == NULL)
    {
        printf("\nThere are no records stored\n");
    }

    while (curr != NULL)
    {
        printf("\nRecord: %d\n", counter);
        printf("Account #: %d\n", curr->accountno);
        printf("Name: %s\n", curr->name);
        printf("Address:\n%s", curr->address);
        curr = curr->next;
        counter+=1;
    }
}

/******************************************************************
//  Function name: findRecord
//
//  DESCRIPTION:   Will traverse the linked list with the objective of finding a specific record with the account number that matches the user input.
//
//  Parameters:    start (struct record *) : beginning of the record list
//                 accountNum (int)        : user account number
//
//  Return values: 0 : the record was found
//                -1 : the record was not found
//
******************************************************************/

int findRecord(struct record * start, int accountNum)
{
    int result = -1;
    struct record * curr;
    curr = start;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in findRecord function with following parameters:<<<\n");
        printf("DEBUG: struct record *: start\n");
        printf("DEBUG: int accountNum:  %d\n", accountNum);
    }

    while (curr != NULL && result == -1)
    {
        if (curr->accountno == accountNum)
        {
            printf("\nRecord found!\n");
            printf("Account #: %d\n", curr->accountno);
            printf("Name: %s\n", curr->name);
            printf("Address:\n%s\n", curr->address);
            result = 0;
        }
        curr = curr->next;
    }
    if (result == -1)
    {
        printf("\nRecord does not exist\n");
    }

    if (DEBUGMODE == 1)
    {
        if (result == 0)
        {
            printf("DEBUG: Record was found. Return value: %d\n", result);
        }
        else
        {
            printf("DEBUG: Record was NOT found. Return value: %d\n", result);
        }
    }
    return result;
}

/******************************************************************
//  Function name: deleteRecord
//
//  DESCRIPTION:   Will traverse the linked list until it finds the record that matches the record that the user wants to remove.
//                 Then the function will deallocate the memory for that record and continue the descending order of the remaining records
//  
//  Parameters:    start (struct record **) : points to the beginning of the record list
//                 accountNum (int)         : user account number 
//
//  Return values: 0 : the record was successfully removed
//                -1 : the record was not found
//
******************************************************************/

int deleteRecord(struct record ** start, int accountNum)
{
    int result = -1;
    struct record * curr;
    struct record * prev;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in deleteRecord function with following parameters:<<<\n");
        printf("DEBUG: struct record ** start: &start\n");
        printf("DEBUG: int accountNum:         %d\n", accountNum);
    }

    if (start != NULL)
    {
        curr = *start;
        prev = NULL;
        while (curr != NULL && result == -1)
        {
            if (accountNum == curr->accountno)
            {
                if (prev == NULL)
                {
                    *start = curr->next;
                    free(curr);
                    result = 0;
                }
                else
                {
                    prev->next = curr->next;
                    free(curr);
                    result = 0;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    if (result == 0)
    {
        printf("\nRecord was successfully deleted\n");
    }
    else
    {
        printf("\nRecord does not exist\n");
    }

    if (DEBUGMODE == 1)
    {
        if (result == 0)
        {
            printf("\nDEBUG: Record was deleted. Return value: %d\n", result);
        }
        else
        {
            printf("\nDEBUG: Unsuccessful. Return value: %d\n", result);
        }
    }
    return result;
}

/******************************************************************
//  Function name: writefile
//
//  DESCRIPTION:   Saves the records into a file once the user chooses the quit option
//
//  Parameters:    start (struct record *) : beginning of record list
//                 filename (char [])      : the file name
//
//  Return values: 0 : success
//                -1 : fail
//
******************************************************************/

int writefile(struct record * start, char filename[])
{
    int result = 0;
    struct record * curr;
    FILE * filePointer;
    filePointer = fopen(filename, "w");
    curr = start;

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in writefile function with following parameters:<<<\n");
        printf("DEBUG: struct record * start: start\n");
        printf("DEBUG: char filename[]:       %s\n", filename);
    }

    if (filePointer != NULL)
    {
        while (curr != NULL)
        {
            fprintf(filePointer, "%d\n", curr->accountno);
            fprintf(filePointer, "%s\n", curr->name);
            fprintf(filePointer, "%s\n", curr->address);
            curr = curr->next;
        }
        fclose(filePointer);
    }
    else
    {
        result = -1;
    }

    if (DEBUGMODE == 1)
    {
        if (result == 0)
        {
            printf("\nDEBUG: Writing in file was successful. Return value: %d\n", result);
        }
        else
        {
            printf("\nDEBUG: Writing in file was unsuccessful. Return value: %d\n", result);
        }
    }
    return result;
}

/******************************************************************
//  Function name: readfile
//
//  DESCRIPTION:   Will retrive the records from the saved file and will be called once the prgoram begins. Will read the file and save the data into the record list
//
//  Parameters:    start (struct record **) : points to the beginning of the record list
//                 filname (char  [])       : the file name
//
//  
//  Return values: 0 : success
//                -1 : fail

******************************************************************/

int readfile(struct record ** start, char filename[])
{
    int result = 0;
    int tempaccountno = 0;
    char tempAddress[50];
    struct record * temp;
    struct record * curr;
    FILE * filePointer;
    filePointer = fopen(filename, "r");

    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in readfile function with following parameters:<<<\n");
        printf("DEBUG: struct record ** start: &start\n");
        printf("DEBUG: char filename[]:        %s\n", filename);
    }

    if (filePointer != NULL)
    {
        while (fscanf(filePointer, "%d", &tempaccountno) == 1)
        {
            temp = (struct record *)malloc(sizeof(struct record));
            temp->accountno = tempaccountno;
            fgetc(filePointer);
            fgets(temp->name, 30, filePointer);
            temp->name[strcspn(temp->name, "\n")] = '\0';
            while (strlen(tempAddress) != 1) /* Checking for line with only newline */
            {
                fgets(tempAddress, 50, filePointer);
                strncat(temp->address, tempAddress, 50 - strlen(temp->address) - 1);
            }
            strcpy(tempAddress, "");
            temp->address[strlen(temp->address) -1] = '\0'; /* Removing extra newline */
            temp->next = NULL;
            if (*start == NULL)
            {
                *start = temp;
                curr = *start;
            }
            else
            {
                curr->next = temp;
                curr = curr->next;
            }
        }
        fclose(filePointer);
    }
    else
    {
        result = -1;
    }

    if (DEBUGMODE == 1)
    {
        if (result == 0)
        {
            printf("\nDEBUG: Reading file was successful. Return value: %d\n", result);
        }
        else
        {
            printf("\nDEBUG: Reading file was unsuccessful. Return value: %d\n", result);
        }
    }
    return result;
}

/******************************************************************
//  Function name: cleanup
//
//  DESCRIPTION:   Will release all the allocated spaces in the heap memory and assign NULL to start.
//
//  Parameters:    start (struct record **) : points to the beginning of the record list
//
//  Return values: void
//
******************************************************************/

void cleanup(struct record ** start)
{
    struct record * curr;
    struct record * prev;
    curr = *start;
    if (DEBUGMODE == 1)
    {
        printf("\nDEBUG: >>>Currently in cleanup function with following parameters:<<<\n");
        printf("DEBUG: struct record ** start: &start\n");
    }

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    *start = NULL;

    if (DEBUGMODE == 1)
    {
        if (*start == NULL)
        {
            printf("\nDEBUG: Heap was cleared. Start successfully assigned to NULL\n");
        }
        else
        {
            printf("DEBUG: Start not assigned to NULL\n");
        }
    }
}
