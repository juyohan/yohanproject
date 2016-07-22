#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int add(int n[], int count);

int main(void) {
  int i = 0, a;
  int sum, g[MAX];
  float avg;

  srand(time(NULL));
  printf("1부터 10사이의 양수 하나를 고르시오. : ");
  scanf("%d", &a);

  if (a < 0 || a > MAX) {
    printf("에러: 숫자는 0~10 까지만 허용됩니다.\n");
    return 1;
  }

  for (i = 0; i < a; i++)
    g[i] = rand() % 10;

  sum = add(g, a);
  avg = (float) sum / a;

  for (i = 0; i < a; i++) {
    printf("%d\n", g[i]);
  }

  printf("전체 합은 %d 입니다.\n", sum);
  printf("평균은 %.2lf 입니다.\n",avg);

  return 0;
}

int add(int n[], int count) {
  int i, result = 0;

  for (i = 0; i < count; i++) {
    result += n[i];
  }

  return result;
}
