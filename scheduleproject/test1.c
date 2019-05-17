#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <termios.h>


#define scheudule_time 10
#define Day_len 6

typedef struct subject{
    char *name[scheudule_time];
    char sub_name[30];
} temp_sub;

int main(){
    temp_sub *s1[Day_len]; // 구조체 포인터 배열로 요일을 정함
    char empty = '-';
    static int n =0;
    int time_ = 0,ext = 0;
    int time_1 = 0, time_2 = 0;
    int l = 0 , i=0, k=0, o=0, num=0;

    for (int i = 0; i < Day_len; i++){
        s1[i] = malloc(sizeof(struct subject));
    }

    while (1){
        printf("1.월요일, 2.화요일, 3.수요일, 4.목요일, 5.금요일,　6.나가기\n");
        printf("입력하실 요일을 적어주세요. : ");
        scanf("%d",&k); 

        if (k<Day_len){ // 요일의 숫자를 적으면 실행
            while (n<scheudule_time){
                printf("과목을 입력하시려면 1번을, 끝내시려면 0번을 눌러주세요. : ");
                scanf("%d",&ext); // 숫자를 입력받음
                if (ext == 0){ // ext값이 0이면 실행
                    if (n < scheudule_time){ // n의 값이 0~9사이라면 실행
                        while (n<scheudule_time){ // 마지막 빈 시간을 공백으로 채워줌
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

    while(1){
        printf("결과 값을 출력하시겠습니까?(1번) 아니면 나가시겠습니까?(2번) : ");
        scanf("%d",&o);
        if (o==1){ // 결과 값을 출력
            while(1){
                printf("1.월요일, 2.화요일, 3.수요일, 4.목요일, 5.금요일,　6.뒤로가기\n");
                printf("무슨 요일을 출력하시겠습니까? : ");
                scanf("%d",&num);

                if (num < Day_len){ // 5보다 작으면 실행
                    for (int i =0 ;i <scheudule_time; i++){
                    printf("%02d교시 : %s\n",i+1,s1[num]->name[i]);
                    }
                    continue; // 다시 while문으로
                }
                else if (num == Day_len){
                    continue; // 다시 while문으로
                }
            }
        }
        else if (o==2){ // 나갈때 메모리 정리
            for (int j = 0 ; j < Day_len ; j++){
                for (int i = 0; i<scheudule_time; i++){
                    free(s1[j]->name[i]);
                }
            }
            break;
        }
    }
   return 0;
}