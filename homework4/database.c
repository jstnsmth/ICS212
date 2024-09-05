/******************************************************************
// 
// NAME:        Justin Smith
//
// HOMEWORK:    3b
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
#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "database.h"

/******************************************************************
//  Function name: addRecord
//
//  DESCRIPTION:   Will add a record to the heap if the record doesn't already exist. The data structure of this record collection will be a linked list in the heap.
//                 addRecord will correctly position the new record in the correction spot for it to maintain its descending order.
//
//  Parameters:    list (struct record **) : this will be passed in as START which is our beginning of the record list
//                 accountNum (int)        : user account number
//                 name       (char[])     : user name
//                 address    (char[])     : user address
//
//  Return values: void
//
******************************************************************/

int addRecord(struct record **start, int accountNum, char name[], char address[])
{
    struct record* temp;
    struct record* curr;
    struct record* prev;
    int result = -2;
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

            if (prev == NULL)
            {
                *start = temp;
            }
            else
            {
                prev->next = temp;
            }
            result = 0;
        }
        if (accountNum == curr->accountno)
        {
            result = -1;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if (result == -2)
    {
        temp = (struct record *)malloc(sizeof(struct record));
        temp->accountno = accountNum;
        strcpy(temp->name, name);
        strcpy(temp->address, address);
        temp->next = NULL;
        prev->next = temp;
        result = 0;
    }
    return result;
}

/******************************************************************
//  Function name: printAllRecords
//
//  DESCRIPTION:   Will print all the records in the linked list. This will be done by traversing the linked list and printing each of the records along with the data inside
//
//  Parameters:    list (struct record *) : this is the beginning of the record list
//  
//  Return values: void
//
******************************************************************/

void printAllRecords(struct record *start)
{
    struct record* curr;
    curr = start;
    while (curr != NULL)
    {
        printf("%d\n", curr->accountno);
        curr = curr->next;
    }
}

/******************************************************************
//  Function name: findRecord
//
//  DESCRIPTION:   Will traverse the linked list with the objective of finding a specific record with the account number that matches the user input.
//
//  Parameters:    list (struct record *) : this is the beginning of the record list
//                 accountNum (int)       : user account number
//
//  Return values: 0 : the record was found
//                 -1 : the record was not found
//
******************************************************************/

int findRecord(struct record *start, int accountNum)
{
    struct record* curr;
    int result = -1;
    curr = start;
    while (curr != NULL && result == -1)
    {
        if (curr->accountno == accountNum)
        {
            result = 0;
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
//  Parameters:    list (struct record **) : this will passed in as START which is our beginning of the record list. This is the address of the pointer of struct record.
//                 accountNum (int)        : user account number 
//
//  Return values: 0 : the record was successfully removed
//                -1 : the record was not found
//
******************************************************************/

int deleteRecord(struct record **start, int accountNum)
{
    struct record* curr;
    struct record* prev;
    int result = -1;

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
    return result;
}
