#include <stdio.h>

int main()
{
    int won,i;
    printf("환원 하고 싶은 금액을 입력하시오.: ");
    scanf("%d",&won);
    i = won / 1150;
    printf("%d달러\n",i);
    return 0;
}

