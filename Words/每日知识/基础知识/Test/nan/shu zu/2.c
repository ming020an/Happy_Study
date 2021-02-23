#include <stdio.h>
int main()
{
    int a=0;
    int sum[100];
    for (a=0;a<100;a++)
    {
        sum[a]=a;

    }
    printf ("sum[%d]=%d\n",99,sum[99]);
    return 0;
}