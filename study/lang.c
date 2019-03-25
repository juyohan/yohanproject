#include <stdio.h>
#include <string.h>

int main() {
    char name[3][50];
    int n;

    n = sizeof(name)/sizeof(char[50]);
    printf("3명의 영어 이름을 차례로 입력해주세요. \n");

    for(int i = 1; i<=n; i++){
    printf("%d번째 이름 : ",i);
    fgets(name[i],sizeof(name[i]),stdin); // fgets로 입력받음
    // name[strlen(name)-1] = 0;
}
printf("\n 대소문자를 서로 변환시킵니다. \n");

for (int k =0 ; k<3; k++){
    for (int i = 0; i<n; i++){
        if (name[k][i]>='A' && name[k][i]<='Z')
        name[k][i] += 32; // 대문자 아스키코드 값에 32를 더해 소문자로 바꿔줌
        else if (name[k][i]>='a' && name[k][i]<='z')
        name[k][i] -= 32; // 소문자 아스키코드 값에 32를 빼서 대문자로 바꿔줌
        printf("%d번째 이름 : %s\n",k+1,name[k]);
    }
}
    return 0;
}