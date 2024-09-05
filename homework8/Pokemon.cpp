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
//  FILE:        Pokemon.cpp
//
//  DESCRIPTION: Will print output of when the Pokemon class is constructed and destructed.
//
******************************************************************/

#include "Pokemon.h"

/******************************************************************
//
//  Function name: Pokemon
//
//  DESCRIPTION:   Pokemon class constructor
//
//  Parameters:    None
//
//  Return values: None
//
******************************************************************/

Pokemon::Pokemon()
{
    cout << "Pokemon Constructor" << endl;
}

/******************************************************************
//
//  Function name: ~Pokemon
//
//  DESCRIPTION:   Pokemon class deconstructor
//
//  Parameters:    None
//
//  Return values: None
//
******************************************************************/

Pokemon::~Pokemon()
{
    cout << "Pokemon Destructor" << endl;
}
