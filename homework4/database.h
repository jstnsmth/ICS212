/******************************************************************
//  NAME:        Justin Smith
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 17, 2023
//
//  FILE:        database.h
//
//  DESCRIPTION: contains the function prototypes that will be used in database.c
//
******************************************************************/

#ifndef DATABASE
#define DATABASE

int addRecord(struct record **, int, char[], char[]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);

#endif
