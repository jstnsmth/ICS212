/******************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 1, 2023
//
//  FILE:        Squirtle.h
//
//  DESCRIPTION: Contains the Squirtle class which inheirts the Pokemon class. Has a constructor,
//               deconstructor and functoin prototype printData.
//
******************************************************************/

#include "Pokemon.h"

#ifndef SQUIRTLE
#define SQUIRTLE

class Squirtle : public Pokemon
{
    public:
        Squirtle();
        ~Squirtle();
        void printData();
};

#endif
