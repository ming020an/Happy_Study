#include <stdio.h>
int main ()
{
int a = 1;
int sum = 0;
while (a<1)
{
  a++;
  sum=sum+1;
}
printf ("a=%d,sum=%d",a,sum);
return 0;
}