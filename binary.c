#include <stdio.h>
#include <stdlib.h>

int main(){
    int story[20] = {0,};
    int num;

    printf("2진법으로 바꾸실 숫자를 적으시오. : ");
    scanf("%d",&num);

    int position = 0;
    while (1){
        story[position] = num % 2; // 2로 나눈 몫 값을 저장함
        num = num / 2; // 2로 나눈 나머지 값을 저장함
        
        position++;

        if (num==0) // 2로 나누고 값이 0이 되었을 때 멈춤
        break;
    }
    for (int i = position-1 ; i >= 0 ; i--) // 배열의 역순으로 출력
    {
        printf("%d",story[i]); 
    }
    printf("\n");
}
