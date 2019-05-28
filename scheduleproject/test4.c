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
#define Day_len 5

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
int schedule_call_(void); // 시간표 불러오기2
int schedule_exit(void); // 종료

char id1[30] = {0,}; // 파일 불러오기 위한 아이디
char Day_[5][10] = {"월요일", "화요일", "수요일", "목요일", "금요일"};

typedef struct information { // 회원정보를 입력받을 구조체
    char name[NAME_len];
    char birth[BIRTH_len];
    char id[ID_len];
    char password[PASSWORD_len];
    char major[MAJOR_len];
} temp_infor;

typedef struct subject{ // 자신의 시간표를 입력받을 포인터 구조체 배열
    char *name[schedule_time];
} temp_sub;

typedef struct subject_{ // 검색당한 사용자의 시간표를 입력받을 포인터 구조체 배열
    char *name_[schedule_time];
} temp_sub1;

int main_1(void){
    temp_infor t1;
    temp_sub *s1[Day_len];
    temp_sub1 *s2[Day_len];

    int re = 0, re_ = 0;

    while(1){
        int menu_1 = main_menu();

        if (menu_1 == 1){
            if (re == 0){
                printf("\n\t\t\t\t       데이터의 값이 없습니다.\n\t\t\t\t 시간표 입력 <- 여기서 입력해주세요.\n");
                continue;
            }
            else if (re > 0){
                schedule_watch(); // 시간표 보기
            }
        }
        else if (menu_1 == 2) {
            if (re == 0){ // 시간표 입력
            re = schedule_add(); // 시간표 입력을 안하고 처음에 다른곳에 들어가는 것을 방지하기 위해 값을 정해줌.
            }
            else if (re > 0) {
                printf("\n\t\t\t\t        이미 입력하셨습니다.\n\t\t\t\t     다른 메뉴를 사용해주세요.\n");
                continue;
            }
        }
        else if (menu_1 == 3){
            if (re == 0){
                printf("\n\t\t\t\t       데이터의 값이 없습니다.\n\t\t\t\t 시간표 입력 <- 여기서 입력해주세요.\n");
                continue;
            }
            else if (re > 0){
            schedule_import(); // 시간표 추가
            }
        }
        else if (menu_1 == 4){
            if (re == 0){
                printf("\n\t\t\t\t       데이터의 값이 없습니다.\n\t\t\t\t 시간표 입력 <- 여기서 입력해주세요.\n");
                continue;
            }
            else if (re > 0){
            schedule_delete(); // 시간표 삭제
            }
        }
        else if (menu_1 == 5){
            schedule_search(); // 시간표 검색
        }
        else if (menu_1 == 6){
            if (re == 0){
                printf("\n\t\t\t\t       데이터의 값이 없습니다.\n\t\t\t\t 시간표 입력 <- 여기서 입력해주세요.\n");
                continue;
            }
            else if (re > 0){
                schedule_store(); // 시간표 저장
                continue;
            }
        }
        else if (menu_1 == 7){
            if (re == 0){
                re = schedule_call(); // 시간표 불러오기
                continue;
            }
            else if (re > 0){
                int ret = schedule_call_(); // 데이터값을 가지고 있는데도 불러오기를 하는걸 방지
                if (ret == 1){
                    re = schedule_call(); // 그래도 불러오기를 하겠다면 현재 값을 초기화시키고 불러오기
                    continue;
                }
                else if (ret == 2){
                    printf("\n\t\t\t\t\t뒤로 넘어가겠습니다.\n");
                    continue;
                }
            }
        }
        else if (menu_1 == 8){
            schedule_exit(); // 나가기
        }
    }
    return 0;
}

int main_menu(void){ // 시간표 메뉴
    temp_infor t1;
    temp_sub *s1[Day_len];

    int menu2_num = 0;

    while(1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t===================================");
        printf("\n\t\t\t\t  1. 시간표 보기   2. 시간표 입력");
        printf("\n\n\t\t\t\t  3. 시간표 추가   4. 시간표 삭제");
        printf("\n\n\t\t\t\t  5. 시간표 검색   6. 시간표 저장");
        printf("\n\n\t\t\t\t  7. 시간표 불러오기   8. 나가기");
        printf("\n\t\t\t\t===================================");
        printf("\n\n\t\t\t\t     어디로 가시겠습니까? : ");
        scanf("%d",&menu2_num);

        if (menu2_num<1||menu2_num>8){
            printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
            continue;
        }
        else {
            return menu2_num;
        }
    }
    return 0;
}

