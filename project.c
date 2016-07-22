#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int add(int n[]);

int main(void)
{
    int i =0,a;
    int sum,g[MAX];

    srand(time(NULL));
    printf("1부터 10사이의 양수 하나를 고르시오. : ");
    scanf("%d",&a);

    for (i=1; i<a+1; i++)
        g[i]=rand()%10;

    sum=add(g);

    for (i=1; i<a+1; i++)
        printf("%d\n",g[i]);

    printf("전체 합은 %d 입니다.\n",sum);

    return 0;
}

int add(int n[])
{
    int i,result=0;
    
    for (i=1; i<MAX; i++)
        result += n[i];

    return result;
}

