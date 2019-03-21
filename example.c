#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int story[32], store[32];
    int position;
    int num;
} binary;

void plus(int count){


}



int main () {
    binary b1;

    int story1[32];
    int con=0;

    printf("2진수로 바꿀 숫자를 적어주세요. : ");
    scanf("%d",&b1.num);
    
    if (b1.num>=0){
        while(1){
        story1[con] = b1.num % 2;
        b1.num = b1.num / 2;

        con++;
        if (b1.num=0)
        break;
        }


    }

}