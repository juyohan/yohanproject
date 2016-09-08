#include <stdio.h>

int main()
{
    double kor,eng,math;
    double sum,avg;
    printf("국어,영어,수학 점수를 각각 적으세요. : ");
    scanf("%lf%lf%lf",&kor,&eng,&math);
    sum = kor + eng + math;
    avg = sum / 3;
    printf("합 : %lf\t 평균 : %.2lf\n",sum,avg);
    return 0;
}


