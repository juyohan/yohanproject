#include <stdio.h>

int add(int num, int num1){
    return (num+num1);
}

int minus(int num, int num1){
    return (num-num1);
}

double avg(int num, int num1){
    return ((double)num/ num1);
}

int multi(int num, int num1){
    return (num*num1);
}

int main(){
    int num,num1;
    int sim;

    printf("사칙연산 할 두 수를 적으세요. : ");
    scanf("%d %d",&num,&num1);
    printf("1.덧셈\t2.뺄셈\t3.나눗셈  4.곱셈\n");
    printf("위 4개중 하나를 선택하세요. : ");
    scanf("%d",&sim);
    int (*add_)(int,int);
    int (*minus_)(int,int);
    int (*multi_)(int,int);
    double (*avg_)(int,int);
    add_ = add;
    minus_ = minus;
    multi_ = multi;
    avg_ = avg;

    switch(sim){
        case 1 : printf("두 수의 덧셈의 값 : %d\n",add_(num,num1)); break;
        case 2 : printf("두 수의 뺄셈의 값 : %d\n",minus_(num,num1)); break;
        case 3 : printf("두 수의 나눗셈의 값 : %.2lf",avg_(num,num1)); break;
        case 4 : printf("두 수의 곱셈의 값 : %d\n",multi_(num,num1)); break;
        
        default : printf("숫자를 잘 못 입력하셨습니다.\n종료합니다.\n");
    }
    return 0;
}