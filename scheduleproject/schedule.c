#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

#define NAME_len 20
#define MAJOR_len 20
#define ID_len 30
#define PASSWORD_len 30
#define BIRTH_len 20
#define schedule_time 10
#define Day_len 6

int display_menu(void); // 메인메뉴를 보여줌
int membership_store(void); // 회원가입
int login(void); // 로그인
int manual(void); // 설명서
int main_menu(void); // 로그인 후 메인메뉴
int main_1(void); // 로그인 후 메인메뉴의 메인
int schedule_watch(void); // 시간표 확인
int schedule_search(void); // 시간표 검색
int schedule_add(void); // 시간표 추가
int schedule_delete(void); // 시간표 삭제 
int schedule_store(void); // 시간표 저장
int schedule_import(void); // 시간표 입력
int schedule_call(void); // 시간표 불러오기

#pragma pack (push, 1)
typedef struct information { // 회원정보를 입력받을 구조체
    char name[NAME_len];
    char birth[BIRTH_len];
    char id[ID_len];
    char password[PASSWORD_len];
    char major[MAJOR_len];
} temp_infor;
#pragma pack(pop)

typedef struct subject{ // 시간표를 입력받을 포인터 구조체 배열
    char *name[schedule_time];
    char sub_name[30];
} temp_sub;

