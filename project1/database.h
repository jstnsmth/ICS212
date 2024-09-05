/******************************************************************
//  NAME:        Justin Smith
//
//  HOMEWORK:    PROJECT 1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 17, 2023
//
//  FILE:        database.h
//
//  DESCRIPTION: Contains the function prototypes that will be used in database.c
//
******************************************************************/

#include "record.h"
#ifndef DATABASE
#define DATABASE

int addRecord(struct record **, int, char[], char[]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);
int writefile(struct record *, char[]);
int readfile(struct record **, char[]);
void cleanup(struct record **);

#endif
