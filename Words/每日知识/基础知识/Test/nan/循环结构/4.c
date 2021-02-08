#include <stdio.h>
int main ()
{
    int a=3;
    int sum=0;
    do
    {
        a+1;
        sum=sum+1;
    }
    while (a<1);
    printf ("a=%d,sum=%d",a,sum);
    return 0;
}