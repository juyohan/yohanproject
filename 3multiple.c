#include <stdio.h>

int main(){
    int num=0,total=0;

    while (1){
        num++;
    if (num%3==0) 
        total = total + num;
    else if (num>100)
        break;
    }
    printf("%d",total);
}