int schedule_watch(void){ // 시간표 출력
    temp_sub *s1[Day_len];

    int ext=0, num=0;

    while(1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t===================================");
        printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기");
        printf("\n\t\t\t\t===================================\n");
        printf("\n\t\t\t\t 무슨 요일을 출력하시겠습니까? : ");
        scanf("%d",&num);
        num -= 1;

        if (num < 5){ // 5보다 작으면 실행
            printf("\n\t\t\t\t\t      %s \n",Day_[num]);
            for (int i =0 ;i <schedule_time; i++){
                printf("\t\t\t\t\t %02d교시 : %s\n",i+1,s1[num]->name[i]);
            }
            continue; // 다시 while문으로
        }

        else if (num == 5){
            break; // 바깥 while문으로
        }

        else {
            printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
        }
    }
    return 0;
}

int schedule_add(void){ // 잘못입력했을 때 뒤로 넘어가는게 있으면 좋겠다.
    temp_sub *s1[Day_len]; // 구조체 포인터 배열로 요일을 정함

    char sub_name[50]={0,};
    char empty[6] = "(X)";
    int time_ = 0, ext = 0, time_st = 0;
    int len = 0, Day =0, num=0;
    int n = 0, w = 0;

    for (int i = 0; i < Day_len; i++){ // 맨 처음 모든 시간표에 값을 집어넣음.
        s1[i] = malloc(sizeof(struct subject));
        for (int j = 0 ; j<schedule_time; j ++){
            char *temp = (char*)malloc(sizeof(char)*6);
            strcpy(temp,empty);
            temp[sizeof(temp)-1] = '\0';
            s1[i]->name[j] = temp;
        }
    }

    while (1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t===================================");
        printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기");
        printf("\n\t\t\t\t===================================\n");
        printf("\n\t\t\t\t 무슨 요일에 입력하시겠습니까? : ");
        scanf("%d",&Day); 
        Day = Day - 1;

        if (Day<Day_len){ // 요일의 숫자를 적으면 실행
            n = 0;
            while (n<schedule_time){
                printf("\n\t\t\t\t      1.시간표 입력  2.뒤로가기");
                printf("\n\t\t\t\t===================================");
                printf("\n\n\t\t\t\t     어디로 가시겠습니까? : ");
                scanf("%d",&ext); // 숫자를 입력받음
                if (ext == 2){ // ext값이 0이면 실행
                    break;
                }

                else if (ext == 1){ // ext값이 1이면 실행
                    printf("\n\t\t\t\t\t 수업 이름 : ");
                    scanf("%s",sub_name);
                    len = strlen(sub_name); // 입력받은 과목명 길이의 값을 가져옴
                    printf("\n\t\t\t\t        수업 시작 시간 : ");
                    scanf("%d",&time_st);
                    time_st -= 1;
                    n = time_st;
                    w = time_st; 
                    printf("\n\t\t\t\t\t 수업 시간 : ");
                    scanf("%d",&time_);
                    printf("\n\t\t\t\t===================================");
        
                    if (len>0){ // l의 값이 0 이상이면
                        while(w<time_+time_st){
                            free(s1[Day]->name[w]); // 해당 날짜, 시간의 동적할당 해제
                            s1[Day]->name[w] = NULL; // 포인터 변수의 값을 NULL처리함
                            w++;
                        } 

                        while (n<time_+time_st){ // 정적변수 n의 값을 i에 대입시켜       반복문 실행 
                            char* sub = (char*)malloc(sizeof (char)*(len+1)); //sub이라는 포인터에 입력받은 과목명 길이만큼 동적할당을 함
                            strcpy(sub,sub_name); // 입력받은 과목명을 sub에 복사함
                            s1[Day]->name[n] = sub; // 각 교시에 맞게 대입시키고 2중 포인터 사용
                            n++;
                        }
                            continue;
                    }
                    else
                    {
                        printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t    뒤로 돌아갑니다. \n");
                        continue;
                    }
                }
                else{
                    printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
                    continue;
                }
            }
        }
        else if (Day == Day_len){
            num = strlen(s1[0]->name[0]);
            return num;
        }
    }
    return 0;
}

