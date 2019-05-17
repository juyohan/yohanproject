#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(){
    int arraySize=10;
    char *name[arraySize];
    char buffer[30];
    char empty = '-';
    static int n =0;
    int time_ = 0,ext = 0;
    int time_1 = 0;
    int l = 0;

    while (n<arraySize){
        printf("듣는 과목이 없으시면 0번을, 계속 입력하시려면 1번을 눌러주세요. : ");
        scanf("%d",&ext); // 숫자를 입력받음
        if (ext == 0){ // ext값이 0이면 실행
            if (n < arraySize){ // n의 값이 0~9사이라면 실행
                while (n<arraySize){
                    char* emp = (char*)malloc(sizeof (char)*1);
                    strcpy(emp,&empty);
                    name[n] = emp;
                    n++;
                }
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

            if (l>0){ // l의 값이 0 이상이면
                while (n<time_){ // 정적변수 n의 값을 i에 대입시켜 반복문 실행
                char* sub = (char*)malloc(sizeof (char)*(l+1)); // sub이라는 포인터에 입력받은 과목명 길이만큼 동적할당을 해줌
                strcpy(sub,buffer); // 입력받은 과목명을 sub에 복사함
                name[n] = sub; // 각 교시에 맞게 대입시키고 2중 포인터 사용
                n++;
                }
                if (time_1!=0){
                    time_1 += n; // 위에나온 값에서 다시 더해줌
                    while (n<time_1){
                        char* emp_ = (char*)malloc(sizeof (char)*1);
                        strcpy(emp_,&empty);
                        name[n] = emp_;
                        n++;
                    }
                }
                else if (time_1==0)
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

    for (int i = 0; i<arraySize; i++){
        printf("%02d: %s\n",i+1,name[i]);
        free(name[i]);
    }
   return 0;

}