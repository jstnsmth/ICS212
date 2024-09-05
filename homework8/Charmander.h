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
//  FILE:        Charmander.h
//
//  DESCRIPTION: Contains the Charmander class which inherits the Pokemon class.
//               Has a constructor, destructor and function prototype printData.
//
******************************************************************/

#include "Pokemon.h"

#ifndef CHARMANDER
#define CHARMANDER

class Charmander : public Pokemon
{
    public:
        Charmander();
        ~Charmander();
        void printData();
};

#endif
