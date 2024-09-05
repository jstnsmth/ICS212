/******************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    PROJECT 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 25, 2023
//
//  FILE:        llist.cpp
//
//  DESCRIPTION: This file will correctly use the user_interface.cpp data to create
//               a database of records for the user.
//
******************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include "llist.h"
using namespace std;

/******************************************************************
//  
//  Function name: llist
//
//  DESCRIPTION:   Will be the default constructor for the llist class with no parameters.
//                 Sets start to null.
//
//  Parameters:    None
//
//  Return Values: None
//
******************************************************************/

llist::llist()
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in llist constructor with no parameters<<<\n";
#endif
    start = NULL;
}

/******************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   Will be the constructor for the llist class if there is one parameter
//                 which is the filename. Will set start to NULL, copy the parameter to the filename
//                 and then call readfile which uses that filename to read the file.
//
//  Parameters:    file (char[]) : the file name
//
//  Return Values: None
//
******************************************************************/

llist::llist(char file[])
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in llist constructor with following parameters:<<<\n";
    cout << "DEBUG: file (char[]) : " << file << endl;
#endif
    start = NULL;
    strncpy(filename, file, sizeof(filename) - 1);
    readfile();
}

/******************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   This is the copy constructor. Will set start to null, then copy the copy.filename
//                 to the filename. Will then call readfile to read the file containing that filename
//
//  Parameters:    copy (llist&) : reference to an object of the class llist
//
//  Return Values: None
//
******************************************************************/

llist::llist(llist& copy)
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in llist constructor with following parameters:<<<\n";
    cout << "DEBUG: copy (llist&) : " << copy << endl;
#endif
    start = NULL;
    strncpy(filename, copy.filename, sizeof(filename) - 1);
    readfile();
}

/******************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   This is the deconstructor. Will call writefile and cleanup.
//
//  Parameters:    None
//
//  Return Values: None
//
******************************************************************/

llist::~llist()
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in llist deconstructor with no parameters<<<\n";
#endif
    writefile();
    cleanup();
}

/******************************************************************
//
//  Function name: operator= 
//
//  DESCRIPTION: This is the overload assignment operator for the llist class.
//               Copies the content of another llist 'copy' while checking that
//               no self-assignment happens.
//
//  Parameters:  copy (const llist&) : Reference to the llist object to be copied.
//
//  Return Values: Reference to the changed llist object.
//
******************************************************************/

llist& llist::operator=(const llist& copy)
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in assignment overload operator with following parameters:<<<\n";
    cout << "DEBUG: copy (const llist&) : " << copy << endl;
#endif
    if (this != &copy)
    {
        writefile();
        cleanup();
        strncpy(filename, copy.filename, sizeof(filename) - 1);
        readfile();
    }
#ifdef DEBUG
    cout << "DEBUG: Return value: " << *this << endl;
#endif
    return *this;
}

/******************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   This is used to overloaad the << operator to print the contents
//                 of the entire database so that it replaces the function call of
//                 printAllRecords in the user-interface. Outputs the content of the llist
//                 object to the specified output stream.
//
//  Parameters:    output   (ostream&)     : Reference to the output stream.
//                 database (const llist&) : Reference to the llist object that will be printed
//
//  Return values: Reference to the output stream.
//
******************************************************************/

ostream& operator<<(ostream& output, const llist& database)
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in << overload operator with following parameters:<<<\n";
    cout << "DEBUG: output   (ostream&)     : " << &output << endl;
    cout << "DEBUG: database (const llist&) : " << &database << endl;
#endif
    int counter = 1;
    record * curr = database.start;

    output << "\nPrinting all records...\n";
    if (curr == NULL)
    {
        output << "\nThere are no records stored\n";
    }
    while (curr != NULL)
    {
        output << "\nRecord: " << counter << endl;
        output << "Account #: " << curr->accountno << endl;
        output << "Name: " << curr->name << endl;
        output << "Address:\n" << curr->address;
        curr = curr->next;
        counter += 1;
    }
