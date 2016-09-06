#include <stdio.h>

int main()
{
    int i;
    int sum=0;
    for (i=1;i<101;i++)
    {
        sum = sum + i;
       }
    printf("1부터 100까지의 합 : %d\n",sum);
    return 0;
}
