#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "getch.h"
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#define NAME_len 10
#define MAJOR_len 10
#define ID_len 30
#define PASSWORD_len 30

int display_menu(void);
int membership_store(void);
int membership_open(void);
int login(void);

#pragma pack (push, 1)
typedef struct information {
    char name[NAME_len];
    int birth;
    char major[MAJOR_len];
    char id[ID_len];
    char password[PASSWORD_len];
} temp_infor;
#pragma pack(pop)

int display_menu(void){
    int menu_num = 0;

    while(1){
    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\t\t   1. 로그인\t\t2. 사용방법");
    printf("\n\n\t\t   3. 회원가입\t\t4. 나가기");
    printf("\n\n\t\t     어디로 가시겠습니까? : ");
    scanf("%d",&menu_num);

    if (menu_num<1 || menu_num>4){
        continue;
    }
    else {
        return menu_num;
    } 
    }
    return 0;
}

int login(void){
    temp_infor t1;

    char id1[30],password1[30];
    int b = 0;

    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\n\t\t\t 아이디  :  ");
    scanf("%s",id1);
    // fopen()
    for (int i = 0 ; i <=strlen(id1); i++){
        if (strcmp(t1.id,id1) == 0 ){
            printf("없는 id입니다.");
            login();
        }
    }
    printf("\n\n\t\t\t비밀번호 :  \n");
    scanf("%s",password1);

    return 0;
}

int membership_store(void){
    temp_infor t1;

    char newname[30];
    memset(&t1, 0, sizeof(t1));

    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\t\t\t  이름  : ");
    scanf("%s",t1.name,newname);   
    printf("\n\t\t\t생년월일 : ");
    scanf("%d",&t1.birth);
    printf("\n\t\t\t 아이디  : ");
    scanf("%s",t1.id);
    printf("\n\t\t\t비밀번호 : ");
    scanf("%s",t1.password);
    printf("\n\t\t\t  학번  : ");
    scanf("%s",t1.major);

    FILE *fp = fopen("membership.bin","wb");

    fwrite(&t1,sizeof(t1),1,fp);

    fclose(fp);

    char oldname[] = "membership.bin";

    // rename(oldname,newname);

    return 0;
}

int membership_open(void){

}

int main(){
        int menu = display_menu();

        if (menu == 1){
            login();
        }
        else if (menu == 2){
            printf("니ㅏ니ㅓㄴ라");
        }
        else if (menu == 3) {
            membership_stpre();
        }
        else if (menu==4){
            exit(1);
        }

return 0;
}