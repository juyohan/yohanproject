#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX 5

int lotto(num);

int main(void)
{
    int leg;
    char inp[5];
    printf("로또 프로그램을 실행시키시겠습니까?\n");
    printf("실행하실려면 'yes'를 안하시려면 'no'를 입력해주세요. :");
    scanf("%s",inp);
    leg = strlen(inp);

    if (leg == 3){
        lotto();
    }
    else if (leg == 2){
        printf("로또 프로그램을 종료합니다.\n");
    }
    return 0;
}

int lotto(num)
{
    int index=0;
    srand(time(NULL));

    for (index=0;index<MAX;index++){
        printf("%d",1 + (rand() % 45));
        printf("\n");
        sleep(2);
    }
}
