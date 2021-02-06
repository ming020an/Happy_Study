#include <stdio.h>

int main(void)
{
	//int a;
	char a;
	printf("please input a num form 1 to 7:\n");
	scanf("%c",&a); //scanf从键盘获取输入
	
	if(a == '1')
	{
		printf("星期一\n");
	}
	else if(a == '2')
	{
		printf("Tus\n");
	}
	else if(a == '3')
	{
		printf("Wed\n");
	}
	else if(a == '4')
	{
		printf("Thu\n");
	}
	else if(a == '5')
	{
		printf("Fri\n");
	}
	else if(a == '6')
	{
		printf("Sat\n");
	}
	else if(a == '7')
	{
		printf("Sun\n");
	}
	else
		printf("you input is error\n");
	
	return 0;
}