int schedule_delete(void){ // 시간표 삭제
    temp_sub *s1[Day_len];

    int num=0, Day=0, SUB=0, TIME=0, n=0, len=0;
    char empty[6] = "(X)";

    while(1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t==================================="); 
        printf("\n\t\t\t\t 1.요일삭제  2.과목삭제  3.뒤로가기");
        printf("\n\t\t\t\t===================================");
        printf("\n\n\t\t\t\t     어디로 가시겠습니까? : ");
        scanf("%d",&num);

        if (num==1){ // 요일삭제
            while (1){
                printf("\n\t\t\t\t\t시간표 관리 프로그램");
                printf("\n\t\t\t\t==================================="); 
                printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기");
                printf("\n\t\t\t\t===================================\n");
                printf("\n\t\t\t\t 무슨 요일을 삭제하시겠습니까? : ");
                scanf("%d",&Day);
                Day -= 1; // 배열을 위해 빼줌

                if (Day == Day_len){ // 뒤로가기
                    break;
                }

                else if (Day<Day_len){ 
                    for (int i = 0; i<schedule_time; i++){ // 해당 요일의 메모리 값을 초기화 시킴
                        free(s1[Day]->name[i]); // 동적할당 해제
                        s1[Day]->name[i] = NULL; // 포인터 변수를 NULL처리함.
                    }

                    while(n<schedule_time){ // 초기화 시키고 비어있다는 표시인 - <- 이거를 대입
                        char* emt_ = (char*)malloc(sizeof(char)*6);
                        strcpy(emt_,empty);
                        emt_[sizeof(emt_)-1] = '\0'; // 마지막 공간을 NULL처리함
                        s1[Day]->name[n] = emt_;
                        n++;
                    }

                    printf("\n\n\t\t\t\t\t삭제가 완료되었습니다.\n");
                    break; // 삭제완료되면 뒤로
                }

                else { 
                    printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
                }
            }
        }

        else if (num==2){ // 과목 삭제
            while(1){
                printf("\n\t\t\t\t\t시간표 관리 프로그램");
                printf("\n\t\t\t\t==================================="); 
                printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기\n");
                printf("\n\t\t\t\t===================================");
                printf("\n\t\t\t     무슨 요일의 과목을 삭제하시겠습니까? : ");
                scanf("%d",&Day);
                Day -= 1; // 배열을 위해 빼줌

                if (Day == 5){ // 뒤로가기
                    break;
                }

                else if(Day < Day_len){
                    printf("\n\t\t\t\t     몇 교시의 과목입니까? : ");
                    scanf("%d",&SUB);
                    SUB -= 1; // 배열을 위해 빼줌
                    len = strlen(s1[Day]->name[SUB]); // 해당 요일에 값이 있는지 확인하기 위해 길이를 구함

                    if (len>0){ // 해당 요일의 길이가 있다면
                        printf("\n\t\t\t\t   몇 시간 삭제하시겠습니까? : ");
                        scanf("%d",&TIME);
                        while(SUB<SUB+TIME){
                            free(s1[Day]->name[SUB]); // 동적할당 해제
                            s1[Day]->name[SUB] = NULL; // 포인터 변수의 값을 NULL처리함.
                            SUB++;
                        }
                        while(SUB<SUB+TIME){ // 메모리 해제한 공간에 값 대입
                            char* emt_ = (char*)malloc(sizeof(char)*6);;
                            strcpy(emt_,empty);
                            emt_[sizeof(emt_)-1] = '\0'; // 마지막 공간을 NULL처리함
                            s1[Day]->name[SUB] = emt_;
                            SUB++;
                        }
                        printf("\n\t\t\t\t===================================");
                        printf("\n\n\t\t\t\t\t삭제가 완료되었습니다.\n");
                        break;
                    }

                    else if (len == 0) { // 길이가 0 이면 실행
                        printf("\n\t\t\t\t 해당 요일의 시간표가 비어있습니다.");
                        printf("\n\t\t\t    시간표를 입력하거나 불러온 뒤 사용해주세요.");
                        printf("\n\t\t\t\t\t   뒤로 넘어갑니다.\n");
                        break;
                    }
                }
                else {
                    printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
                }
            }
        }

        else if (num==3){
            break; // 뒤로가기
        }

        else {
            printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
        }
    }
    return 0;
}

