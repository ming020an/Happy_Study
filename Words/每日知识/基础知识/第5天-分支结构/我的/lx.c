#include <stdio.h>
int main (void)
{
	int a,b;
	printf("请输入两个数！");
	scanf("%d%d",&a,&b);
	if(a-b>0)
	printf("a+b=%d\n",a+b);
	else
	printf("a*b=%d\n",a*b);

}