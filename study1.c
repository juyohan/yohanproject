#include <stdio.h>
#define pi 3.14

double area(double r);
double circum(double r);

int main()
{
    double s,l;
    int r;
    printf("반지름을 입력하세요.: ");
    scanf("%d",&r);
    s = area(r);
    l = circum(r);
    printf("원의 둘레 : %lf \t 원의 넓이 : %lf \n",l,s);
    return 0;
}

double area(double r)
{
    return (pi*r*r);
}

double circum(double r)
{
    return (pi*2*r);
}
