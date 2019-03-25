#include <stdio.h>

double compound(int a,int b,double c);
double increase(double m,int b);

int main(){
    int money,year;
    double rate;

    printf("1. 원금을 입력해주세요. : ");
    scanf("%d",&money);
    printf("2. 년수를 입력해주세요. : ");
    scanf("%d",&year);
    printf("3. 이율을 입력해주세요. : ");
    scanf("%lf",&rate);

    printf("총 값은 : %lf",compound(money,year,rate));
}

double compound(int a,int b,double c){
    return a*increase(1+(0.01*c),b);
}

double increase(double m, int b){
    int i;
    double total = 1;

    for (i = 0; i < b;i++){
        total *= m;
    }
    return total;
}