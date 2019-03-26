#include <stdio.h>
#include <string.h>

int main() {
    char name[30];
    int n;

    printf("영어 이름을 적어주세요. : ");
    fgets(name, sizeof(name),stdin);

    printf("소대문자를 서로 변환시킵니다. \n");

    for (int i = 0; i <=30; i++){
        if (name[i] >= 'A' && name[i] <= 'Z') // 대문자 아스키코드의 값에 32를 더해줌
        name[i] += 32;
        else if(name[i] >= 'a' && name[i] <='z') // 소문자 아스키코드의 값에 32를 빼줌
        name[i] -= 32;
        printf("%c",name[i]);
    }

    return 0;
}