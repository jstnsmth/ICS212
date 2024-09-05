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
//  FILE:        llist.h
//
//  DESCRIPTION: Contains the llist class along with method prototypes, constructors, destructor,
//               and variables in private and public fields
//
******************************************************************/

#include <iostream>
#include "record.h"
#ifndef LLIST
#define LLIST

class llist
{
private:
    record * start;
    char filename[20];
    int readfile();
    int writefile();
    void cleanup();
public:
    llist();
    llist(char[]);
    llist(llist&);
    ~llist();
    llist& operator=(const llist&);
    int addRecord(int, char[], char[]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    friend std::ostream& operator<<(std::ostream&, const llist&);
};

#endif
