#include <stdio.h>

int main(){
    int a,i=1;
    char name[10];

    printf("당신의 이름은 무엇입니까? : ");
    scanf("%s",name);

    printf("이름을 몇 번 출력하시겠습니까? : ");
    scanf("%d",&a);

    for (i=1;i<=a;i++){
        printf("%s\n",name);
    }
    return 0;
}