int schedule_import(void){ // 시간표 추가 -> 입력을 받으면 값 저장을 못함.
    temp_sub *s1[Day_len];

    char sub_name[50]={0,};
    int Day=0,num=0,len=0,len1=0;
    int sub_num=0, sub_af=0;

    while (1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t==================================="); 
        printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기\n");
        printf("\n\t\t\t\t===================================");
        printf("\n\t\t\t\t 무슨 요일에 추가하시겠습니까? : ");
        scanf("%d",&Day);
        Day -= 1;

        while(Day<5){ // 추가 입력
            printf("\n\t\t\t\t\t 수업 이름 : ");
            scanf("%s",sub_name);
            len = strlen(sub_name);
            printf("\n\t\t\t\t        수업 시작 시간 : ");
            scanf("%d",&sub_num);
            sub_num -= 1; // 배열을 위해 1을 뺌
            printf("\n\t\t\t\t\t 수업 시간 : ");
            scanf("%d",&sub_af);
            sub_af += sub_num; // 수업시간의 길이를 구함.

            len1 = strlen(s1[Day]->name[sub_num]); // 초기화를 할지 말지 결정하기 위해 배열의 길이를 구함.

            if (len1 != 0){ // 안에 있는 값이 있다면

                for (int i = sub_num; i <sub_af; i++){ // 초기화를 해준다.
                    free(s1[Day]->name[i]);
                    s1[Day]->name[i] = NULL;
                }

                while(sub_num<sub_af){ // 그리고 그 곳에 값을 입력해줌.
                    char* sub_sub = (char*)malloc(sizeof(char)*(len+1));
                    strcpy(sub_sub,sub_name);
                    s1[Day]->name[sub_num] = sub_sub;
                    sub_num++;
                }
            }

            else if (len1 == 0){ // 값이 없다면 바로 입력
                while(sub_num<sub_af){
                    char* sub_sub = (char*)malloc(sizeof(char)*(len+1));
                    strcmp(sub_sub,sub_name);
                    s1[Day]->name[sub_num] = sub_sub;
                    sub_num++;
                }
            }
            printf("\n\t\t\t\t       입력이 완료되었습니다. \n");
            printf("\n\t\t\t\t\t 1.추가  2.뒤로가기 ");
            printf("\n\n\t\t\t\t     어디로 가시겠습니까? : ");
            scanf("%d",&num);

            if (num==1){ // 추가
                continue;
            }

            else if (num==2){ // 뒤로가기
                break;
            }
            
            else { // 다시 입력
                printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
            }
        }

        if(Day==5){ // 메뉴로
            break;
        }

    }
    return 0;
}

