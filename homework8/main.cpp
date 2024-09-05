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
//  FILE:        main.cpp
//
//  DESCRIPTION: Used to run and test the pokemon created in seperate files
//               using instances of child classes in heap memory.
//
******************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Pokemon.h"
#include "Pikachu.h"
#include "Squirtle.h"
#include "Charmander.h"
using namespace std;

/******************************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   Calls the polymorphic function, printData, of the given pokemon
//                 and prints a newline for a nicer look.
//  
//  Parameters:    pokemon (Pokemon *) : Points to the pokemon address stored in the heap.
//
//  Return values: void
//
******************************************************************/

void checkPokedex(Pokemon *pokemon)
{
    cout << "Found at address: " << pokemon << endl;
    pokemon->printData();
    cout << endl;
}

/******************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Creates instances of all the child classes in the heap memory and
//                 stores their addresses in pointers of Pokemon. Give a nickname to
//                 each of your pokemons. Creates a vector container and stores the three
//                 nicknames. Creates a map container which stores a Pokemon pointer
//                 by its corresponding nickname as a key. Shows that everything works
//                 by using each element of the vector container to accress the corresponding
//                 item stored in the map container.
//
//  Parameters:    argc (int)     : number of arguments
//                 argv (char*[]) : array of arguments
//
//  Return values: 0 : success
//
******************************************************************/

int main(int argc, char* argv[])
{
    Pokemon *pikachu = new Pikachu();
    Pokemon *squirtle = new Squirtle();
    Pokemon *charmander = new Charmander();

    cout << "\nMemory Addresses of Pokemon on Heap:" << endl;
    cout << "Pikachu: " << pikachu << endl;
    cout << "Squirtle: " << squirtle << endl;
    cout << "Charmander: " << charmander << endl;

    string pikachuNickname = "Zappy";
    string squirtleNickname = "Riptide";
    string charmanderNickname = "Blaze";

    vector<string> nicknames;
    nicknames.push_back(pikachuNickname);
    nicknames.push_back(squirtleNickname);
    nicknames.push_back(charmanderNickname);

    map<string, Pokemon*> pokedex;
    pokedex[pikachuNickname] = pikachu;
    pokedex[squirtleNickname] = squirtle;
    pokedex[charmanderNickname] = charmander;

    cout << endl;

    for (vector<string>::const_iterator it = nicknames.begin(); it != nicknames.end(); ++it)
    {
        const string& nickname = *it;
        cout << "Checking Pokedex for Pokemon with key: " << nickname << endl;
        checkPokedex(pokedex[nickname]);
    }

    delete pikachu;
    delete squirtle;
    delete charmander;

    return 0;
}
