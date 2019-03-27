#include <stdio.h>

int plus(int num); // 입력받은 양수를 2진법으로 변환
int minus(int num); // 입력받은 음수를 1의 보수로 변환
int print(int j); // 변환된 값을 출력

int story[32];
int i;

int main () {
    int num;
    int j = 0;
    int k = i; // 증감된 i의 값을 k값에 대입

    printf("2진수로 바꿀 숫자를 입력해주세요. : ");
    scanf("%d",&num); // 매개변수에 값 입력

    if (num>=0){ // 입력받은 숫자가 양수일때
    plus(num);
    printf("\n");
    }
    else if(num<0){ // 입력받은 숫자가 음수일떼
        num = -num; // 입력받은 음수를 양수로 변환
        minus(num); 

        int l=i; // i값을 불러옴
        for (int l=i; l>=0; l--){ 
            if (story[l] == 0){ // 자리가 0이면 1을 더해줌
                story[l] = story[l] + 1;
                break; // 반복문 탈출
            }
                else if (story[l] == 1){ // 자리가 1이면 0으로                             // 바꿔줌
                    story[l] = 0;
                }
        }
        if (story[k] == 0) // 15와 같이 1111의 음수인 -15와 같은                       // 수를 2진법으로 표현하기 위해 앞자리를                        // 추가하고 1로 바꿔줌
                story[k] = 1;
        print(j); // 재귀함수를 이용해 출력
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

int print(int j){
    if (j==i+1) // j의 값이 i+1이 되면 재귀함수 스탑
    return 0;

    printf("%d",story[j]); // story의 값들을 출력

    return print(j+1); // j의 값에 1을 더하고 다시 print재귀함수를                       // 불러옴
} 