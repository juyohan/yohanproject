#include <stdio.h>
#include <string.h>


int lang(void);

int lang(void) {
    char id1[30],password1[30];

    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\n\t\t\t아이디   : ");
    fgets(id1,sizeof(id1),stdin);
    id1[strlen(id1)-1] = '\0';
    // for (int i = 0 ; i <=strlen(id1); i++){
    //     if (strcmp(t1.id,id1) == 0 ){
    //         printf("없는 id입니다.");
    //         login();
    //     }
    // }
      printf("\n\t\t\t비밀번호 : \n");
       fgets(password1,sizeof(password1),stdin);
    password1[strlen(password1)-1] = '\0';

    return 0;
}
int main() {
   
    lang();
    return 0;
}