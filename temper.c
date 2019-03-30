#include <stdio.h>

double centi(double Fahren);
double fahren(double Centi);

double fahren(double Centi){
    return (Centi*1.8)+32;
}

double centi(double Fahren){
    return (Fahren-32)/1.8;
}

int main(){
    double Fahren,Centi;
    int num;

    while(1){

        printf("섭씨 -> 화씨면 1번, 화씨 -> 섭씨면 2번을 눌러주세요. : ");
        scanf("%d",&num);

        if (num == 1){
        printf("섭씨를 입력해주세요. : ");
        scanf("%lf",&Centi);
        printf("섭씨 -> 화씨로 변환합니다.\n");
        printf("화씨 : %.2lf℉입니다.",fahren(Centi));
        break;
    }
    else if (num == 2){
        printf("화씨를 입력해주세요. : ");
        scanf("%lf",&Fahren);
        printf("화씨 -> 섭씨로 변환합니다.\n");
        printf("섭씨 : %.2lf℃입니다.",centi(Fahren));
        break;
    }
    else if (num != 1 && num != 2){
        printf("숫자를 잘못입력하셨습니다.\n다시 돌아갑니다.\n");
    }
    }
return 0;
}