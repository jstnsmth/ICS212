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
//  FILE:        record.h
//
//  DESCRIPTION: Contains the struct of record
//
******************************************************************/

#ifndef RECORD
#define RECORD

struct record
{
    int accountno;
    char name[30];
    char address[50];
    struct record* next;
};

#endif
