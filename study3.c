#include <stdio.h>

int add(int *n,int *m)
{
    return (*n+*m);
}
int minus(int *n,int *m)
{
    return(*n-*m);
}
double div(int *n,int *m)
{
    return(*n/ *m);
}
int mul(int *n,int *m)
{
    return(*n* *m);
}

int main()
{
    int sum1,sum2,sum4;
    int m,n;
    double sum3;
    printf("두 정수를 입력해주세요. :");
    scanf("%d %d",&n,&m);
    sum1 = add(&n,&m);
    sum2 = minus(&n,&m);
    sum3 = div(&n,&m);
    sum4 = mul(&n,&m);
    printf("두 수의 합 : %d \t 두 수의 뺄셈 : %d\n",sum1,sum2);
    printf("두 수의 나눗셈 : %.2lf \t 두 수의 곱셈 : %d\n",sum3,sum4);
    return 0;
}



