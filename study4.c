#include <stdio.h>

int main()
{
    int a,b,i;
    printf("몇 단을 출력하시겠습니까? ");
    scanf("%d",&a);
    for (i=1;i<10;i++)
    {
        b = a * i;
        printf("%d x %d = %d\n",a,i,b);
    }
    for (int j = 10; j > 0 ; j--){
        b = a * j;
        printf("%d x %d = %d\n",a,i,b);
    }
    return 0;
}

