#include <stdio.h>

int main()
{
    int num;
    int a;
    scanf("%d",&num);
    
    a = num / 10;

    switch (a){
    case 9 :
        printf("A학점\n");
        break;
    case 8 :
        printf("B학점\n");
        break;
    case 7 :
        printf("C학점\n");
        break;
    case 6 :
        printf("D학점\n");
        break;
    default :
        printf("F학점\n ");
        break;
}
        return 0;
}
