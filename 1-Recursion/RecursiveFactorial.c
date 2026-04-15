#include <stdio.h>

int Factorial(int num)
{
    if(num==1)
        return 1;
    else
        return num * Factorial(num -1);
}

int main(void)
{
    printf("1! = %d\n", Factorial(1));
    printf("3! = %d\n", Factorial(3));
    printf("5! = %d\n", Factorial(5));
    printf("7! = %d\n", Factorial(7));

    return 0;
}