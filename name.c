#include <stdio.h>

struct Introduction {
    char name[10], major[15];
    int num;
} i;

int main(){
    struct Introduction i;

    printf("이름을 입력해주세요. : ");
    scanf("%s",i.name);
    printf("학과를 적어주세요. : ");
    scanf("%s",i.major);
    printf("학번을 적어주세요. : ");
    scanf("%d",&i.num);

    printf("이름 : %s\n학과 : %s\n학번 : %d\n",i.name,i.major,i.num);

    return 0;
}