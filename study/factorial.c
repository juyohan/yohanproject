#include <stdio.h>

int factorial(num){
    if (num ==1)
    return 1;
    return num * factorial(num -1);
}

int main(){
    int num;

    printf("몇 팩토리얼을 구하시겠습니까? : ");
    scanf("%d",&num);

    printf("%d! = %d\n",num,factorial(num));
}