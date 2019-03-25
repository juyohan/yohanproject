#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    
    printf("자신의 영어 이름을 입력해주세요 : ");
    fgets(name,sizeof(name),stdin); // fgets로 입력받음
    // name[strlen(name)-1] = 0;

    for (int i = 0; i<50; i++){
    if (name[i]>='A' && name[i]<='Z')
        name[i] += 32; // 대문자 아스키코드 값에 32를 더해 소문자로 바꿔줌
        else if (name[i]>='a' && name[i]<='z')
        name[i] -= 32; // 소문자 아스키코드 값에 32를 빼서 대문자로 바궈줌
    }
    printf("대소문자를 변환합니다. : %s",name);
    return 0;
}