#ifdef DEBUG
    cout << "\nDEBUG: Return value: " << &output << endl;
#endif
    return output;
}

/******************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Will add a record to the heap if the record doesn't already exist.
//                 The data structure of this record collection will be a linked list
//                 in the heap. addRecord will correctly position the new record in the
//                 correct spot for it to maintain its descending order.
//
//  Parameters:    accountNum (int)    : user account number
//                 name       (char[]) : user name
//                 address    (char[]) : user address
//
//  Return values: 0 : Successfully added
//                -1 : Not added
//
******************************************************************/

int llist::addRecord(int accountNum, char name[], char address[])
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in addRecord function with following parameters:<<<\n";
    cout << "DEBUG: accountNum (int)    : " << accountNum << endl;
    cout << "DEBUG: name       (char[]) : " << name << endl;
    cout << "DEBUG: address    (char[]) :\n" << address;
#endif
    int result = -2;
    record * temp = NULL;
    record * curr = start;
    record * prev = NULL;

    if (start == NULL)
    {
        temp = new record;
        temp->accountno = accountNum;
        strcpy(temp->name, name);
        strcpy(temp->address, address);
        temp->next = NULL;
        start = temp;
        result = 0;
    }
    else
    {
        while (curr != NULL && result == -2)
        {
            if (accountNum > curr->accountno)
            {
                temp = new record;
                temp->accountno = accountNum;
                strcpy(temp->name, name);
                strcpy(temp->address, address);
                temp->next = curr;

                if (prev == NULL)
                {
                    start = temp;
                }
                else
                {
                    prev->next = temp;
                }
                result = 0;
            }
            else if (accountNum == curr->accountno)
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
            temp = new record;
            temp->accountno = accountNum;
            strcpy(temp->name, name);
            strcpy(temp->address, address);
            temp->next = NULL;
            prev->next = temp;
            result = 0;
        }
    }
#ifdef DEBUG
    cout << "DEBUG: Return value: " << result << endl;
#endif
    return result;
}

/******************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Will print all the records in the linked list. This will
//                 be done by traversing the linked list and printing each
//                 of the records along with the data inside.
//
//  Parameters:    None
//
//  Return values: void
//
******************************************************************/

void llist::printAllRecords()
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in printAllRecords function with no parameters<<<\n";
#endif
    int counter = 1;
    record * curr;
    curr = start;

    cout << "\nPrinting all records...\n";
    if (curr == NULL)
    {
        cout << "\nThere are no records stored\n";
    }

    while (curr != NULL)
    {
        cout << "\nRecord: " << counter << endl;
        cout << "Account #: " << curr->accountno << endl;
        cout << "Name: " << curr->name << endl;
        cout << "Address:\n" << curr->address;
        curr = curr->next;
        counter+=1;
    }
}

/******************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Will traverse the linked list with the objective of finding
//                 a specific record with the account number that matches the
//                 user input.
//
//  Parameters:    accountNum (int) : user account number
//
//  Return values: 0 : the record was found
//                -1 : the record was not found
//
******************************************************************/

int llist::findRecord(int accountNum)
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in findRecord function with following parameters<<<\n";
    cout << "DEBUG: accountNum (int) : " << accountNum << endl;
#endif
    int result = -1;
    record * curr;
    curr = start;

    while (curr != NULL && result == -1)
    {
        if (curr->accountno == accountNum)
        {
            cout << "\nRecord found!\n";
            cout << "Account #: " << curr->accountno << endl;
            cout << "Name : " << curr->name << endl;
            cout << "Address:\n" << curr->address << endl;
            result = 0;
        }
        curr = curr->next;
    }
    if (result == -1)
    {
        cout << "\nRecord does not exist\n";
    }
#ifdef DEBUG
    cout << "DEBUG: Return value : " << result << endl;
#endif
    return result;
}

