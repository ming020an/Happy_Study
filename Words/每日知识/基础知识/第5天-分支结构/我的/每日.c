/*有一整数序列
 1,1,2,3, 5, 8, 13,21......
求出这个数列的前20项之和。*/
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