/*************************************************************
//
//  NAME:        ***Justin Smith***
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        August 28, 2023
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//  This code first defines two variables called num and i. This is called variable definition. It then creates a for loop that will loop the following code five times. There are three statements inside the for loop checking for which number the current iteration is on. Depending on the current iteration, the output will be different. After this for loop, it assigns the value of 0 to num, this is called an assignment statement. After this, there is a while loop that will loop through the following part four times since num will increase by one every iteration. Once the while loop finishes, num is assigned the value 0 again and a do-while loop begins that will also loop four times.
//
//
*************************************************************/

#include <stdio.h>

/*************************************************************
// 
//  Function name: main
//
//  DESCRIPTION:   Basic function for testing different loops in C
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
*************************************************************/

int main(int argc, char* argv[])
{
    int num;
    int i;
    
    for (i = 0; i < 5; i = i + 1)
    {
        if (i < 2)
        {
            printf("Hello\n");
        }
        else if (i < 4)
        {
            printf("World\n");
        }
        else
        {
            printf("!!!\n");
        }
    }
    
    num = 0;
    while (num < 4)
    {
        printf("While loop!\n");
        num++;
    }

    num = 0;
    do
    {
        printf("Do-while loop!\n");
        num++;
    }
    while (num < 4);
    return 0;
}

