#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(){
    int arraySize=10;
    char *name[arraySize];
    char buffer[30],day[10];
    char empty = '-';
    static int n =0;
    int time_ = 0,ext = 0;
    int time_1 = 0;
    int l = 0,k=0,num=0;

    while (n<arraySize){
        // if (n==0){
        //     printf("무슨 요일의 시간표를 적으십니까? : ");
        //     scanf("%s",day);
        //     k = strlen(day);
        //     char* day_ = (char*)malloc(sizeof(char)* k);
        //     strcpy(day_,day);
        //     name[n] = day_;
        //     n++;
        // }
        // else {
            printf("듣는 과목이 없으시면 0번을, 계속 입력하시려면 1번을 눌러주세요. : ");
            scanf("%d",&ext); // 숫자를 입력받음
            if (ext == 0){ // ext값이 0이면 실행
                if (n < 11) // n의 값이 1~10사이라면 실행
                for (int i = n ; i <= arraySize; i++){
                    char* emp = (char*)malloc(sizeof (char)*1);
                    strcpy(emp,&empty);
                    name[i] = emp;
                    n++;
                }
                else
                break;
            }
            else if (ext == 1){ // ext값이 1이면 실행
                printf("과목 명을 입력해주세요. : ");
                scanf("%s",buffer);
                l = strlen(buffer); // 입력받은 과목명 길이의 값을 가져옴
                printf("이 과목은 몇 시간 수업입니까? : ");
                scanf("%d",&time_);
                time_ += n; //시간을 계속 유지
                printf("다음 수업까지 빈 시간은 몇 시간 입니까?(없으면 0) : ");
                scanf("%d",&time_1);
                num = time_1; // time_1의 값을 num에 대입
                time_1 += n;

                if (l>0){ // l의 값이 0 이상이면
                    for (int i = n; i < time_; i++){ // 정적변수 n의 값을 i에 대입시켜 반복문 실행
                    char* sub = (char*)malloc(sizeof (char)*(l+1)); // sub이라는    포인터에 입력받은 과목명 길이만큼 동적할당을 해줌
                    strcpy(sub,buffer); // 입력받은 과목명을 sub에 복사함
                    name[i] = sub; // 각 교시에 맞게 대입시키고 2중 포인터 사용
                    n++;
                    }
                    time_1 += n; // 위에나온 값에서 다시 더해줌
                    if(num == 0){ // 빈 시간이 0이면 다시 처음으로
                        continue;
                    }
                    else { // 빈 시간이 0이 아니면 실행
                        for (int i = n; i < time_1; i++){
                        char* emp_ = (char*)malloc(sizeof (char)*1);
                        strcpy(emp_,&empty);
                        name[i] = emp_;
                        n++;
                        }
                    }
                }
                else
                {
                    break;
                }
                }
            else{
                printf("잘못입력하셨습니다. 다시 입력해주세요.\n");
                }
        // }
    }
    printf("%s\n",name[0]);
    free(name[0]);
    for (int i = 1; i<=arraySize; i++){
        printf("%02d: %s\n",i,name[i]);
        free(name[i]);
    }
   return 0;

}