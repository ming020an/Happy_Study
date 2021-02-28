//100000!末尾有几个零
#include <stdio.h>
int main ()
{
    int a=0;
    int b;
    int i;
    for (i=0;i<100000;i++)
    {
        if (i%10 == 0)
        {
            a++;
        
        }
        else
        {
            a+0;
        }
    }
    printf ("a=%d\n",a);
    return 0;
}