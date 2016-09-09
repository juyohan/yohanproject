#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5 

int main(void)
{
    int index = 0;

    srand(time(NULL));
    printf("이 예제는 rand()함수를 이용하여 5개의 난수를 생성하는 예제입니다.\n");

    for (index=0;index<MAX;index++)
    printf("%4d",rand());
    printf("\n");

    return 0;
}
