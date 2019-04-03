#include <stdio.h>

// 구조체를 이용해 이름,학번,학과출력

// struct Introduction {
//     char name[10], major[15];
//     int num;
// } i;

// int main(){
//     struct Introduction i;

//     printf("이름을 입력해주세요. : ");
//     scanf("%s",i.name);
//     printf("학과를 적어주세요. : ");
//     scanf("%s",i.major);
//     printf("학번을 적어주세요. : ");
//     scanf("%d",&i.num);

//     printf("이름 : %s\n학과 : %s\n학번 : %d\n",i.name,i.major,i.num);

//     return 0;
// }

// 배열 초기화를 사용해 출력

struct name_1{
    char name[10];
    char major[10];
    char num[10];
} n1;

int main(){
    struct n1;

    printf("이름, 학번, 학과를 입력해주세요. : ");
    scanf("%s %s %s",n1.name,n1.major,n1.num);

    printf("이름 : %s\n학번 : %s\n학과 : %s",n1.name,n1.num,n1.major);

    return 0;
}