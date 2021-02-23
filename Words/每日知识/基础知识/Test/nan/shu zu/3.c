#include <stdio.h>
int main()
{
    int i=0;
    int a[6]={11,22,33,44,55,66};
    int sum=0,b;
    for(i=0;i<6;i++)
        {
            if (i==5)
            {
                continue;
            }
            if (i==0)
            {
                continue;
            }
            sum=sum+a[i];
        }  
    b=sum/4;
    printf ("sum=%d,b=%d",sum,b);
    return 0;
}