/******************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Will traverse the linked list until it finds the record that 
//                 matches the record that the user wants to remove. Then the function
//                 will deallocate the memory for that record and continue the descending
//                 order of the remaining records.
//
//  Parameters:    accountNum (int) : user account number
//
//  Return values: 0 : the record was successfully removed
//                -1 : the record was not found
//
******************************************************************/

int llist::deleteRecord(int accountNum)
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in deleteRecord function with following parameters:<<<\n";
    cout << "DEBUG: accountNum (int) : " << accountNum << endl;
#endif
    int result = -1;
    record * curr;
    record * prev;

    if (start != NULL)
    {
        curr = start;
        prev = NULL;
        while (curr != NULL && result == -1)
        {
            if (accountNum == curr->accountno)
            {
                if (prev == NULL)
                {
                    start = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                result = 0;
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
        cout << "\nRecord was successfully deleted\n";
    }
    else
    {
        cout << "\nRecord does not exist\n";
    }
#ifdef DEBUG
    cout << "DEBUG: Return value: " << result << endl;
#endif
    return result;
}

/******************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Saves the records into a file once the user chooses the quit option.
//                 Will call the writefile in the deconstructor.
//
//  Parameters:    None
//
//  Return values: 0 : success
//                -1 : fail
//
******************************************************************/

int llist::writefile()
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in writefile function with no parameters<<<\n";
    cout << "DEBUG: Attempting to write to file: " << filename << endl;
#endif
    int result = 0;
    ofstream file(filename);
    record * curr;

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        result = -1;
    }
    else
    {
        curr = start;
        while (curr != NULL)
        {
            file << curr->accountno << '\n';
            file << curr->name << '\n';
            file << curr->address << '\n';
            curr = curr->next;
        }
        file.close();
    }
#ifdef DEBUG
    cout << "DEBUG: Return value : " << result << endl;
#endif
    return result;
}

/******************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Will retrive the records from the saved file and will be called
//                 in the constructor. Will read the file and save the data into the record list
//
//  Parameters:    None
//
//  Return values: 0 : success
//                -1 : fail
//
******************************************************************/

int llist::readfile()
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in readfile function with no parameters<<<\n";
    cout << "DEBUG: Attempting to read file: " << filename << endl;
#endif
    int result = 0;
    int tempaccountno;
    char tempAddress[50];
    ifstream file(filename);
    record * temp;
    record * curr;

    if (!file.is_open())
    {
        cout << "Error reading file" << filename << endl;
        result = -1;
    }
    else
    {
        while (file >> tempaccountno)
        {
            temp = new record;
            temp->accountno = tempaccountno;
            file.ignore();
            file.getline(temp->name, 30);
            while (file.getline(tempAddress, 50) && strlen(tempAddress) != 0)
            {
                strncat(temp->address, tempAddress, 50 - strlen(temp->address) - 2);
                strncat(temp->address, "\n", 1);
            }
            temp->next = NULL;
            if (start == NULL)
            {
                start = temp;
                curr = start;
            }
            else
            {
                curr->next = temp;
                curr = curr->next;
            }
        }
        file.close();
    }
#ifdef DEBUG
    cout << "DEBUG: Return value: " << result << endl;
#endif
    return result;
}

/******************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Will release all the allocated spaces in the heap memory and assign NULL to start.
//
//  Parameters:    None
//
//  Return values: void
//
******************************************************************/

void llist::cleanup()
{
#ifdef DEBUG
    cout << "\nDEBUG: >>>Currently in cleanup function with no parameters<<<\n";
#endif
    record * curr;
    record * prev;
    curr = start;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    start = NULL;
#ifdef DEBUG
    if (start == NULL)
    {
        cout << "\nDEBUG: Heap was cleared. Start successfully assigned to NULL\n";
    }
    else
    {
        cout << "\nDEBUG: Start not assigned to NULL\n";
    }
#endif
}