int main_1(void){
    while(1){
        
        int menu_1 = main_menu();

        if (menu_1 == 1)
        schedule_watch(); // 시간표 보기
        else if (menu_1 == 2)
        schedule_add(); // 시간표 입력
        else if (menu_1 == 3)
        schedule_import(); // 시간표 추가
        else if (menu_1 == 4)
        schedule_delete(); // 시간표 삭제
        else if (menu_1 == 5)
        schedule_search(); // 시간표 검색
        else if (menu_1 == 6)
        schedule_store(); // 시간표 저장
        else if (menu_1 == 7)
        schedule_call(); // 시간표 불러오기
        else if (menu_1 == 8)
        exit(1); // 나가기
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
    printf("\n\n\t\t  3. 시간표 추가   4. 시간표 삭제");
    printf("\n\n\t\t  5. 시간표 검색   6. 시간표 저장");
    printf("\n\n\t\t  7. 시간표 불러오기   8. 나가기");
    printf("\n\n\t\t     어디로 가시겠습니까? : ");
    scanf("%d",&menu2_num);

    if (menu2_num<1||menu2_num>8){
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
    temp_sub *s1[Day_len];

    int o=0, num=0;

    while(1){
        printf("1.시간표 확인  2.나가기 \n ");
        printf(": ");
        scanf("%d",&o);
        if (o==1){ // 결과 값을 출력
            while(1){
                printf("1.월요일, 2.화요일, 3.수요일, 4.목요일, 5.금요일,　6.뒤로가기\n");
                printf("무슨 요일을 출력하시겠습니까? : ");
                scanf("%d",&num);

                if (num < Day_len){ // 5보다 작으면 실행
                    for (int i =0 ;i <schedule_time; i++){
                    printf("%02d교시 : %s\n",i+1,s1[num]->name[i]);
                    }
                    continue; // 다시 while문으로
                }
                else if (num == Day_len){
                    continue; // 다시 while문으로
                }
            }
        }
        else if (o==2){
            break;
        }
        else {
            printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
        }
    }
    return 0;
}

int schedule_add(void){
    temp_sub *s1[Day_len]; // 구조체 포인터 배열로 요일을 정함

    char empty = '-';
    static int n =0;
    int time_ = 0, ext = 0;
    int time_1 = 0, time_2 = 0;
    int l = 0 , k=0 ;

    for (int i = 0; i < Day_len; i++){
        s1[i] = malloc(sizeof(struct subject));
    }

    while (1){
        printf("1.월요일, 2.화요일, 3.수요일, 4.목요일, 5.금요일,　6.뒤로가기\n");
        printf("입력하실 요일을 적어주세요. : ");
        scanf("%d",&k); 

        if (k<Day_len){ // 요일의 숫자를 적으면 실행
            while (n<schedule_time){
                printf("과목을 입력하시려면 1번을, 끝내시려면 0번을 눌러주세요. : ");
                scanf("%d",&ext); // 숫자를 입력받음
                if (ext == 0){ // ext값이 0이면 실행
                    if (n < schedule_time){ // n의 값이 0~9사이라면 실행
                        while (n<schedule_time){ // 마지막 빈 시간을 공백으로 채워줌
                            char* emp = (char*)malloc(sizeof (char)*1);
                            strcpy(emp,&empty);
                            s1[k]->name[n] = emp;
                            n++;
                        }
                    }
                    else
                    break;
                }
                else if (ext == 1){ // ext값이 1이면 실행
                    printf("과목 명을 입력해주세요. : ");
                    scanf("%s",s1[k]->sub_name);
                    l = strlen(s1[k]->sub_name); // 입력받은 과목명 길이의 값을 가져옴
                    printf("이 과목은 몇 교시에 시작합니까? : ");
                    scanf("%d",&time_2);
                    printf("이 과목은 몇 시간 수업입니까? : ");
                    scanf("%d",&time_);
                    time_ += n; //시간을 계속 유지
                    printf("다음 수업까지 빈 시간은 몇 시간 입니까?(없으면 0) : ");
                    scanf("%d",&time_1);

                    if (l>0){ // l의 값이 0 이상이면
                        time_2 -= 1; // 배열을 위해 1을 빼줌
                        while (n<time_+time_2){ // 정적변수 n의 값을 i에 대입시켜       반복문 실행
                            char* sub = (char*)malloc(sizeof (char)*(l+1)); //sub이라는 포인터에 입력받은 과목명 길이만큼 동적할당을 해줌
                            while (n<time_2){ // 앞에 빈 시간을 공백으로 채워줌
                                char* emp1 = (char*)malloc(sizeof (char)*1);
                                strcpy(emp1,&empty);
                                s1[k]->name[n] = emp1;
                                n++;
                            }   
                            strcpy(sub,s1[k]->sub_name); // 입력받은 과목명을 sub에 복사함
                            s1[k]->name[n] = sub; // 각 교시에 맞게 대입시키고 2중 포인터 사용
                            n++;
                        }
                        if (time_1!=0){ // 중간의 빈 시간이 0이 아니면 실행
                            time_1 += n; // 위에나온 값에서 다시 더해줌
                            while (n<time_1){ // 중간의 빈 시간을 공백으로 채워줌
                                char* emp_ = (char*)malloc(sizeof (char)*1);
                                strcpy(emp_,&empty);
                                s1[k]->name[n] = emp_;
                                n++;
                            }
                        }
                        else if (time_1==0) // 중간의 빈 시간이 0이면 실행
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else{
                    printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
                }
            }
        }
        else if (k == 6){
            break;
        }
    }
    return 0;
}

int schedule_delete(void){
    return 0;
}

int schedule_import(void){
    return 0;
}

int schedule_search(void){
    temp_sub *s1[Day_len];
    temp_infor t1;

    char mem_name[10];

    while(1){
    printf("\n\t\t\t시간표 관리 프로그램");
    printf("\n\t\t===================================");
    printf("\n\t    시간표를 볼 회원님의 이름을 적어주세요. : ");
    scanf("%s",mem_name);

    FILE *fp_1 = fopen(mem_name,"r");
    if (fp_1==NULL){
        printf("\t\t\t  없는 회원님입니다.\n\n\t\t   다른 회원님의 이름을 적어주세요.");
        continue;
    }
    else if (fp_1 !=NULL){
        
        return 0;
    }

    fclose(fp_1);
    }
    return 0;
}

int schedule_store(void){
    temp_sub *s1[Day_len];
    temp_infor t1;

    printf("입력하신 시간표를 저장합니다. \n");

    FILE *fp2 = fopen(t1.name,"w");
    FILE *fp3 = fopen(t1.id,"w");

    for (int i = 0; i < Day_len ; i++){
        for (int j = 0 ; j < schedule_time ; j ++){
        fwrite(s1[i]->name[j],strlen(s1[i]->name[j]),1,fp2);
        fwrite(s1[i]->name[j],strlen(s1[i]->name[j]),1,fp3);
        }
    }

    fclose(fp2);
    fclose(fp3);

    for (int j = 0 ; j < Day_len ; j++){ // 동적할당 줬던 걸 해제
        for (int i = 0; i<schedule_time; i++){
            free(s1[j]->name[i]);
        }
    }
    printf("입력하신 정보를 초기화 합니다.\n");

    return 0;
}

int schedule_call(void){

    return 0;
}

int main(){
    while(1){
    int menu = display_menu();

        if (menu == 1){
            login(); // 로그인메뉴로
            main_1(); // 로그인이 되었다면 후의 메인메뉴로
        }
        else if (menu == 2){
            manual(); // 사용 설명서
        }
        else if (menu == 3) {
            membership_store(); // 회원정보 확인
        }
        else if (menu==4){
           break; // 나가기
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

int membership_store(void){ // 추가 -> 이미 존재하는 아이디일때 다시 입력하도록. 
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

int manual(void){
    int back=0;

    printf(" 사용 설명서 \n");
    printf("1. 회원가입이 되어있지 않다면 회원가입을 한다.\n");
    printf("2. 회원가입을 한 후 로그인을 하고 '시간표 입력' <- 여기에 들어간다.\n");
    printf("3. 시간표 입력이 끝나고 수정이 필요하면 '추가', '삭제' <- 여기에 들어가서 한다.\n");
    printf("4. 시간표 입력이나 수정이 다 끝나고 제대로 입력이 되어있는지 확인하기 위해 '시간표 보기' <- 여기에 들어가서 확인한다. \n");
    printf("5. 확인까지 다 끝났으면 '시간표 저장' <- 여기에 들어가서 저장한다.\n");
    printf("※ 중요 ※\n만약 시간표 입력을 해둔 사용자라면 '시간표 불러오기' <- 여기에 들어가서 불러오고 수정을 한다.\n");

    while(1){
        printf("다 읽으셨으면 뒤로가기(1)을 입력해주세요. : ");
        scanf("%d",&back);

        if (back == 1){
            continue;
        }

        else {
            printf("잘못입력하셨습니다.\n다시 입력해주세요. \n");
        }
    }
    return 0;
}