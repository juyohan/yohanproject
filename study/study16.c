#include <stdio.h>

int main()
{
    int x[10],y[10];
    int z[10];
    int a,i,b=0,h;

    printf("원소의 갯수를 정해주세요.(최대갯수 10개) : ");
    scanf("%d",&a);
    for (i=0;i<a;i++){
        printf("x의 %d번째 원소 : ",i+1);
        scanf("%d",&x[i]);
    }
    for (i=0;i<a;i++){
        printf("y의 %d번째 원소 : ",i+1);
        scanf("%d",&y[i]);
    }

    for (int k=0;k<a;k++){
        for (int j=0;j<a;j++){
            if (x[k] == y[j]){
            z[b] = x[k];
            b++;
            }
        }
    }

    printf("\n");
    return 0;
}

