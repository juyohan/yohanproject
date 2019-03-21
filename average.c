#include <stdio.h>

double add(double *kor, double *eng, double *math){
    return (*kor+*eng+*math);
}
double mean(double sum){
    return sum/3;
}

int main()
{
    double kor,eng,math;
    double sum,avg;

    for (int i = 1; i <4 ; i++){
    printf("국어,영어,수학 점수를 각각 적으세요. : ");
    scanf("%lf%lf%lf",&kor,&eng,&math);
    sum = add(&kor,&eng,&math);
    avg = mean(sum);
    printf("합 : %.2lf\t 평균 : %.2lf\n",sum,avg);
    }
    return 0;
}


