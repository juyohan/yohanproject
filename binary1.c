#include <stdio.h>

int plus(int num); // 입력받은 양수를 2진법으로 변환
int minus(int num); // 입력받은 음수를 1의 보수로 변환
// int store(int i); // 1의 보수로 변환 뒤 1을 더해주는 과정
int print(int j); // 1의 보수에서 2의 보수로 변환해서 출력

int story[32];
int i;

int main () {
    int num;
    int j = 0;
    int l = 0;
    int k = 0;

    printf("2진수로 바꿀 숫자를 입력해주세요. : ");
    scanf("%d",&num); // 매개변수에 값 입력

    if (num>=0){ // 입력받은 숫자가 양수일때
    plus(num);
    printf("\n");
    }
    else if(num<0){ // 입력받은 숫자가 음수일떼
        num = -num; // 입력받은 음수를 양수로 변환
        minus(num); 
        j = i;
        k=i;
        // store(i);
        for (int l=i; l<=i; l++){
            if (story[l] == 0){
                story[l] = story[l] + 1;
                break;
            }
                else if (story[l] == 1){
                    story[l] = 0;
                }
        }
        print(j);
    }
    return 0;
}

int plus (int num){
    if (num==0)
        return 0;
       else{
           plus(num/2); // 2로 나누고 몫을 재귀함수로 호출
           printf("%d",num%2); // 2로 나누고 나머지를 출력
       }
       return 0;
}

int minus (int num){
if (num ==0)
return 0;
else {
        minus(num/2); // 2로 나누고 몫을 재귀함수로 호출
    story[i] = !(num%2); // 2로 나눈 나머지값을 1의 보수로 바꿔줌
    i++; // 저장소를 하나씩 증감
}
return 0;
} 

// int store(int i){
//     if (i == 0)
//     return 0;

//     else if (story[i] == 0){
//     story[i] = story[i] + 1;
//     // return 1;
//     }

 //     // else if (story[i] == 1)
 //     // story[i] = 0;

//     // printf("%d",story[i]);

//     return store(i-1);
// }

int print(int j){
    if (j==0)
    return 0;

    printf("%d",story[j]);

    return print(j-1);
}