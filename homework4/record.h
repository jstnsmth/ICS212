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
//  FILE:        record.h
//
//  DESCRIPTION: contains the struct of record
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
