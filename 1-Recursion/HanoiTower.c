#include <stdio.h>
/*
하노이탑

상황: FROM / BY / TO
세가지 공간이 있고 FROM에 n개의 원반이 있으며 TO로 이동시키는 것이 목적

재귀의 원칙:
FROM에 있는 원반 중 위에서부터 n-1개의 원반을 BY로 이동시킨다.
FROM에 있는 가장 큰 원반을 TO로 이동시킨다.
BY에 있는 원반들을 TO로 이동시킨다.

구현중 한 실수:
if~else 구문으로 작성하지 않고
if만 작성함 -> 이 경우 if 밑 문장까지 계속 실행되어 무한루프에 빠진다.


*/


void HT(int n, char from, char by, char to)
{
    if(n==1)
        printf("원반1을 %c에서 %c로 이동시킨다\n", from, to);
    else
    {    
    HT(n-1, from, to, by);
    printf("원반%d를 %c에서 %c로 이동시킨다\n", n, from, to);
    HT(n-1, by, from, to);
    }
}


int main(void)
{
    HT(3, 'A', 'B','C');
    return 0;
}