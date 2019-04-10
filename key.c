#include <stdio.h>

int main(){
    int num;
    int total = 0;
    while(1){
    printf("더할 숫자들을 입력해주세요.(0을 누르면 멈춥니다.) : ");
    scanf("%d",&num);

    total = total + num;

    if (num == 0)
    {
        printf("지금까지 누르신 합 : %d\n",total);
        break;
    }
    }
}