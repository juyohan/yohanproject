#include <stdio.h>
#include <stdlib.h>

int main(){
    char name[10];
    char kor[10],eng[10],math[10];
    int total;
    double avg;

    while(1){
        int i = 0;
    printf("이름을 적어주세요. : ");
    scanf("%s",name);
    printf("국어,영어,수학 점수를 각각 적으세요. : ");
    scanf("%s %s %s",kor,eng,math);
    total = atoi(kor) + atoi(eng) + atoi(math);
    avg = total / 3;

    printf("%s님의 합과 평균\n합 : %d\n평균 : %.2lf\n",name,total,avg);
    i++;
    if (i==3)
    break;
    }
    return 0;
}