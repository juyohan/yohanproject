#include <stdio.h>

int main()
{
    int n=0,sum=0;

    while (1)
    {
      n = n + 2;

      if (n>100)
          break;

        sum = n + sum;

    }
    printf("%d\n",sum);
    return 0;
}
