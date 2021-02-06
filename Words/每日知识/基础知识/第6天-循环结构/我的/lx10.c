/*判断一个数是不是质数*/
#include<stdio.h>
int main(void)
{
	int a,c;
	int i;
	scanf("%d",&a);
	if(a==1||a==2)
	{
		c=1;
	}
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
		c=0;	
		}
	}
	if(c==0)
	printf("该数不是素数！\n");
	else
	printf("该数是素数！\n");
	return 0;
}