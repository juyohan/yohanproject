#include <stdio.h>
#define pi 3.14

double area(double r);
double circum(double r);

int main()
{
    double s,l,k;
    int r;
    printf("반지름을 입력하세요.: ");
    scanf("%d",&r);
    s = area(r);
    l = circum(r);
    k = round(r);
    printf("원의 부피 : %lf \n 원의 넓이 : %lf \n /n 원의 둘레 : %f/n",l,s,k);
    return 0;
}

double area(double r)
{
    return (4*pi*r*r);
}

double circum(double r)
{
    return (4*pi*r*r*r/3);
}

double round(double r)
{
    return (2*pi*r);
}
