#include <stdio.h>

double meter(double Mile);
double mile(double Meter);

double meter(double Mile){
    return Mile*1609.344;
}
double mile(double Meter){
    return Meter*0.000621;
}

int main(){
    double Mile,Meter;
    int num;

    while(1){

        printf("마일 -> 미터면 1번, 미터 -> 마일면 2번을 눌러주세요. : ");
        scanf("%d",&num);

        if (num == 1){
        printf("마일를 입력해주세요. : ");
        scanf("%lf",&Mile);
        printf("마일 -> 미터로 변환합니다.\n");
        printf("미터 : %.2lf℉입니다.",meter(Mile));
        break;
    }
    else if (num == 2){
        printf("미터를 입력해주세요. : ");
        scanf("%lf",&Meter);
        printf("미터 -> 마일로 변환합니다.\n");
        printf("마일 : %.2lf℃입니다.",mile(Meter));
        break;
    }
    else if (num != 1 && num != 2){
        printf("숫자를 잘못입력하셨습니다.\n다시 돌아갑니다.\n");
    }
    }
return 0;
}