#include <stdio.h>


int main()
{
    int i , k =100;
    int sum=0,sum1= 0 ,sum2=0;

    for (i=1;i<101;i++)
    {
        sum = sum + i;
       }
    for (int j = 0; j < 50 ; j++){
        sum1 = (k-j) + j;
        sum2 += sum1;
        
    }
    sum2 = sum2 + 50; 
    
    printf("1부터 100까지의 합 : %d\n",sum);
     printf("1부터 100까지의 합 : %d\n",sum2);
    return 0;
}
