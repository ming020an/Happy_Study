/*斐波拉切阶数*/
#include<stdio.h>
int main(void)
{
	int a=1,b=1,c,i;
	int sum=2;
	for(i=0;i<18;i++)
	{
		c=a+b;
		a=b;
		b=c;
		sum+=c;
	}
	printf("%d\n",sum);
	return 0;
}