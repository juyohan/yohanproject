#include <stdio.h>

int BSearch(int numb[], int len, int target);
int BSearchRe(int numb[], int first, int last, int target);

int main(){
    int number[10]; // 입력받을 배열 지정
    int num,avg,index,index1;
    int i = 0;

    printf("숫자 10개를 입력해주세요.(작은 수부터 차례로) : ");
    while ( i < 10){
        scanf("%d",&number[i]);
        i++;
    }

    printf("10개의 숫자들 중 무슨 숫자를 찾으시겠습니까? : ");
    scanf("%d",&num); // 찾을 숫자

    index = BSearch(number, sizeof(number)/sizeof(int), num);

    if (index == -1){
        index1 = BSearchRe(number,0,sizeof(number)/sizeof(int)-1 , num);

        if (index1 == -1){
            printf("숫자를 잘 못 입력하셨습니다. 프로그램을 종료합니다.\n");
        }
        else {
            printf("선택한 숫자의 위치 : %d\n",index1);
        }
    }

    else {
    printf("선택한 숫자의 위치 : %d\n",index);
    }
    
    return 0;
}

int BSearch(int numb[],int len, int target){ 
    // target을 찾기위한 반복문
    int first = 0;
    int last = len -1;
    int mid = 0;
    while (first <= last){ 
        // first의 값과 last의 값이 같아도 돌리는 이유는 마지막 1개가 남았을 때에도 실행시키기 위해
        mid = (first + last) / 2;
        if (numb[mid] == target){
            return mid;
        }
        else {
            if (numb[mid] > target)
            last = mid -1; 
            else
            first = mid + 1;
        }
    }
    return -1;
}

int BSearchRe(int numb[], int first, int last, int target){
    // target을 찾기위한 재귀함수
    int mid = (first + last) / 2;
    if (first > last)
    return -1;
    else {
        if (numb[mid] == target)
        return mid;
        else {
            if (numb[mid] > target){
                last = mid - 1;
                BSearchRe(numb, first, last, target);
            }
            else {
                first = mid + 1;
                BSearchRe(numb, first, last, target);
            }
        }
    }
}