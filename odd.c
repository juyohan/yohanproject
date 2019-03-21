#include <stdio.h>

int main(){
    int num=1,total=0;

    while (1){
        total = total + num;
        num = num * 2 + 1;
     if (total>100)
        break;
    }
    printf("%d",total);
}