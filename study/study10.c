#include <stdio.h>

int main() 
{
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int sum=0,i;
    for (i=0;i<10;i++)
    {
        sum += num[i];
    }
    printf("%d\n",sum);
    return 0;
}
