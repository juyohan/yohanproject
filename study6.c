#include <stdio.h>
#include <string.h>

int main()
{
    char name[] = "korea nazarene university";
    int len,i;
    printf("%s : 25\n",name);

    len = strlen(name);
    for (i=len-1;i>=0;i--)
        printf("%c",name[i]);
    printf("\n");
    return 0;
}
