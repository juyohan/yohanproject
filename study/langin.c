#include <stdio.h>
#include <string.h>

int main(){
    char lang[20];

    printf("역순으로 출력하고 싶은 문자를 입력하세요. : ");
    scanf("%[^\n]s",lang);

    int position = strlen(lang);

    for (int i = position -1; i >=0; i--){
        printf("%c",lang[i]);
    }
    return 0;

}