int schedule_search(void){ // 시간표 검색하기
    temp_sub1 *s2[Day_len];

    int num=0, len = 0, str = 0;
    char mem_[NAME_len]={0,};
    char major_[MAJOR_len] = {0,};

    for (int i = 0 ; i < Day_len ; i++){
        s2[i] = malloc(sizeof(struct subject_));
    }

    while(1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t===================================");
        printf("\n\t\t\t\t  1.이름으로 확인  2.학번으로 확인\n\n\t\t\t\t  3.뒤로가기");
        printf("\n\t\t\t\t===================================\n");
        printf("\n\t\t\t\t    어디로 가시겠습니까? : ");
        scanf("%d",&num);

        if (num==1){
            printf("\n\t\t\t\t\t검색할 이름 : ");
            scanf("%s",mem_);

            FILE *fp_1 = fopen(mem_,"r"); //

            if (fp_1 == NULL){
                printf("\n\t\t\t\t\t  없는 회원님입니다.\n\t\t\t\t   다른 회원님의 이름을 적어주세요.");
            }

            else if (fp_1 != NULL){
                for (int i = 0; i < Day_len; i++){
                    for (int j = 0 ; j < schedule_time; j++){
                        char sub1[50] = {0,}; // 읽어올 과목을 저장할 문자열

                        fgets(sub1,sizeof(sub1),fp_1); // 한줄씩 읽어옴
                        sub1[strlen(sub1)-1] = '\0'; // 마지막엔 공백처리
            
                        len = strlen(sub1); // 읽어온 과목의 길이 구함

                        char *sub_s1 = (char*)malloc(sizeof(char)*(len+1));
                        strcpy(sub_s1,sub1);
                        s2[i]->name_[j] = sub_s1;
                    }
                }
                int num = 0;

                while(1){
                    printf("\n\t\t\t\t\t시간표 관리 프로그램");
                    printf("\n\t\t\t\t===================================");
                    printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기\n");
                    printf("\n\t\t\t\t===================================");
                    printf("\n\t\t\t\t 무슨 요일을 출력하시겠습니까? : ");
                    scanf("%d",&num);
                    num -= 1;

                    if (num < 5){ // 5보다 작으면 실행
                        printf("\n\t\t\t\t\t      %s \n",Day_[num]);
                        for (int i =0 ;i <schedule_time; i++){
                            printf("\t\t\t\t\t %02d교시 : %s\n",i+1,s2[num]->name_[i]);
                        }
                        continue; // 다시 while문으로
                    }
                    else if (num == 5){
                        break;
                    }
                }
            }
            fclose(fp_1);
            continue;
        }

        else if (num == 2){
            printf("\n\t\t\t\t\t검색할 학번 : ");
            scanf("%s",major_);

            FILE *fp_2 = fopen(major_,"r");

            if (fp_2 == NULL){
                printf("\n\t\t\t\t\t  없는 회원님입니다.\n\t\t\t\t   다른 회원님의 이름을 적어주세요.");
            }
            else if (fp_2 != NULL){
                for (int i = 0; i < Day_len; i++){
                    for (int j = 0 ; j < schedule_time; j++){
                        char sub2[50] = {0,}; // 읽어올 과목을 저장할 문자열

                        fgets(sub2,sizeof(sub2),fp_2); // 한줄씩 읽어옴
                        sub2[strlen(sub2)-1] = '\0'; // 마지막엔 공백처리
            
                        len = strlen(sub2); // 읽어온 과목의 길이 구함

                        char *sub_s2 = (char*)malloc(sizeof(char)*(len+1));
                        strcpy(sub_s2,sub2);
                        s2[i]->name_[j] = sub_s2;
                    }
                }
                int num = 0;

                while(1){
                    printf("\n\t\t\t\t\t시간표 관리 프로그램");
                    printf("\n\t\t\t\t===================================");
                    printf("\n\t\t\t\t    1.월요일  2.화요일  3.수요일\n\t\t\t\t    4.목요일  5.금요일  6.뒤로가기\n");
                    printf("\n\t\t\t\t===================================");
                    printf("\n\t\t\t\t 무슨 요일을 출력하시겠습니까? : ");
                    scanf("%d",&num);
                    num -= 1;

                    if (num < 5){ // 5보다 작으면 실행
                        printf("\n\t\t\t\t\t      %s \n",Day_[num]);
                        for (int i =0 ;i <schedule_time; i++){
                            printf("\t\t\t\t\t %02d교시 : %s\n",i+1,s2[num]->name_[i]);
                        }
                        continue; // 다시 while문으로
                    }
                    else if (num == 5){
                        break;
                    }
                }
                continue;
            }
            fclose(fp_2);
        }
        else if (num == 3){
            str = strlen(s2[0]->name_[0]);
            if (str > 0){
                for (int i = 0 ; i < Day_len ; i++){ // 동적할당 해제
                    for (int j = 0 ; j < schedule_time ; j++){
                        free(s2[i]->name_[j]);
                        s2[i]->name_[j] = NULL; // 포인터 변수의 값도 NULL처리함.
                    }
                    free(s2[i]); 
                    s2[i] = NULL;
                }
                break;
            }
            else if (str == 0){
                break;
            }
        }
        else {
            printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
        }
    }
    return 0;
}

