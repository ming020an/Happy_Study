#include <stdio.h>

int main(void)
{
	int a,b,c;
	printf("please input 3 num\n");
	scanf("%d%d%d",&a,&b,&c);
	/*
	if(a+b>c && a+c>b && b+c>a)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	*/
	if(a+b>c)
	{
		if(a+c>b)
		{
			if(a<b+c)
			{
				printf("yes\n");
				return 0; //return会结束函数的运行
			}
		}
	}

	printf("no\n");
	
	return 0;
}