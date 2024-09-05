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
//  FILE:        Pikachu.h
//
//  DESCRIPTION: Contains the Pikachu class which inherits the Pokemon class. Has a constructor,
//               destructor and function prototype printData.
//
******************************************************************/

#include "Pokemon.h"

#ifndef PIKACHU
#define PIKACHU

class Pikachu : public Pokemon
{
    public:
        Pikachu();
        ~Pikachu();
        void printData();
};

#endif
