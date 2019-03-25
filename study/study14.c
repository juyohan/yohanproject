#include <stdio.h>
#include <math.h>

int main()
{
    int a=0;
    int b=0;
    double c= 0;

    printf("밑변 a와 높이 b를 입력: ");
    scanf("%d%d",&a,&b);
    c= (a*a)+(b*b);
    printf("a*a+b*b=c*c\n");
    printf("%d+%d=%.2lf\n",a*a,b*b,c);
    c = sqrt(c);
    printf("빗면의 길이:%.2lf\n",c);
    return 0;
}
        
