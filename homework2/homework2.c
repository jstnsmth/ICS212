/*****************************************************************
//
//  NAME:        Justin Smith
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 6, 2023
//
//  FILE:        homework2.c
//
//  DESCRIPTION: 
//  This program will ask for input from the user for a positive integer. It will continue to prompt the user until a positive integer is entered. Then it will output all the integers from 0 to the number the user entered along with
//  if the integer is even or odd.
//
//
*****************************************************************/

#include <stdio.h>

/*****************************************************************
//  
//  Function name: user_interface
//
//  DESCRIPTION:   Prompts user for a number. Will continue to ask unless given a positive integer. Prompts  user to input an integer if a different data type is entered. Prompts user to input a positive int if a negative int is given.
//
//  Parameters:    None
//
//  Return values: num : success
*****************************************************************/

int user_interface()
{
    int num, numRead;
    printf("*** Will print all numbers from 0 to number entered and odd or even ***\n");
    printf("Enter maximum number to show:\n");
    printf(">");
    do
    {
        numRead = scanf("%d", &num);
        while (numRead != 1)
        {
            printf("ERROR. Enter an integer: ");
            scanf("%*[^\n]");
            numRead = scanf("%d", &num);
        }
        if (num <= 0)
        {
            printf("ERROR. Enter a positive integer: ");
        }
    }
    while (num <= 0);
    return num;
}

/*****************************************************************
//
//  Function name: is_even
//
//  DESCRIPTION:   Takes in one int parameter. Returns 0 if the int is even, else returns 1. 
//
//  Parameters:    value (int) : an integer value
//
//  Return values: 0 : even
//                 1 : odd
*****************************************************************/

int is_even(int value)
{
    int result = 1;
    if (value % 2)
    {
        result = 0;
    }
    return result;
}

/*****************************************************************
// 
//  Function name: print_table
//
//  DESCRIPTION:   Will print a correctly formatted list of integers starting from 0 and ending at the value the user inputted. Each of these values will also contain if its even or odd.
//
//  Parameters:    value (int) : an integer value
//
//  Return values: void
*****************************************************************/

void print_table(int value)
{
    int counter, temp, i, j;
    printf("  Number  Even or Odd?\n");
    for (i = 0; i <= value; i++)
    {
        counter = 0;
        temp = i;
        while (temp != 0)
        {
            temp = temp / 10;
            counter++;
        }
        if (counter == 0)
        {
            counter = 1;
        }
        for (j = 0; j <= 7-counter; j++)
        {
            printf(" ");
        }
        printf("%d", i);

        if (is_even(i))
        {
            printf("  Even\n");
        }
        else
        {
            printf("   Odd\n");
        }
    }
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Will properly call the other functions to output the desired result.
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
*****************************************************************/

int main(int argc, char* argv[])
{
    print_table(user_interface());
    return 0;
}
