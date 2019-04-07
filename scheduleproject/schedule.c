#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include "getch.h"
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#define NAME_len 20
#define MAJOR_len 20
#define ID_len 30
#define PASSWORD_len 30
#define BIRTH_len 20

int display_menu(void); // 메인메뉴를 보여줌
int membership_store(void); // 회원가입
int login(void);
int main_menu(void);
int main_1(void);
int schedule_watch(void);
int schedule_search(void);
int schedule_add(void);
int schedule_delete(void);
int schedule_change(void);
int schedule_import(void);

#pragma pack (push, 1)
typedef struct information {
    char name[NAME_len];
    char birth[BIRTH_len];
    char id[ID_len];
    char password[PASSWORD_len];
    char major[MAJOR_len];
} temp_infor;
#pragma pack(pop)

int main_1(void){
    while(1){
        
        int menu_1 = main_menu();

        if (menu_1 == 1)
        schedule_watch();
        else if (menu_1 == 2)
        schedule_import();
        else if (menu_1 == 3)
        schedule_add();
        else if (menu_1 == 4)
        schedule_change();
        else if (menu_1 == 5)
        schedule_search();
        else if (menu_1 == 6)
        schedule_delete();
        else if (menu_1 == 7)
        exit(1);
    }
    return 0;
}

int main_menu(void){
    temp_infor t1;

    int menu2_num = 0;

    while(1){
    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\t\t  1. 시간표 보기   2. 시간표 입력");
    printf("\n\n\t\t  3. 시간표 추가   4. 시간표 수정");
    printf("\n\n\t\t  5. 시간표 검색   6. 시간표 삭제");
    printf("\n\n\t\t  7. 종료");
    printf("\n\n\t\t     어디로 가시겠습니까? : ");
    scanf("%d",&menu2_num);

    if (menu2_num<1||menu2_num>7){
    printf("\n\n\t\t\t잘못입력하셨습니다. \n");
    continue;
    }
    else {
    return menu2_num;
}
    }
    return 0;
}

int schedule_watch(void){
    return 0;
}

int schedule_add(void){
    temp_infor t1;

    return 0;
}

int schedule_delete(void){
    return 0;
}

int schedule_import(void){
    return 0;
}

int schedule_search(void){
    temp_infor t1;

    char mem_id[10];

    while(1){
    printf("%s%s%s%s%s",t1.name,t1.birth,t1.id,t1.password,t1.major);
    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\t    시간표를 볼 회원님의 아이디를 적어주세요. : ");
    scanf("%s",mem_id);

    FILE *fp_1 = fopen(mem_id,"r");
    if (fp_1==NULL){
        printf("\t\t\t  없는 회원님입니다.\n\n\t\t   다른 회원님의 아이디를 적어주세요.");
        continue;
    }
    else if (fp_1 !=NULL){
        return 0;
    }

    fclose(fp_1);
    }
    return 0;
}

int schedule_change(void){
    return 0;
}

int main(){
    while(1){
    int menu = display_menu();

        if (menu == 1){
            login();
            main_1();
        }
        else if (menu == 2){
            printf("니ㅏ니ㅓㄴ라");
        }
        else if (menu == 3) {
            membership_store();
        }
        else if (menu==4){
           break;
        }
    }
return 0;
}

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
        printf("\n\t\t\t잘못입력하셨습니다. \n");
        continue;
    }
    else {
        return menu_num;
    } 
    }
    return 0;
}

int membership_store(void){
    temp_infor t1;

    memset(&t1, 0, sizeof(t1));

    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\t\t\t  이름  : ");
    scanf("%s",t1.name);   
    printf("\n\t\t\t생년월일 : ");
    scanf("%s",t1.birth);
    printf("\n\t\t\t 아이디  : ");
    scanf("%s",t1.id);
    printf("\n\t\t\t비밀번호 : ");
    scanf("%s",t1.password);
    printf("\n\t\t\t  학번  : ");
    scanf("%s",t1.major);

    FILE *fp = fopen(t1.id,"w");

    fwrite(t1.name,strlen(t1.name),1,fp);
    fprintf(fp,"\n");
    fwrite(t1.birth,strlen(t1.birth),1,fp);
    fprintf(fp,"\n");
    fwrite(t1.id,strlen(t1.id),1,fp);
    fprintf(fp,"\n");
    fwrite(t1.password,strlen(t1.password),1,fp);
    fprintf(fp,"\n");
    fwrite(t1.major,strlen(t1.major),1,fp);
    fprintf(fp,"\n");

    fclose(fp);

    printf("\n\t\t\t회원가입을 축하합니다.\n");

    return 0;
}

int login(void){
    temp_infor t1;

    char id1[20]={0,};
    char password1[30]={0,};

    while(1){
    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\n\t\t\t 아이디  :  ");
    scanf("%s",id1);
    printf("\n\t\t\t비밀번호 :  ");
    scanf("%s",password1);
    printf("%s",t1.password);

     FILE *fp = fopen(id1,"rb");

     fgets(t1.name,sizeof(t1.name),fp);
     fgets(t1.birth,sizeof(t1.birth),fp);
     fgets(t1.id,sizeof(t1.id),fp);
     fgets(t1.password,sizeof(t1.password),fp);
     fgets(t1.major,sizeof(t1.major),fp);
     t1.password[strlen(t1.password)-1] = '\0'; 

     if (fp==NULL){
        printf("\n\t\t\t없는 아이디입니다.\n\t\t\t메인메뉴로 넘어갑니다.\n");
        break;
    }
    else if(fp!=NULL){
    if (strcmp(password1,t1.password) == 0){
         printf("\n\t\t\t     환영합니다.\n");
         break;
    }  

    else if (strcmp(password1,t1.password) != 0) {
         printf("\n\t\t\t비밀번호가 틀렸습니다. \n");
        continue;
     }
    }
    fclose(fp);
    }
    return 0;
}
