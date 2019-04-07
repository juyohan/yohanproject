#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int class_1(void);
int class_2(void);

typedef struct students {
    double imfor[2][30][3];
    int std;
    double total;
} students_num;

int main(){
    int class;

    while(1){
    printf("1반과 2반 중 어느 반으로 가시겠습니까? : ");
    scanf("%d",&class);

    if (class == 1){
        class_1();
        continue;
    }
    else if (class ==2){
        class_2();
        continue;
    }
    else {
        printf("잘못 입력하셨습니다. 처음으로 돌아갑니다.\n");
        continue;
    }
    }
    return 0;
}
// 1반
int class_1(void){
    students_num s1;
    memset(&s1, 0, sizeof(s1));

    int num;
    
    printf("몇 명 있습니까? : ");
    scanf("%d",&s1.std);

    while(1){
    printf("1.점수입력 2.합계 3.평균 4.검색 5.나가기\n");
    printf("어디 가시겠습니까? : ");
    scanf("%d",&num);

     if (num == 1) {
          for (int i = 0; i<s1.std; i++){
        printf("%d번째 학생의 국어, 영어, 수학점수를 입력해주세요. : ",i+1);
        for (int j = 0; j<3; j++){
            scanf("%lf",&s1.imfor[0][i][j]);
        }
}
    }

    else if (num == 2) {
    double total = 0;
    double total1 = 0;

    for (int i = 0; i<s1.std; i++){
        for (int j =0; j<3; j++){
    total1 += s1.imfor[0][i][j];
    }
     total += total1;
    }
    s1.total = total;
    printf("1반 %d명의 총 점수의 합계는 %lf입니다. \n",s1.std,s1.total);
    }

    else if (num == 3) {
      double avg = 0;
    avg = s1.total/s1.std;

    printf("1반 %d명의 평균은 %.2lf입니다. \n",s1.std,avg);
    }

    else if (num == 4) {
        int std = 0 ;
        printf("몇 번째의 학생의 점수를 확인하시겠습니까? : ");
        scanf("%d",&std);

        printf("%d 번째의 학생의 점수\n국어 : %lf\n영어 : %lf\n수학 : %lf\n",std-1,s1.imfor[0][std][0],s1.imfor[0][std][1],s1.imfor[0][std][2]);
    }

    else if (num == 5) {
        exit(1);
    }

    else {
        printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
        continue;
    }

    }
     return 0;
}
// 2반
int class_2(void){
    students_num s1;
    memset(&s1, 0, sizeof(s1));

    int num;
    
    printf("몇 명 있습니까? : ");
    scanf("%d",&s1.std);

    while(1){
    printf("1.점수입력 2.합계 3.평균 4.검색 5.나가기\n");
    printf("어디 가시겠습니까? : ");
    scanf("%d",&num);

     if (num == 1) {
          for (int i = 0; i<s1.std; i++){
        printf("%d번째 학생의 국어, 영어, 수학점수를 입력해주세요. : ",i+1);
        for (int j = 0; j<3; j++){
            scanf("%lf",&s1.imfor[1][i][j]);
        }
}
    }

    else if (num == 2) {
    double total = 0;
    double total1 = 0;

    for (int i = 0; i<s1.std; i++){
        for (int j =0; j<3; j++){
    total1 += s1.imfor[1][i][j];
    }
     total += total1;
    }
    s1.total = total;
    printf("2반 %d명의 총 점수의 합계는 %lf입니다. \n",s1.std,s1.total);
    }

    else if (num == 3) {
      double avg = 0;
    avg = s1.total/s1.std;

    printf("2반 %d명의 평균은 %.2lf입니다. \n",s1.std,avg);
    }

    else if (num == 4) {
        int std = 0 ;
        printf("몇 번째의 학생의 점수를 확인하시겠습니까? : ");
        scanf("%d",&std);

        printf("%d 번째의 학생의 점수\n국어 : %lf\n영어 : %lf\n수학 : %lf\n",std-1,s1.imfor[1][std][0],s1.imfor[1][std][1],s1.imfor[1][std][2]);
    }

    else if (num == 5) {
        exit(1);
    }

    else {
        printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
        continue;
    }

    }
    return 0;
}