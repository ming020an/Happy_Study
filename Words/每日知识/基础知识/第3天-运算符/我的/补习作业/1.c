#include<stdio.h>
int main(void)
{
int a=0;
for(a=99;a<1000;a++)
{
int j,k,m;
	j = a/100;
	k = (a-100*j)/10;
	m = (a-100*j-10*k);
	if(j*j*j+k*k*k+m*m*m==a)
printf("%d %d %d\n",j,k,m);
}
return 0;
}