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
//  FILE:        Pikachu.cpp
//
//  DESCRIPTION: Contains the function definition of printData. Along with
//               correctly assigning the Pokemon private values of Pikachu
//               in the constructor. Also prints output when in the
//               pikachu constructor and destructor.
//
******************************************************************/

#include "Pikachu.h"

/******************************************************************
//
//  Function name: Pikachu
//
//  DESCRIPTION:   Assigns Electric to type, 13.2 to weight and prints
//                 output confirming that the Pikachu constructor worked.
//  
//  Parameters:    None
//
//  Return values: None
//
******************************************************************/

Pikachu::Pikachu()
{
    type = "Electric";
    weight = 13.2;
    cout << "Pikachu Constructor" << endl;
}

/******************************************************************
//
//  Function name: ~Pikachu
//
//  DESCRIPTION:   Prints output confirming that the pikachu destructor worked.
//
//  Parameters:    None
//
//  Return values: None
//
******************************************************************/

Pikachu::~Pikachu()
{
    cout << "Pikachu Destructor" << endl;
}

/******************************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   Prints the data of Pikachu. Begins with printing the name
//                 then prints the type, and finally the weight along with
//                 lbs.
//
//  Parameters:    None
//
//  Return values: void
//
******************************************************************/

void Pikachu::printData()
{
    cout << "Type: Pikachu" << endl;
    cout << "Type: " << type << endl;
    cout << "Weight: " << weight << " lbs" << endl;
}
