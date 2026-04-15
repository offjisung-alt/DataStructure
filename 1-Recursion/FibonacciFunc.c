#include <stdio.h>

int Fibo(int num)
{
    if(num==1 || num == 2)
        return 1;
    else
        return Fibo(num-1) + Fibo(num-2);
}

int main(void)
{
    printf("첫 번째 = %d\n", Fibo(1));
    printf("세 번째 = %d\n", Fibo(3));
    printf("다섯 번째 = %d\n", Fibo(5));
    printf("일곱 번째 = %d\n", Fibo(7));

    return 0;
}