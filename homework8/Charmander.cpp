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
//  FILE:        Charmander.cpp
//
//  DESCRIPTION: Contains the function definition of printData. Along with
//               correctly assigning the Pokemon private values of Charmander
//               in the constructor. Also prints output when in the Charmander
//               constructor and destructor.
//
******************************************************************/

#include "Charmander.h"

/******************************************************************
//
//  Function name: Charmander
//
//  DESCRIPTION:   Assigns Fire to type, 18.7 to weight and prints
//                 confirmation that the Charmander constructor worked.
//
//  Parameters:    None
//
//  Return values: None
//
******************************************************************/

Charmander::Charmander()
{
    type = "Fire";
    weight = 18.7;
    cout << "Charmander Constructor" << endl;
}

/******************************************************************
//
//  Function name: ~Charmander
//
//  DESCRIPTION:   Prints output confirming that the Charmander destructor worked.
//
//  Parameters:    None
//
//  Return values: None
//
******************************************************************/

Charmander::~Charmander()
{
    cout << "Charmander Destructor" << endl;
}

/******************************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   Prints the data of Charmander. Begins with printing the name
//                 then pirnts the type, and finally the weight along with lbs.
//
//  Parameters:    None
//
//  Return values: void
//
******************************************************************/

void Charmander::printData()
{
    cout << "Name: Charmander" << endl;
    cout << "Type: " << type << endl;
    cout << "Weight: " << weight << " lbs" << endl;
}
