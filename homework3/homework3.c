#include  <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 12;
    char c1 = 'C';
    char c2 = 'D';
    float score1 = 10.5;
    char ca[3] = "Hi";
    printf("Address of argc %p\n", &argc);
    printf("Address of argv %p\n", &argv);
    printf("Address of c1 %p\n", &c1);
    printf("Address of c2 %p\n", &c2);
    printf("Address of score1 %p\n", &score1);
    printf("Address of ca[0] %p\n", &ca[0]);
    printf("Address of ca[1] %p\n", &ca[1]);
    printf("Address of ca[2] %p\n", &ca[2]); 
    printf("Address of num1 %p\n", &num1);
    printf("Address of num2 %p\n", &num2);

    printf("Value of argv %d\n", argc);
    printf("Value of argv %s\n", argv[1]);
    printf("Value of c1 %c\n", c1);
    printf("Value of c2 %c\n", c2);
    printf("Value of score1 %f\n", score1);
    printf("Value of ca[0] %c\n", ca[0]);
    printf("Value of ca[1] %c\n", ca[1]);
    printf("Value of ca[2] %c\n", ca[2]);
    printf("Value of num1 %d\n", num1);
    printf("Value of num2 %d\n", num2);
   



    dummy(num2, c1, ca, score1);


    return 0;
}


void dummy(int x, char y, char* z, float w)
{
    printf("Value of x %d\n", x);
    printf("Value of y %c\n", y);
    printf("Value of z %c\n", z);
    printf("Value of w %f\n", w);

    x++;
    y++;
    w = w + 2.1;
    printf("2 Value of x %d\n", x);
    printf("2 Value of y %c\n", y);
    printf("2 Value of z %d\n", &z);
    printf("2 Value of w %f\n", w);

    printf("Address of x %p\n", &x);
    printf("Address of y %p\n", &y);
    printf("Address of z %p\n", &z);
    printf("Address of w %p\n", &w);


    /* pause here */
}

