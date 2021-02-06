/*求最大公约数和最小公倍数*/
#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	int x=1,y=0;
	scanf("%d%d",&a,&b);
	c=a;
	d=b;
	do
	{
	if(a>b)
		a=a-b;
	else
		b=b-a;
	}
	while(a!=b);
	x=a;
	y=(c*d)/x;
	printf("最大公约数是%d\n",x);
	printf("最小公倍数是%d\n",y);
	return 0;
}