#include <stdio.h>
int main ()
{
    int i;
    int a[10];
    for(i=0;i<10;i++)
    {
        printf("请输入第 % d个值：\n",i);
        scanf("%d",&a[i]);
    }
    for (i=0;i<10;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
    return 0;
}