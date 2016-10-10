#include <stdio.h>

void Recursive(int nCount)
{
    if (nCount<=0)
    {
        printf("발사\n");
        return ;
    }
    else
    {
        printf("카운트 다운 : %d\n",nCount);
        Recursive(nCount-1);
    }
}

int main()
{
    Recursive(5);
    return 0;
}
