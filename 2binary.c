#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int story[32];
    int num;

    printf("2진법으로 바꾸실 숫자를 적으시오. : ");
    scanf("%d",&num);

    int position = 0;

    if (num >= 0){

    while (1){
        story[position] = num % 2; // 2로 나눈 몫 값을 저장함
        num = num / 2; // 2로 나눈 나머지 값을 저장함
        
        position++;

        if (num==0) // num의 값이 0이 되면 멈춤
        break;
    }
      for (int i = position-1 ; i >= 0 ; i--) // 배열의 역순으로 출력
    {
        printf("%d", story[i]);
        if (i % 4 == 0 ) // 4개씩 나눔
        printf("  ");
    }
    }

else if (num < 0){

    num = -num; // 음수를 양수로 변환

    while (1){
        story[position] = num % 2; // 2로 나눈 몫 값을 저장함
        num = num / 2; // 2로 나눈 나머지 값을 저장함
        
        position++;

        if (num==0) // num의 값이 0이 되면 멈춤
        break;
    }
    printf("1의 보수 : ");
    for (int i = position-1 ; i >= 0 ; i--) // 배열의 역순으로 출력
    {
        story[i] = !story[i]; // 1의 보수로 바꿔줌
        printf("%d",story[i]); 
    if (i % 4 == 0 ) // 4개씩 나눔
        printf("  ");
    }

    printf("\n");

    for (int i = 0 ; i <=position-1 ; i++){
        if (story[i] == 0){
            story[i] = story[i] + 1; // 끝자리가 0이면 1을 더해줌 (2의 보수)
            break;   // 1을 더하면 for문 밖으로 나감
        }
        else if(story[i] == 1){ // 끝자리가 1이면 0으로 바꿔줌
            story[i] = 0;
        }
     }
     printf("2의 보수 : ");
     for (int i = position-1 ; i >=0 ; i--){
    printf("%d",story[i]); 
    if (i % 4 == 0 ) // 4개씩 나눔
        printf("  ");
     }
}
    printf("\n");
}

