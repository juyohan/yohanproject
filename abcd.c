#include <stdio.h>

int position = 0;

int two(int num){
    int story[20] = {0,};
     while (1){
        story[position] = num % 2; // 2로 나눈 몫 값을 저장함
        num = num / 2; // 2로 나눈 나머지 값을 저장함
        
        position++;

        if (num==0) // 2로 나누고 값이 0이 되었을 때 멈춤
        break;
    }

    return story[20];

}

int main(){
    int num, give;

    printf("숫자를 적어주세요. : ");
    scanf("%d",&num);

    give = two(num);
    
    for (int i = position-1 ; i >= 0 ; i--) // 배열의 역순으로 출력
    {
        printf("%d",story[i]); 
    }
}