int schedule_store(void){
    temp_sub *s1[Day_len];
    temp_infor t1;

    printf("\n\t\t\t\t    입력하신 시간표를 저장합니다. \n");

    FILE *fp = fopen(id1,"r"); // id1이름을 읽기모드로 불러옴
        
    fgets(t1.name,sizeof(t1.name),fp);
    t1.name[strlen(t1.name)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.birth,sizeof(t1.birth),fp);
    t1.birth[strlen(t1.birth)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.id,sizeof(t1.id),fp);
    t1.id[strlen(t1.id)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.password,sizeof(t1.password),fp);
    t1.password[strlen(t1.password)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.major,sizeof(t1.major),fp);
    t1.major[strlen(t1.major)-1] = '\0'; // 마지막 공간을 0으로 만들어줌

    fclose(fp);

    FILE *fp2 = fopen(t1.name,"w");
    FILE *fp3 = fopen(t1.major,"w");

    for (int i = 0; i < Day_len ; i++){
       
        for (int j = 0; j<schedule_time; j++){
            char sub[50]={0,}; // 각 시간표의 결과 값을 저장하기 위한 배열

            strcpy(sub,s1[i]->name[j]); // 각 시간표의 값을 복사함

            fprintf(fp2,"%s\n",sub);
            fprintf(fp3,"%s\n",sub);
        }
    }

    fclose(fp2);
    fclose(fp3);
    return 0;
}

