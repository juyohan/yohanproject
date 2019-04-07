#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int draw(void);
int lose(void);
int win(void);
int pro(void);

int result[3] = {0,};
int count; 

int main(){
    int num, random;

     srand((unsigned)time(NULL));
    
    while(1){
   printf("1.가위 2.바위 3.보 4.검색 5.종료\n");
   printf("무엇을 내시겠습니까? : ");
   scanf("%d",&num);

   random = rand() % 3 + 1;

   if (num <= 3 && num >= 1){
       count++;

        if (num == random)
       draw();

        else if (((num == 1) && (random == 3)) || ((num == 2) && (random == 1)) || ((num == 3) && (random == 2)))
        win();

        else 
            lose();
   }

   else if (num == 4)
        pro();

    else if (num == 5){
        printf("프로그램을 종료합니다.\n");
        exit(1);
    }

    else {
        printf("잘못 입력하셨습니다.\n");
        printf("다시 입력해주세요.\n");
    }
    }
    return 0;
}

int draw(void){
        printf("비겼습니다.\n");
        result[1]++;
    return 0;
}

int lose(void){
        printf("졌습니다.\n");
        result[2]++;
    return 0;
}

int win(void){
        printf("이겼습니다.\n");
        result[0]++;
    return 0;
}

int pro(void){
    int num1;

        printf("지금까지 게임 한 횟수 : %d\n",count);
       printf("지금까지 이긴 횟수 : %d\n",result[0]);
       printf("지금까지 진 횟수 : %d\n",result[2]);
       printf("지금까지 비긴 횟수 : %d\n",result[1]);
       printf("이긴 확률 : %lf\n",(double)result[0]/count);
       printf("1.뒤로가기 2.종료\n");
       scanf("%d",&num1);

       if (num1 == 1)
           return 0;

       else
       exit(1);

       return 0;
}