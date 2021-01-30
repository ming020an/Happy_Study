#include<stdio.h>
int main (void)
{
	int a,b,c;
	int sum;
	printf("请输入年月日！\n");
	scanf("%d%d%d",&a,&b,&c);
	if (b==1)
		sum = c;
	else if (b==2)
	{
		sum = 31+ c;
			if(a%400||a%4&&a%100)
			sum = 32 + c;
	}
	else if(b==3)
	{
	sum = 59+ c;
			if(a%400||a%4&&a%100)
			sum = 60 + c;
	}
	else if(b==4)
	{
	sum = 90+c;
		if(a%400||a%4&&a%100)
			sum = 91 + c;
	}
	else if(b==5)
	{
	sum = 120+c;
		if(a%400||a%4&&a%100)
			sum = 121 + c;
	}
	else if(b==6)
	{
	sum = 151+c;
		if(a%400||a%4&&a%100)
			sum = 152 + c;
	}
	else if(b==7)
	{
	sum = 181+c;
		if(a%400||a%4&&a%100)
			sum = 182 + c;
	}
	else if(b==8)
	{
	sum = 212+c;
		if(a%400||a%4&&a%100)
			sum = 213 + c;
	}
	else if(b==9)
	{
	sum = 243+c;
		if(a%400||a%4&&a%100)
			sum = 244 + c;
	}
	else if(b==10)
	{
	sum = 273+c;
		if(a%400||a%4&&a%100)
			sum = 274 + c;
	}
	else if(b==11)
	{
	sum =304+c;
		if(a%400||a%4&&a%100)
			sum = 305 + c;
	}
	else
	{
	sum = 334+c;
		if(a%400||a%4&&a%100)
			sum = 335 + c;
	}
	printf("它是这一年的第%d天\n",sum);
	return 0;
}
