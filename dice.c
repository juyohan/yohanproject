#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    static int num1,num2,num3,num4,num5,num6; // 증감하는 값들을 계속 유지시키기                                               위해 정적변수를 사용함.
    int num,random;

    srand(time(NULL)); // 난수 설정

    printf("주사위를 몇번 돌리시겠습니까? : ");
    scanf("%d",&num);

    for (int i = 0; i < num; i++){

    random = (rand() % 6) + 1; // 1~6까지의 난수만 나오게 설정함

    printf("%d ",random);

    if (random == 1)
    num1++;
    else if (random == 2)
    num2++;
    else if (random == 3)
    num3++;
    else if (random == 4)
    num4++;
    else if (random == 5)
    num5++;
    else if (random == 6)
    num6++;
    }
printf("\n=========================결과 값==========================\n");
printf("숫자 1이 나온 횟수 : %2d\n숫자 2가 나온 횟수 : %2d\n숫자 3이 나온 횟수 : %2d",num1,num2,num3);
printf("\n숫자 4가 나온 횟수 : %2d\n숫자 5가 나온 횟수 : %2d\n숫자 6이 나온 횟수 : %2d",num4,num5,num6);

return 0;
}