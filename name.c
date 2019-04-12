#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체를 이용해 이름,학번,학과출력

struct Introduction {
    char name[10][50];
    char address[10][50];
    char phone[10][50];
    char age[10][50];
} i;

int main(){
    struct Introduction i;

    int num,a,num_;

    printf("몇 명의 정보를 입력하시겠습니까?(최대 10명) : ");
    scanf("%d",&num);

    for (int j = 0 ; j<num; j++){
        printf("%d번째 사람의 정보를 입력합니다.\n",j+1);
    
    printf("이름을 입력해주세요. : ");
    scanf("%s",i.name[j]);
    printf("주소를 적어주세요. : ");
    scanf("%s",i.address[j]);
    printf("나이을 적어주세요. : ");
    scanf("%s",i.age[j]);
    printf("핸드폰 번호를 적어주세요.(-포함) : ");
    scanf("%s",i.phone[j]);

    }
    
    while(1){
    printf("정보를 확인하겠습니까?\n1.예 2.아니요 : ");
    scanf("%d",&a);

    if (a==1){
        printf("몇 번째의 정보를 확인하겠습니까? : ");
        scanf("%d",&num_);
        printf("이름 : %s\n주소 : %s\n나이 : %s\n핸드폰 번호 : %s\n",i.name[num_-1],i.address[num_-1],i.age[num_-1],i.phone[num_-1]);
    }
        else if (a==2){
            printf("입력하신 정보를 삭제하고 종료합니다.\n");
            exit(1);
        }
        else {
        printf("숫자를 잘못입력하셨습니다.\n이전으로 돌아갑니다.\n");
        return 0;
        }
    }
    return 0;
}

// 배열 초기화를 사용해 출력

// struct name_1{
//     char name[10];
//     char major[10];
//     char num[10];
// } n1;

// int main(){
//     struct n1;

//     printf("이름, 학번, 학과를 입력해주세요. : ");
//     scanf("%s %s %s",n1.name,n1.major,n1.num);

//     printf("이름 : %s\n학번 : %s\n학과 : %s",n1.name,n1.num,n1.major);

//     return 0;
// }

// 포인터 배열을 사용해 출력 

// int main(){
//     char *name = "주요한";
//     char *address = "경기도 화성시 동탄순환대로 21길 15, 1342동 2502호";
//     char *major = "IT학부";

//     printf("이름 : %s\n주소 : %s\n학과 : %s\n",name,address,major);

//     return 0;
// }

