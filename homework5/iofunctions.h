/******************************************************************
//  
//  NAME:        Justin Smith
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 5, 2023
//
//  FILE:        iofunctions.h
//
//  DESCRIPTION: Contains two function prototypes
//
******************************************************************/

#ifndef IOFUNCTIONS_H
#define IOFUNCTIONS_H

int writefile(struct pokemon pokearray[], int num, char filename[]);
int readfile(struct pokemon pokearray[], int* num, char filename[]);

#endif
