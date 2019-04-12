#include <stdio.h>
#include <stdlib.h>

typedef struct information{
    char name[10];
    int kor,eng,math;
    int total_;
    double avg_;
} infor_;

int num;

int main(){
    infor_ i1;

    printf("몇 명의 학생의 정보를 입력하시겠습니까? : ");
    scanf("%d",&num);

    for (int i = 1; i<=num; i++){
        printf("학생의 이름을 입력해주세요. : ");
        scanf("%s",i1.name);
    printf("학생의 국어, 영어, 수학 점수를 각각 입력해주세요. : ");
    scanf("%d %d %d",&i1.kor,&i1.eng,&i1.math);
    i1.total_ = i1.kor+i1.eng+i1.math;
    i1.avg_ = i1.total_/num;

    FILE *fp = fopen(i1.name,"w");
    fwrite(&i1,sizeof(i1),1,fp);
    printf("파일이 저장되었습니다.\n");
    fclose(fp);
    }

    int num_;
    char stu[10];

    printf("저장된 파일을 읽어오겠습니까? \n1.예 2.아니요 : ");
    scanf("%d",&num_);


    while(1){
    if (num_ == 1){
        printf("어느 학생의 정보를 가져오시겠습니까?\n이름을 입력해주세요. : ");
        scanf("%s",stu);
        FILE *fp = fopen(stu,"r");
        fread(&i1,sizeof(i1),1,fp);
        printf("국어 점수 : %d\n영어 점수 : %d\n수학 점수 : %d\n",i1.kor,i1.eng,i1.math);
        printf("총 합계 : %d\n",i1.total_);
        printf("평균 값 : %.2lf",i1.avg_);
        fclose(fp);
    }
    else if (num_ == 2){
        printf("종료하겠습니다.\n");
        exit(1);
    }
    else {
        printf("입력된 숫자가 잘못되었습니다.\n 종료합니다.\n");
        exit(1);
    }
    }
    return 0;
}