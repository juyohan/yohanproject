#include <stdio.h>

int remain(int num){
    return num/2;
}

void quo(int story[],int num){
    int position=0;

    story[position] = num % 2;
    
}
int main(){
    int num;
    int story[] = {0,};

    printf("숫자를 입력해주세요 : ");
    scanf("%d",&num);

    quo(story,num);
    remain(num);
}