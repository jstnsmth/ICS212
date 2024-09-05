/******************************************************************
//
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 31, 2023
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION: This program will ask for input from the user for a positive integer.
//               It will continue to prompt the user until a positive integer is entered.
//               Then it will output all the integers from 0 to the number the user entered
//               along with if the integer is even or odd.
//
******************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Prompts user for a number. Will continue to ask unless given a positive integer.
//                 Prompts user to input an integer if a different data type is entered.
//                 Prompts user to input a positive int if a negative int is given.
//
//  Parameters:    None
//
//  Return values: num : success
//
******************************************************************/

int user_interface()
{
    int num;
    std::cout << "*** Will print all numbers from 0 to number entered and odd or even ***\n";
    std::cout << "\nEnter maximum number to show: ";
    do
    {
        if (std::cin >> num)
        {
            if (num <= 0)
            {
                std::cout << "\nERROR. Enter a positive integer: ";
            }
        }
        else
        {
            std::cout << "\nERROR. Enter an integer: ";
            cin.clear();
            while (std::cin.get() != '\n');
        }
    }
    while (num <= 0);
    return num;
}

/******************************************************************
//
//  Function name: is_even
//
//  DESCRIPTION:   Takes in an integer and an integer reference. If the integer is even then the
//                 integer reference will be set to 1. else it will be set to 0.
//
//  Parameters:    num (int) : an integer value
//                 numReference (int&) : an integer reference variable
//
//  Return values: void
//
******************************************************************/

void is_even(int num, int& numReference)
{
    if (num % 2 == 0)
    {
        numReference = 1;
    }
    else
    {
        numReference = 0;
    }
}

/******************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Will print a correctly formatted list of integers starting from 0 and
//                 ending at the value the user inputted. Each of these values will also
//                 contain if its even or odd.
//
//  Parameters:    value (int) : an integer value
//
//  Return values: void
//
******************************************************************/

void print_table(int value)
{
    int i, j, numReference, lineSpace, digitCount;
    lineSpace = 0;
    digitCount = 1;
    std::cout << "  Number  Even or Odd?\n";
    for (i = 0; i <= value; i++)
    {
        if (i % digitCount == 0)
        {
            lineSpace+=1;
            digitCount*=10;
        }
        for (j = 0; j <= 7-lineSpace; j++)
        {
            std::cout << ' ';
        }
        std::cout << i;
        is_even(i, numReference);
        if (numReference == 1)
        {
            std::cout << "  Even\n";
        }
        else
        {
            std::cout << "   Odd\n";
        }
    }
}

/******************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Will properly call the other functoins to output the desired result.
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values: 0 : success
//
******************************************************************/

int main(int argc, char* argv[])
{
    print_table(user_interface());
    return 0;
}
