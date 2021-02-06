#include<stdio.h>
int main(void)
{
	int n;
	int sum=1;
	printf("请输入一个数！\n");
	scanf("%d",&n);
	do
	{
		sum*=n;
		n--;
	}
	while (n>1);
	printf("n！=%d\n",sum);
	return 0;
}