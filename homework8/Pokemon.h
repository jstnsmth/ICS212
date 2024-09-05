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
//  FILE:        Pokemon.h
//
//  DESCRIPTION: Contains the abstract parent class called Pokemon which holds pokemon data. 
//               Has protected values of type and weight and public constructor, destructor 
//               and printData prototype. Destructor and printData are virtual.
//
******************************************************************/

#include <iostream>
#include <string>
using namespace std;

#ifndef POKEMON
#define POKEMON

class Pokemon
{
    protected:
        string type;
        float weight;

    public:
        Pokemon();
        virtual ~Pokemon();
        virtual void printData() = 0;
};

#endif
