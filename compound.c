#include <stdio.h>
#include <math.h>

// double compound(int a,int b,double c);
// double increase(double m,int b);

int main(){
    int money,total;
    double rate;
    int year=1;

    printf("1. 원금을 입력해주세요. : ");
    scanf("%d",&money);
    printf("2. 이율을 입력해주세요. : ");
    scanf("%lf",&rate);

while (1) {
    total = money * pow(1+(0.01*rate),year); // 이율의 제곱승을 해줌
    year++; //년도의 값을 증가시킴
    if (total >= 2*money){ // 총 금액이 원금의 2배보다 높거나 같으면 멈춤
       break;
    }
}

    printf("%d년 후 원금의 2배가 됩니다. \n",year);

    return 0;
}

// double compound(int a,int b,double c){ 
//     return a*increase(1+(0.01*c),b); // 총 금액의 값
// }

// double increase(double m, int b){
//     int i;
//     double total = 1;

//     for (i = 0; i < b;i++){
//         total *= m;
//     }
//     return total;
// }