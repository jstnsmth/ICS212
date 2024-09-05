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
//  FILE:        user_interface.cpp
//
//  DESCRIPTION: This program will begin by prompting you to enter one of the following commands.
//               Based on what the user enters, it will execute that command. The user is able to use
//               shortcuts to enter the commands. Will then prompt user to enter necessary information to
//               call the database function to give the user the proper data.
//
******************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include "llist.h"
using namespace std;

/******************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Prompts user to enter a command while sucessfully calling the llist class mmethods to
//                 get the desired results. Makes sure that all data is entered in correctly and will prompt
//                 user to redo tehir input if theres an error.
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values: 0 : success
//
******************************************************************/

int main(int argc, char* argv[])
{
    int commandPass, commandFail, i, accountno, counter;
    string input, line;
    char name[30], address[50] = {'\0'};
    size_t j;
    string commands[6] = {"add", "printall", "find", "delete", "copy", "quit"};
    llist database(const_cast<char *>("records.txt"));

#ifdef DEBUG
    cout << "\nDebug mode has been enabled.\n";
#endif

    cout << "\n***This is a bank database application where you will interact with the UI***\n";
    do
    {
        cout << "\nType one of the following commands" << endl;
        cout << "add:       Add a new record in the database" << endl;
        cout << "printall:  Print all records in the database" << endl;
        cout << "find:      Find record(s) with a specified account #" << endl;
        cout << "delete:    Delete existing record(s) using a specified account #" << endl;
        cout << "copy:      EXTRA CREDIT: Copying database to another database" << endl;
        cout << "quit:      Quit the program" << endl;
        cout << "\nEnter command:\n>";
        getline(cin, input);
        /* Algorithm for finding what choice user enters. */
        /* commandPass = 1 means add option commandPass = 2 means printall option and so on */
        /* commandPass = -1 means invalid command */
        i = 0;
        commandPass = -1;
        while (i < 6 && commandPass == -1)
        {
            commandFail = 0;
            if (commands[i].size() >= input.size() && input.size() != 0)
            {
                j = 0;
                while (j < input.size() && commandFail == 0)
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
            cout << "\nEnter account number:\n>";
            do
            {
                if (cin >> accountno)
                {
                    if (accountno <= 0)
                    {
                        cout << "\nERROR. Enter a positive integer:\n>";
                    }
                }
                else
                {
                    cout << "\nERROR. Enter an integer:\n>";
                    cin.clear();
                    while (cin.get() != '\n');
                }
            }
            while (accountno <= 0);
            cin.clear();
            while (cin.get() != '\n');
            do
            {
                cout << "\nEnter name:\n>";
                getline(cin, line);
                if (line.length() > 29) /* user inputted a name longer then 30 characters */
                {
                    cout << "\nYour name is too long. Max length is 30.";
                }
                else if (line.length() == 0)
                {
                    cout << "\nYou cannot leave this blank";
                }
                else
                {
                    strncpy(name, line.c_str(), 30);
                }
            }
            while (line.length() > 29 || line.length() == 0);

            strcpy(address, "");
            counter = 0;
            cout << "\nEnter you address: When you are done, hit enter twice\n>";
            while (counter != 1)
            {
                getline(cin, line);

                if (line.empty() && address[0] != '\0')
                {
                    counter = 1;
                }
                else if (strlen(address) + line.length() > 50)
                {
                    cout << "\nSize exceeded the 50 character limit. Re-enter your address.\n";
                    address[0] = '\0';
                    cout << ">";
                }
                else
                {
                    strncat(address, (line + '\n').c_str(), 50 - strlen(address) - 1);
                    cout << ">";
                }
            }
            database.addRecord(accountno, name, address);
        }
        else if (commandPass == 2) /* print option */
        {
            /* database.printAllRecords(); */
            cout << database; /* EXTRA CREDIT: overloading the << operator */
        }

        else if (commandPass == 3) /* find option */
        {
            cout << "\nEnter account number:\n>";
            do
            {
                if (cin >> accountno)
                {
                    if (accountno <= 0)
                    {
                        cout << "\nERROR. Enter a positive integer:\n>";
                    }
                }
                else
                {
                    cout << "\nERROR. Enter an integer:\n>";
                    cin.clear();
                    while (cin.get() != '\n');
                }
            }
            while (accountno <= 0);
            cin.ignore();
            database.findRecord(accountno);
        }

        else if (commandPass == 4) /* delete option */
        {
            cout << "\nEnter account number:\n>";
            do
            {
                if (cin >> accountno)
                {
                    if (accountno <= 0)
                    {
                        cout << "\nERROR. Enter a positive integer:\n>";
                    }
                }
                else
                {
                    cout << "\nERROR. Enter an integer:\n>";
                    cin.clear();
                    while (cin.get() != '\n');
                }
            }
            while (accountno <= 0);
            cin.ignore();
            database.deleteRecord(accountno);
        }

        else if (commandPass == 5) /* EXTRA CREDIT: copy option */
        {
            llist copyDatabase = database; /* using copy constructor */
            llist anotherDatabase;
            anotherDatabase = database; /* overloaded assignment operator */
        }

        else if (commandPass == -1) /* Invalid user input */
        {
            std::cout << "Input was not a command" << std::endl;
        }
    }
    while (commandPass != 6); /* 5 = quit option */

#ifdef DEBUG
    cout << "\nDEBUG: Quitting program. Return value: 0";
#endif
    return 0;
}
