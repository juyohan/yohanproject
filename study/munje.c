// #include <stdio.h>

// int main(){
//     printf("Fun Programming!");   
//     return 0;
// }

// #include <stdio.h>

// int main(void){
//     printf("(@) (@)\n");
//     printf("(=^.^=)\n");
//     printf("(-m-m-)");
// }

// #include <stdio.h>

// int main(){
//     char *name;
//     printf("이름을 적어주세요. : ");
//     scanf("%s",name);
//     int a,b;
//     printf("키랑 몸무게 순서대로 적어주세요. : ");
//     scanf("%d %d",&a,&b);
    
//     printf("%s의 키는 %d입니다.\n",name,a);
//     printf("%s의 몸무게는 %d 입니다.",name,b);
//     return 0;
// }

// #include <stdio.h>

// int main(){
//     int a;
//     printf("구구단 몇 단을 출력하시겠습니까? : ");
//     scanf("%d",&a);
//     for (int i=1;i<11;i++){
//         printf("%d * %d = %d\n",a,i,a*i); 
//     }
//     return 0;
// }

//재귀함수 사용
// #include <stdio.h>

// void printNumber(int count)
// {
//   if(count ==4)
//   return;

//   printf("%d\n", count);

//   printNumber(++count);
// }

// int main()
// {
//   int count = 1;

//   printNumber(count);

//   return 0;
// }

//재귀함수를 이용해 1부터 100까지의 합을 구하기.
// #include <stdio.h>

// int sum(int n)
// {
//     if (n==100)
//     return 100;

//     return n + sum(n+1);
// }

// int main()
// {
//     printf("%d\n", sum(1));

//     return 0;
// }

//재귀함수를 이용해 피보나치 구하기.
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// int fib(num1){
//     if (num1==0)
//     return 0;
//     if (num1 == 1)
//     return 1;
//     return fib(num1-1)+fib(num1-2);
// }

// int main()
// {
//     int num1;

//     scanf("%d", &num1);

//     printf("%d\n", fib(num1));

//     return 0;
// }

//입력된 값까지의 합
// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// int sum(int n)
// {
//     if (n == 1)
//         return 1;

//     return n + sum(n-1);
// }

// int main()
// {
//     int n = 0;

//     scanf("%d", &n);

//     printf("%d\n", sum(n));

//     return 0;
// }

#include <stdio.h>

int global = 10;

int globaltest(){
    global += 5;
    return 0;
}

int main(){
    int result = 10;

    printf("%d",global);
    printf("%d",result);
    globaltest();
    printf("%d",global);
    return 0;
}