int schedule_call(void){ // 시간표 불러오기
    temp_sub *s1[Day_len];
    temp_infor t1;

    int len = 0, len_ = 0;

    printf("\n\t\t\t\t    저장된 시간표를 불러옵니다. \n");

    FILE *fp = fopen(id1,"r"); // id1이름을 읽기모드로 불러옴
        
    fgets(t1.name,sizeof(t1.name),fp);
    t1.name[strlen(t1.name)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.birth,sizeof(t1.birth),fp);
    t1.birth[strlen(t1.birth)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.id,sizeof(t1.id),fp);
    t1.id[strlen(t1.id)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.password,sizeof(t1.password),fp);
    t1.password[strlen(t1.password)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
    fgets(t1.major,sizeof(t1.major),fp);
    t1.major[strlen(t1.major)-1] = '\0'; // 마지막 공간을 0으로 만들어줌

    fclose(fp);

    FILE *fp1 = fopen(t1.name,"r"); // t1.name으로 되어있는 파일을 읽어옴

    if (fp1 != NULL){ // 파일이 있을 경우
        for (int i = 0; i < Day_len; i++){
            s1[i] = malloc(sizeof(struct subject));
            for (int j = 0 ; j < schedule_time; j++){
                char sub[50] = {0,}; // 읽어올 과목을 저장할 문자열

                fgets(sub,sizeof(sub),fp1); // 한줄씩 읽어옴
                sub[strlen(sub)-1] = '\0'; // 마지막엔 공백처리
            
                len = strlen(sub); // 읽어온 과목의 길이 구함

                char *sub_s = (char*)malloc(sizeof(char)*(len+1));
                strcpy(sub_s,sub);
                s1[i]->name[j] = sub_s;
            }
        }

        printf("\n\t\t\t\t        시간표 불러왔습니다.\n");
        fclose(fp1); // 파일 닫음

        len_ = strlen(s1[0]->name[0]);
        return len_; // 이 값을 리턴해 메뉴에서 시간표 입력<-여기로 못들어가게 하기위함.
    }
    else if (fp1 == NULL){ // 파일이 없을 경우
        printf("\n\t\t\t\t       저장된 시간표가 없습니다.\n\t\t\t\t 시간표 입력 <- 여기서 입력해주세요.\n");
    }
    return 0;
}

int schedule_call_(void){ // 이미 데이터가 있는데 눌렀을 경우를 대비함.
    temp_sub *s1[Day_len];

    int num = 0;
    
    printf("\n\t\t\t\t\t      ※ 중요 ※\n\t\t\t\t       1.불러오기  2.뒤로가기\n\t\t\t\t     이미 데이터가 있습니다. : ");
    scanf("%d",&num);
    if (num == 1){ // 불러오기 위해 메모리 해제
        for (int i = 0 ; i < Day_len ; i++){ // 동적할당 해제
            free(s1[i]); 
            s1[i] = NULL;
        }
        return num;
    }
    else if (num == 2){
        return num;
    }
    else {
        printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
    }
    return 0;
}

int schedule_exit(void){ // 시간표 종료
    temp_sub *s1[Day_len];

    for (int i = 0 ; i < Day_len ; i++){ // 동적할당 해제
        for (int j = 0 ; j < schedule_time ; j++){
            free(s1[i]->name[j]);
            s1[i]->name[j] = NULL; // 포인터 변수의 값도 NULL처리함.
        }
        free(s1[i]); 
        s1[i] = NULL;
    }

    exit(1); // 나가기

    return 0;
}

int main(){ // 메인함수
    while(1){
    int menu = display_menu();

        if (menu == 1){
            int m = login(); // 로그인메뉴
            if (m == 1){
                main_1(); // 로그인이 되었다면 후의 메인메뉴로
            }
            else { //안되면 다시 메인메뉴로
                continue;
            }
        }
        else if (menu == 2){
            manual(); // 사용 설명서
        }
        else if (menu == 3) {
            membership_store(); // 회원정보 회원가입
        }
        else if (menu==4){
           break; // 나가기
        }
    }
return 0;
}

int display_menu(void){ // 메뉴 인터페이스
    int menu_num = 0;

    while(1){
        menu_num=0;
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t===================================");
        printf("\n\t\t\t\t   1. 로그인\t\t2. 사용방법");
        printf("\n\n\t\t\t\t   3. 회원가입\t\t4. 나가기");
        printf("\n\t\t\t\t===================================");
        printf("\n\n\t\t\t\t     어디로 가시겠습니까? : ");
        scanf("%d",&menu_num);

        if (menu_num<1 || menu_num>4){
            printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
            continue;
        }
        else {
            return menu_num;
        } 
    }
    return 0;
}

int membership_store(void){ // 회원가입 
    temp_infor t1;

    printf("\n\t\t\t\t\t시간표 관리 프로그램");
    printf("\n\t\t\t\t===================================");
    printf("\n\t\t\t\t\t  이름  : ");
    scanf("%s",t1.name);
    printf("\n\t\t\t\t\t생년월일 : ");
    scanf("%s",t1.birth);

    while(1){ // 아이디가 존재한 아이디로 만드는지 
        printf("\n\t\t\t\t\t 아이디  : ");
        scanf("%s",t1.id);

        FILE *fp5 = fopen(t1.id,"r"); // t1.id이름으로 되어있는 파일 읽어오기

        if (fp5 != NULL){ // 파일이 존재하면 실행
            printf("\n\t\t\t\t  이미 존재하고 있는 아이디입니다.\n\t\t\t\t  다른 아이디로 입력해주세요.\n");
            fclose(fp5); // 파일 메모리 닫기
        }   

        else if (fp5 == NULL){ // 파일이 존재하지 않으면 계속 입력
            printf("\n\t\t\t\t\t비밀번호 : ");
            scanf("%s",t1.password);
            printf("\n\t\t\t\t\t  학번  : ");
            scanf("%s",t1.major);

            FILE *fp4 = fopen(t1.id,"w"); // 파일을 쓰기모드로 불러오기

            fwrite(t1.name,strlen(t1.name),1,fp4);
            fprintf(fp4,"\n");
            fwrite(t1.birth,strlen(t1.birth),1,fp4);
            fprintf(fp4,"\n");
            fwrite(t1.id,strlen(t1.id),1,fp4);
            fprintf(fp4,"\n");
            fwrite(t1.password,strlen(t1.password),1,fp4);
            fprintf(fp4,"\n");
            fwrite(t1.major,strlen(t1.major),1,fp4);
            fprintf(fp4,"\n");

            fclose(fp4); // 파일 메모리 닫기
            break;
        }
    }
    printf("\n\t\t\t\t\t회원가입을 축하합니다.\n");

    return 0;
}

int login(void){ // 로그인
    temp_infor t1;

    char password1[30]={0,};
    int re=0 ;


    while(1){
        printf("\n\t\t\t\t\t시간표 관리 프로그램");
        printf("\n\t\t\t\t===================================");
        printf("\n\n\t\t\t\t\t 아이디  :  ");
        scanf("%s",id1);
        printf("\n\t\t\t\t\t비밀번호 :  ");
        scanf("%s",password1);

        FILE *fp = fopen(id1,"r"); // id1이름을 읽기모드로 불러옴

        if (fp == NULL){ // 파일이 없어 NULL값을 반환하면 실행
            printf("\n\t\t\t\t\t없는 아이디입니다.\n\t\t\t\t\t메인메뉴로 넘어갑니다.\n");
            return 0; // 반복문 돌리기
        }

        else if (fp != NULL){
            fgets(t1.name,sizeof(t1.name),fp);
            t1.name[strlen(t1.name)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
            fgets(t1.birth,sizeof(t1.birth),fp);
            t1.birth[strlen(t1.birth)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
            fgets(t1.id,sizeof(t1.id),fp);
            t1.id[strlen(t1.id)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
            fgets(t1.password,sizeof(t1.password),fp);
            t1.password[strlen(t1.password)-1] = '\0'; // 마지막 공간을 0으로 만들어줌
            fgets(t1.major,sizeof(t1.major),fp);
            t1.major[strlen(t1.major)-1] = '\0'; // 마지막 공간을 0으로 만들어줌

            re = strcmp(password1,t1.password); // 입력한 비밀번호와 저장한 비밀번호가 일치한지 비교한 후 참이면 0, 거짓이면 1을 대입

            if (re == 0){ 
                printf("\n\t\t\t\t\t     환영합니다.\n");
                int n = 1; 
                return n; // 제대로 로그인이 되어있는지 아니면 틀렸는데 넘어가는지 확인하기위한 리턴 값
            }  

            else if (re != 1) {
                printf("\n\t\t\t\t\t비밀번호가 틀렸습니다. \n");
                continue; // 반복문 돌리기
            }
        }
    fclose(fp);
    }
    return 0;
}

int manual(void){ // 사용 설명서
    int back=0;

    printf("\n\t\t\t\t\t    사용 설명서 \n");
    printf("\t\t\t 　1. 회원가입이 되어있지 않다면 회원가입을 한다.\n");
    printf("\t\t2. 회원가입을 한 후 로그인을 하고 '시간표 입력' <- 여기에 들어간다.\n");
    printf("\t    3. 시간표 입력이 끝나고 수정이 필요하면 '추가', '삭제' <- 여기에 들어가서 한다.\n");
    printf("\t4. 시간표 입력이나 수정이 다 끝나고 제대로 입력이 되어있는지 확인하기 위해\n\t\t\t\t '시간표 보기' <- 여기에 들어가서 확인한다. \n");
    printf("\t\t 5. 확인까지 다 끝났으면 '시간표 저장' <- 여기에 들어가서 저장한다.\n");
    printf("\n\t\t\t\t\t      ※ 중요 ※\n\t   만약 시간표 입력을 해둔 사용자라면 '시간표 불러오기' <- 여기에 들어가서 불러오고\n\t\t\t 수정을 하고 마지막엔 '시간표 저장' <- 여기를 꼭 들어간다.\n");

    while(1){
        printf("\n\t\t\t  다 읽으셨으면 뒤로가기(1)을 입력해주세요. : ");
        scanf("%d",&back);

        if (back == 1){
            return 0;
        }

        else {
            printf("\n\t\t\t\t\t  잘못입력하셨습니다.\n\t\t\t\t\t  다시 입력해주세요. \n");
        }
    }
    return 0;
}