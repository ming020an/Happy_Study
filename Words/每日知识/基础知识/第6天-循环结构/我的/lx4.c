#include<stdio.h>
int main(void)
{
	int a,b,c,d,i=0;
	scanf("%d",&a);
	b=a;
	while(a>=1)
	{
		a=a/10;
		i++;
	}
	printf("%d\n",i);// 计算几位数
	/*while(i>0)
	{
		for(j=0)
		c=
		d=b/(10);
		i--;
		printf("%d\n",c);
	}*/
	return 0;
}