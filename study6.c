#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    int len,i;
    printf("이름을 영어로 입력하세요. :");
    scanf("%s",name);

    len = strlen(name);
    for (i=len-1;i>=0;i--)
        printf("%c",name[i]);
    printf("\n");
    return 0;
}
